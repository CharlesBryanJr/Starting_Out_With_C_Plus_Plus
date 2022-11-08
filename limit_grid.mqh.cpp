//+------------------------------------------------------------------+
//|                                                   limit_grid.mqh |
//|                                                             Mike |
//|                                                              yes |
//+------------------------------------------------------------------+
#property copyright "Mike"
#property link      "yes"
#property strict
#include <shapes.mqh>
#include <dashboard.mqh>
#include <stash.mqh>


//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
class Grid
  {
private:

   double            pip_value;

public:
   void              initialise(int _buy_or_sell,double _interval_pips, int _partial_close, double _sl_pips,double _risk_amount,bool _close_on_retracement,string _grid_name,int _magic_number,double _compound,color _line_colour);
   void              check(void);
   void              close(void);
   void              reopen(void);
   void              kill(void);


   string            grid_name;
   int               buy_or_sell;

   double            starting_price;
   double            upper_limit;
   double            lower_limit;

   int               magic_number;
   int               partial_close;
   double            risk_amount;
   double            sl_pips;
   double            compound;
   int               current_level;
   double            starting_lots;
   double            lots_closed;
   double            interval_pips;
   bool              close_on_retracement;
   color             line_colour;


  };

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void Grid::initialise(
   int _buy_or_sell,
   double _interval_pips,
   int _partial_close,
   double _sl_pips,
   double _risk_amount,
   bool _close_on_retracement,
   string _grid_name,
   int _magic_number,
   double _compound,
   color _line_colour
)
  {

   buy_or_sell=_buy_or_sell;
   sl_pips=_sl_pips;
   risk_amount=_risk_amount;
   partial_close=_partial_close;
   close_on_retracement=_close_on_retracement;
   grid_name=_grid_name;
   magic_number=_magic_number;
   compound=_compound;
   interval_pips=_interval_pips;
   pip_value=grab_pip_value();
   lots_closed=0;
   line_colour=_line_colour;

   starting_price=Ask;

   h_line(grid_name+" Open Price",clrRed,starting_price,"Open Price");
   if(buy_or_sell==0)
     {
      open_buy(1,risk_amount,1000,sl_pips,"pips",grid_name,magic_number);
      
      upper_limit = starting_price+(interval_pips*pip_value);
      lower_limit = starting_price-(1000*pip_value);
      
      h_line(grid_name+" Upper Limit",line_colour,upper_limit,"Upper Limit:"+upper_limit);

     }


   if(buy_or_sell==1)
     {
      open_sell(1,risk_amount,1000,sl_pips,"pips",grid_name,magic_number);
      upper_limit = starting_price+(1000*pip_value);
      lower_limit = starting_price-(interval_pips*pip_value);
      h_line(grid_name+" Lower Limit",line_colour,lower_limit,"Lower Limit:"+lower_limit);

     }

   add_log("Grid Initialised!");
   starting_lots=current_lots_open(magic_number);
   add_log("Current open lots: "+starting_lots);
   add_log("Currently at risk: "+n(currently_at_risk(magic_number),1));


  }

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void Grid::check(void)
  {
   if(buy_or_sell==0)
     {
      if(Ask>=upper_limit)
        {
         current_level ++;
         upper_limit=Ask+(interval_pips*pip_value);
         h_line(grid_name+" Upper Limit",line_colour,upper_limit,"Upper Limit: "+upper_limit);


         if(current_level>1)
           {
            lower_limit = Ask-(interval_pips*pip_value);
            h_line(grid_name+" Lower Limit",line_colour,lower_limit,"Lower Limit: "+lower_limit);
           }

         close();
        }

      if(Ask<=lower_limit)
        {
         current_level--;
         if(current_level>1)
           {
            lower_limit = Ask-(interval_pips*pip_value);
            h_line(grid_name+" Lower Limit",line_colour,lower_limit,"Lower Limit: "+lower_limit);
           }

         else
           {
            lower_limit=0;
            h_line(grid_name+" Lower Limit",line_colour,lower_limit,"Lower Limit: "+lower_limit);
           }

         if(close_on_retracement==false)
           {
            lower_limit=0;
            h_line(grid_name+" Lower Limit",line_colour,lower_limit,"Lower Limit: "+lower_limit);
           }

         upper_limit = Ask+(interval_pips*pip_value);
         h_line(grid_name+" Upper Limit",line_colour,upper_limit,"Upper Limit: "+upper_limit);

         if(close_on_retracement==true)
           {

            close();
           }


        }

      if(Ask<=starting_price)
        {
         current_level=0;
         upper_limit = starting_price+(interval_pips*pip_value);
         h_line(grid_name+" Upper Limit",line_colour,upper_limit,"Upper Limit: "+upper_limit);

         if(lots_closed>0)
            reopen();


        }

     }

   if(buy_or_sell==1)
     {


      if(Ask<=lower_limit)
        {
         current_level ++;
         lower_limit=Ask-(interval_pips*pip_value);
         h_line(grid_name+" Lower Limit",line_colour,lower_limit,"Lower Limit: "+lower_limit);


         if(current_level>1)
           {
            upper_limit = Ask+(interval_pips*pip_value);
            h_line(grid_name+" Upper Limit",line_colour,upper_limit,"Upper Limit: "+upper_limit);
           }

         close();




        }

      if(Ask>=upper_limit)
        {
         current_level--;
         if(current_level>1)
           {
            upper_limit = Ask+(interval_pips*pip_value);
            h_line(grid_name+" Upper Limit",line_colour,upper_limit,"Upper Limit: "+upper_limit);

           }

         else
           {
            upper_limit=1000;
            h_line(grid_name+" Upper Limit",line_colour,upper_limit,"Upper Limit: "+upper_limit);
           }

         if(close_on_retracement==false)
           {
            upper_limit=999999;
            h_line(grid_name+" Upper Limit",line_colour,upper_limit,"Upper Limit: "+upper_limit);
           }

         lower_limit = Ask-(interval_pips*pip_value);
         h_line(grid_name+" Lower Limit",line_colour,lower_limit,"Lower Limit: "+lower_limit);

         if(close_on_retracement==True)
            close();

        }

      if(Ask>=starting_price)
        {
         current_level=0;
         lower_limit = starting_price-(interval_pips*pip_value);
         h_line(grid_name+" Lower Limit",line_colour,lower_limit,"Lower Limit: "+lower_limit);

         if(lots_closed>0)
            reopen();


        }

     }


  }

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void Grid::reopen(void)
  {
   add_log("Reopening Trades!");
   double ea_closed_profit = n(current_ea_closed_profit(magic_number),1);
   add_log("Closed Lots: "+n(lots_closed,2));
   add_log("Closed Cash: "+ea_closed_profit+AccountCurrency());
   add_log("Compounding "+n(ea_closed_profit*compound,1)+AccountCurrency()+" back into grid");
   double to_risk = (risk_amount-currently_at_risk(magic_number))+(ea_closed_profit*compound);
   if(buy_or_sell==0)
     {
      open_buy(1,to_risk,1000,sl_pips,"pips","Grid!",magic_number);
     }

   if(buy_or_sell==1)
     {
      open_sell(1,to_risk,1000,sl_pips,"pips","Grid!",magic_number);
     }

   lots_closed=0;
   add_log("Currently at risk: "+n(currently_at_risk(magic_number),1));
   starting_lots=current_lots_open(magic_number);

  }



