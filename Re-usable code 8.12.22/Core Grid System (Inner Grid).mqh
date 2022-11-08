//+------------------------------------------------------------------+
//|                                                    core_grid.mqh |
//|                        Copyright 2021, MetaQuotes Software Corp. |
//|                                             https://www.mql5.com |
//+------------------------------------------------------------------+
#property copyright "Copyright 2021, MetaQuotes Software Corp."
#property link      "https://www.mql5.com"
#property strict
#include <stash.mqh>

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
class CoreGrid
  {

public:
   void              initialise(
      string _asset,
      int _buy_or_sell,
      int _partial_close,
      double _target_intervals,
      double _sl_pips,
      double _risk_percentage,
      string _name,
      int _magic_number,
      bool _reopen_on_starting_price,
      double _compound_profit_percentage
   );
   void              check();
   void              launch();
   double            starting_lots;
   void              close();
   void              reopen();

   int               current_level;
   int               partial_close;

   double            grid_pip_value;
   double            upper_limit;
   double            lower_limit;
   double            starting_price;
   string            asset;
   int               buy_or_sell;
   double            interval_targets;
   double            sl_pips;
   double            risk_percentage;
   string            name;
   int               magic_number;
   bool              reopen_on_starting_price;
   double            lots_closed;
   double            compound_profit_percentage;
   double            amount_to_risk;

  };

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void CoreGrid::initialise(
   string _asset,
   int _buy_or_sell,
   int _partial_close,
   double _target_intervals,
   double _sl_pips,
   double _risk_percentage,
   string _name,
   int _magic_number,
   bool _reopen_on_starting_price,
   double _compound_profit_percentage
)
  {
   asset=_asset;
   buy_or_sell = _buy_or_sell;
   interval_targets = _target_intervals;
   sl_pips = _sl_pips;
   risk_percentage = _risk_percentage;
   name = _name;
   magic_number=_magic_number;
   grid_pip_value=grab_pip_value(asset);
   partial_close = _partial_close;
   reopen_on_starting_price =_reopen_on_starting_price;
   compound_profit_percentage = _compound_profit_percentage;
  }


//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void CoreGrid::launch()
  {
   amount_to_risk = (AccountBalance()/100)*risk_percentage;
   starting_price=Ask;
   h_line(name+" Open Price ",clrGreen,starting_price,"Starting Price");
   double lotsize_to_use = calculate_lotsize_by_percent(risk_percentage,sl_pips,asset);

   if(buy_or_sell==OP_BUY)
     {
      OrderSend(asset,OP_BUY,lotsize_to_use,Ask,30,Ask-(sl_pips*grid_pip_value),Ask+(1000*grid_pip_value),name,magic_number);
      upper_limit = starting_price+(interval_targets*grid_pip_value);
      lower_limit = 0;
      h_line(name+" Upper Limit",clrOrange,upper_limit,"Upper Limit: "+upper_limit);
     }

   if(buy_or_sell==OP_SELL)
     {

      OrderSend(asset,OP_SELL,lotsize_to_use,Bid,30,Bid+(sl_pips*grid_pip_value),Bid-(1000*grid_pip_value),name,magic_number);
      upper_limit = 10000;
      lower_limit = starting_price-(interval_targets*grid_pip_value);
      h_line(name+" Lower Limit",clrOrange,lower_limit,"Lower Limit: "+lower_limit);
     }

   add_log("CoreGrid "+name+" "+asset+" Launched");
   starting_lots = open_lots(magic_number);
   add_log("Currently Open Lots: "+starting_lots);
   add_log("Currently At Risk: "+currently_at_risk(magic_number));
   lots_closed=0;

  }



//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void CoreGrid::check()
  {
   if(buy_or_sell==OP_BUY)
     {
      if(Ask>=upper_limit)
        {
         current_level ++;
         upper_limit=Ask+(interval_targets*grid_pip_value);
         h_line(name+" Upper Limit",clrOrange,upper_limit,"Upper Limit: "+upper_limit);

         if(current_level>1)
           {
            lower_limit = Ask-(interval_targets*grid_pip_value);
            h_line(name+" Lower Limit",clrOrange,lower_limit,"Lower Limit: "+lower_limit);

           }

         close();

        }

      if(Ask<=lower_limit)
        {
         current_level --;
         if(current_level>1)
           {
            lower_limit = Ask-(interval_targets*grid_pip_value);
            h_line(name+" Lower Limit",clrOrange,lower_limit,"Lower Limit: "+lower_limit);
           }
         else
           {
            lower_limit=0;
            delete_line(name+ " Lower Limit");

           }

         upper_limit=Ask+(interval_targets*grid_pip_value);
         h_line(name+" Upper Limit",clrOrange,upper_limit,"Upper Limit: "+upper_limit);

         close();
        }

      if(Ask<=starting_price)
        {
         current_level=0;
         upper_limit = starting_price+(interval_targets*grid_pip_value);
         h_line(name+" Upper Limit",clrOrange,upper_limit,"Upper Limit: "+upper_limit);
         if(lots_closed>0 && reopen_on_starting_price==True)
         {

            reopen();
}
        }

     }


   if(buy_or_sell==OP_SELL)
     {
      if(Bid<=lower_limit)
        {
         current_level ++;
         lower_limit=Bid-(interval_targets*grid_pip_value);
         h_line(name+" Lower Limit",clrOrange,lower_limit,"Lower Limit: "+lower_limit);

         if(current_level>1)
           {
            upper_limit= Bid+(interval_targets*grid_pip_value);
            h_line(name+" Upper Limit",clrOrange,upper_limit,"Upper Limit: "+upper_limit);

           }

         close();

        }

      if(Bid>=upper_limit)
        {
         current_level --;
         if(current_level>1)
           {
            upper_limit= Bid+(interval_targets*grid_pip_value);
            h_line(name+" Upper Limit",clrOrange,upper_limit,"Upper Limit: "+upper_limit);
           }
         else
           {
            upper_limit=10000;
            delete_line(name+ " Upper Limit");

           }

         lower_limit=Bid-(interval_targets*grid_pip_value);
         h_line(name+" Lower Limit",clrOrange,lower_limit,"Lower Limit: "+lower_limit);

         close();
        }

      if(Bid>=starting_price)
        {
         current_level=0;
         lower_limit = starting_price-(interval_targets*grid_pip_value);
         h_line(name+" Lower Limit",clrOrange,lower_limit,"Lower Limit: "+lower_limit);
         if(lots_closed>0 && reopen_on_starting_price==True)
           {
            reopen();
           }
        }

     }

  }