void Grid::close(void)

  {
   double lotsize_to_close = (starting_lots/partial_close);
   if(lotsize_to_close<0.01)
     {
      add_log("Lotsize too small!");
      lotsize_to_close=0.01;
     }
   double current_closed_lots = 0;

   for(int i; i<OrdersTotal(); i++)
     {
      double lotsize_to_close = (starting_lots/partial_close)-current_closed_lots;
      if(lotsize_to_close<0.01)
        {
         add_log("Lotsize too small!");
         lotsize_to_close=0.01;
        }


      OrderSelect(i,SELECT_BY_POS);
      if(OrderMagicNumber()==magic_number)
        {
         if(OrderSymbol()==Symbol())
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
               //total_lots_closed+=lotsize_to_close;
              }

            else
               translate_error(GetLastError());

            if(current_closed_lots>=lotsize_to_close)
              {
               break;
              }
           }
        }
     }
  }

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void Grid::kill(void)
  {
   close_all_trades_by_magic_number(magic_number);

  }
//+------------------------------------------------------------------+


Grid grid_array[];


void new_grid(
   int _buy_or_sell,
   double _interval_pips,
   int _magic_number,
   int _partial_close,
   double _stop_loss,
   double _risk_amount,
   double _compound,
   string _name,
   bool _close_on_retracement,
   color _line_colour
)
  {
  

   Grid grid;
   grid.initialise(
   _buy_or_sell,
   _interval_pips,
   _partial_close,
   _stop_loss,
   _risk_amount,
   _close_on_retracement,
   _name,
   _magic_number,
   _compound,
   _line_colour
   );

   int current_array_size = ArraySize(grid_array);
   int new_array_size = current_array_size+1;
   
   ArrayResize(grid_array,new_array_size);
   
   grid_array[ArraySize(grid_array)-1] = grid ;

//grids = [0]grid_1,grid_2,grid_3,grid_4]
  }
  
  
void check_grids()
  {
   for(int i; i<ArraySize(grid_array); i++)
     {

      grid_array[i].check();
     }

  }