//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void CoreGrid::reopen()
  {
   add_log("Reopening Trades!");
   double ea_closed_profit = n(current_ea_closed_profit(magic_number),1);
   add_log("Lots Closed: "+n(lots_closed,1));
   add_log("Closed Cash: "+ea_closed_profit+AccountCurrency());
   add_log("Compounding "+n(ea_closed_profit*compound_profit_percentage,1)+AccountCurrency()+" back into the grid");
   double to_risk = (amount_to_risk-currently_at_risk(magic_number))+(ea_closed_profit*compound_profit_percentage);
  
   if(buy_or_sell==OP_BUY)
     {
      OrderSend(asset,OP_BUY,calculate_lotsize_by_currency_amount(to_risk,sl_pips,asset),Ask,30,Ask-(sl_pips*grid_pip_value),Ask+(1000*grid_pip_value),name,magic_number);
     }

   if(buy_or_sell==OP_SELL)
     {
      OrderSend(asset,OP_SELL,calculate_lotsize_by_currency_amount(to_risk,sl_pips,asset),Bid,30,Bid+(sl_pips*grid_pip_value),Ask-(1000*grid_pip_value),name,magic_number);
     }

   lots_closed=0;
   add_log("Currently at risk: "+n(currently_at_risk(magic_number),1));
   starting_lots=open_lots(magic_number);


  }

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void CoreGrid::close()
  {

   double lotsize_to_close = (starting_lots/partial_close);

   double current_closed_lots;

   for(int i; i<OrdersTotal(); i++)
     {
      double lotsize_to_close=(starting_lots/partial_close)-current;
      if(lotsize_to_close<0.01)
        {
         add_log("Lotsize too small!");
         lotsize_to_close=0.01;
        }
      OrderSelect(i,SELECT_BY_POS);
      if(OrderMagicNumber()==magic_number)
        {
         int ticket = OrderTicket();
         double available_lots = OrderLots();
         if(lotsize_to_close>available_lots)
            lotsize_to_close=OrderLots();
         if(OrderClose(ticket,lotsize_to_close,OrderClosePrice(),30))
           {
            OrderSelect(ticket,SELECT_BY_TICKET,MODE_HISTORY);
            add_log("Closed "+n(lotsize_to_close,1)+" lots ("+OrderProfit()+AccountCurrency()+")");
            current_closed_lots+=lotsize_to_close;
            lots_closed+=lotsize_to_close;


           }
         if(current_closed_lots>=lotsize_to_close)
            break;

        }
     }


  }
















CoreGrid grid_array[];

//+------------------------------------------------------------------+
//|            Create a new CoreGrid                                 |
//+------------------------------------------------------------------+
void new_grid(
   string _asset,
   int _buy_or_sell,
   int _partial_close,
   double _target_intervals,
   double _sl_pips,
   double _risk_percentage,
   string _name,
   int _magic_number,
   bool _reopen_on_starting_price,
   double _compound_profit_percentage

)
  {
   CoreGrid grid;
   grid.initialise(
      _asset,
      _buy_or_sell,
      _partial_close,
      _target_intervals,
      _sl_pips,
      _risk_percentage,
      _name,
      _magic_number,
      _reopen_on_starting_price,
      _compound_profit_percentage
   );
   grid.launch();
   int grid_array_size = ArraySize(grid_array);
   int new_grid_array_size = grid_array_size+1;
   ArrayResize(grid_array,new_grid_array_size);
   grid_array[ArraySize(grid_array)-1] = grid;

  }


//+------------------------------------------------------------------+
//|      Loop throuh [Grid 1, Grid 2, Grid 3, Grid 4]                |
//+------------------------------------------------------------------+
void check_grids()
  {
   for(int i; i<ArraySize(grid_array); i++)
     {
      grid_array[i].check();
     }

  }
//+------------------------------------------------------------------+

//+------------------------------------------------------------------+