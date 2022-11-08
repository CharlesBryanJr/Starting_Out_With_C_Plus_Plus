//+------------------------------------------------------------------+
//|                                                   my_library.mqh |
//|                                                             Mike |
//|                                                              yes |
//+------------------------------------------------------------------+
#property copyright "Mike"
#property link      "yes"
#property strict

#include <dashboard.mqh>


int line_number=1;
double pip_value;
int current_closed_orders;
int current_open_orders;
int low_counter=1;
int high_counter=1;
bool debug;

enum timeframes
  {
   current=0,
   m1=1,
   m5=5,
   m15=15,
   m30=30,
   h1=60,
   h4=240,
   d1=1440,
   w1=10080,
   mn1=43200
  };

enum order_types
  {
   buy=OP_BUY,
   sell=OP_SELL,
   buy_stop=OP_BUYSTOP,
   buy_limit=OP_BUYLIMIT,
   sell_stop=OP_SELLSTOP,
   sell_limit=OP_SELLSTOP

  };
enum market_orders
{
buying=OP_BUY,
selling=OP_SELL
};
//+------------------------------------------------------------------+
//|                INITIALISE THE PIP VALUE                          |
//+------------------------------------------------------------------+
double grab_pip_value(string symbol="")
  {
   if(symbol=="")
     {
      symbol=Symbol();
     }
   double digits=MarketInfo(symbol,MODE_DIGITS);
   if(digits==2 || digits==3)
      return 0.01;
   else
      if(digits==4 || digits==5)
         return 0.0001;
   return 1;

  }

//+------------------------------------------------------------------+
//|                 RETURNS THE PROFIT IN PIPS OF THE TICKET         |
//+------------------------------------------------------------------+
double profit_in_pips(int ticket)
  {
   if(!OrderSelect(ticket,SELECT_BY_TICKET))
      return -1;
   if(OrderType()==OP_BUY)
      return (OrderClosePrice()-OrderOpenPrice())/pip_value;
   if(OrderType()==OP_SELL)
      return (OrderOpenPrice()-OrderClosePrice())/pip_value;
   return 0;
  }

//+------------------------------------------------------------------+
//|                 RETURNS THE PROFIT IN CASH OF THE TICKET         |
//+------------------------------------------------------------------+
double profit_in_cash(int ticket)
  {
   if(!OrderSelect(ticket,SELECT_BY_TICKET))
      return -1;
   return OrderProfit();

  }


//+------------------------------------------------------------------+
//|RETURNS LOTSIZE YOU SHOULD USE FOR sl_pips TO EQUAL x GBP/USD/EUR |
//+------------------------------------------------------------------+
double calculate_lotsize_by_currency_amount(double risk_amount, double sl_pip_distance,string symbol="")
  {
   if(symbol=="")
      symbol=Symbol();
   double t_size = MarketInfo(symbol,MODE_TICKVALUE);
   return ((risk_amount/sl_pip_distance)/t_size)/10;
  }



//+------------------------------------------------------------------+
// RETURNS THE LOTSIZE YOU SHOULD USE FOR sl_pips TO EQUAL % OF ACC. |
//+------------------------------------------------------------------+
double calculate_lotsize_by_percent(double percent_to_risk,double sl_pip_distance)
  {
   double account_percent = AccountEquity()/100;
   double amount_we_are_risking = account_percent * percent_to_risk;
   return calculate_lotsize_by_currency_amount(amount_we_are_risking,sl_pip_distance);
  }

//+------------------------------------------------------------------+
//|  PROFIT/LOSS FROM A DISTANCE IN PIPS BASED ON LOTSIZE            |
//+------------------------------------------------------------------+
double calculate_profit_by_distance(double lotsize, double pip_distance)
  {
   double t_size = MarketInfo(Symbol(),MODE_TICKVALUE);
   return ((t_size*lotsize)*pip_distance)*10;
  }




//+------------------------------------------------------------------+
//|  HOW MUCH IS MONEY CURRENTLY AT RISK BASED ON A MAGIC NUMBER     |
//+------------------------------------------------------------------+
double currently_at_risk(int magic_number=0)
  {
   double return_amount;
   double sl_distance;
   for(int i; i<OrdersTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS);
      if(OrderMagicNumber()==magic_number ||magic_number==0)
        {
         if(OrderStopLoss()==0)
            return 9999;
         double stoploss_distance=0;
         if(OrderType()==OP_BUY)
           {
            sl_distance=(OrderOpenPrice()-OrderStopLoss())/pip_value;
           }
         if(OrderType()==OP_SELL)
           {
            sl_distance=(OrderStopLoss()-OrderOpenPrice())/pip_value;
           }
         return_amount+=calculate_profit_by_distance(OrderLots(),sl_distance);

        }

     }
   return return_amount;


  }
//+------------------------------------------------------------------+
//|  HOW MANY PIPS ARE  AT RISK BASED ON A MAGIC NUMBER                |
//+--------------------------------------------------------------------+
double pips_at_risk(int magic_number=0)
  {
   double return_amount;
   double sl_distance;
   for(int i; i<OrdersTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS);
      if(OrderMagicNumber()==magic_number || magic_number==0)
        {
         if(OrderStopLoss()==0)
            return 9999;
         double stoploss_distance=0;
         if(OrderType()==OP_BUY)
           {
            sl_distance=(OrderOpenPrice()-OrderStopLoss())/pip_value;
           }
         if(OrderType()==OP_SELL)
           {
            sl_distance=(OrderStopLoss()-OrderOpenPrice())/pip_value;
           }
         return_amount+=sl_distance;

        }

     }
   return return_amount;
  }


//+------------------------------------------------------------------+
//|  HOW MANY LOTS ARE OPEN BASED ON A MAGIC NUMBER                  |
//+------------------------------------------------------------------+
double open_lots(int magic_number=0)
  {
   double lots;
   for(int i; i<OrdersTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS);
      if(OrderMagicNumber()==magic_number)
        {

         lots+=OrderLots();

        }

     }

   return n(lots,2);
  }



//+------------------------------------------------------------------+
//|  HOW MANY LOTS HAVE BEEN CLOSED BASED ON A MAGIC NUMBER          |
//+------------------------------------------------------------------+
double closed_lots(int magic_number=0)
  {
   double lots;
   for(int i; i<OrdersHistoryTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_HISTORY);
      if(OrderMagicNumber()==magic_number)
        {

         lots+=OrderLots();

        }

     }

   return n(lots,2);
  }


//+------------------------------------------------------------------+
//|  HOW MUCH PROFIT HAS THE EA MADE BASED ON MAGIC NUMBER           |
//+------------------------------------------------------------------+
double current_ea_closed_profit(int magic_number=0)
  {

   double profit;
   for(int i; i<OrdersHistoryTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_HISTORY);
      if(OrderMagicNumber()==magic_number)
        {

         profit+=OrderProfit();

        }

     }

   return n(profit,1);
  }

//+------------------------------------------------------------------+
//|  HOW MUCH OPEN PROFIT THE EA CURRENTLY HAS ON MAGIC NUMBER       |
//+------------------------------------------------------------------+
double current_ea_open_profit(int magic_number=0)
  {
   double profit;
   for(int i; i<OrdersTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS);
      if(OrderMagicNumber()==magic_number)
        {
         profit+=OrderProfit();
        }
     }
   return n(profit,2);
  }


//+------------------------------------------------------------------+
//|  CLOSE ALL TRADES BASED ON A MAGIC NUMBER                        |
//+------------------------------------------------------------------+
void close_all_trades_by_magic_number(int magic_number)
  {


   for(int i=(OrdersTotal()-1); i>=0; i--)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_TRADES);
      if(OrderMagicNumber()==magic_number)
        {
         OrderClose(OrderTicket(),OrderLots(),OrderClosePrice(),30);
        }
     }
  }


//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void close_all_trades()
  {


   for(int i=(OrdersTotal()-1); i>=0; i--)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_TRADES);
      if(!OrderClose(OrderTicket(),OrderLots(),OrderClosePrice(),30))
         add_log("Order Close Error "+GetLastError());;

     }
  }


//+------------------------------------------------------------------+
//|  CLOSE ALL TRADES BY SYMBOL                                      |
//+------------------------------------------------------------------+
void close_all_trades_by_symbol(int symbol)
  {
   for(int i; i<OrdersTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_TRADES);
      if(OrderSymbol()==symbol)
        {
         OrderClose(OrderTicket(),OrderLots(),OrderClosePrice(),30);
        }
     }
  }

//+------------------------------------------------------------------+
//|  MOVE STOP TO BREAK EVEN                                           |
//+------------------------------------------------------------------+
void move_stop_to_break_even(int ticket)
  {
   OrderSelect(ticket,SELECT_BY_TICKET);
   OrderModify(ticket,Ask,OrderOpenPrice(),OrderTakeProfit(),NULL);
  }

//+------------------------------------------------------------------+
//|  CLOSE ALL WINNING TRADES BY MAGIC NUMBER                        |
//+------------------------------------------------------------------+
void close_all_winning_trades_by_magic_number(int magic_number=0)
  {
   for(int i; i<OrdersTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_TRADES);
      if(OrderMagicNumber()==magic_number ||magic_number==0)
         if(OrderProfit()>0)
           {
            OrderClose(OrderTicket(),OrderLots(),OrderClosePrice(),30);
           }
     }
  }

//+------------------------------------------------------------------+
//|  CLOSE ALL LOSING TRADES BY MAGIC NUMBER                         |
//+------------------------------------------------------------------+
void close_all_losing_trades_by_magic_number(int magic_number=0)
  {
   for(int i; i<OrdersTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_TRADES);
      if(OrderMagicNumber()==magic_number||magic_number==0)
         if(OrderProfit()<0)
           {
            OrderClose(OrderTicket(),OrderLots(),OrderClosePrice(),30);
           }
     }
  }

//+------------------------------------------------------------------+
//|          RETURN TRUE ON OPEN OF NEW CANDLE                       |
//+------------------------------------------------------------------+
bool new_candle()
  {
   static datetime time=0;
   if(time==0)
     {
      time=Time[0];
      return false;
     }
   if(time!=Time[0])
     {
      time=Time[0];
      return true;
     }
   return false;
  }

//+------------------------------------------------------------------+
//| RETURN TRUE IF A TRADE WAS CLOSED SINCE LAST TIME WE CHECKED     |
//+------------------------------------------------------------------+
bool a_trade_has_closed()
  {
   if(current_closed_orders<OrdersHistoryTotal())
     {
      current_closed_orders=OrdersHistoryTotal();
      return true;
     }
   return false;
  }


//+------------------------------------------------------------------+
//| RETURN TRUE IF A TRADE WAS OPENED SINCE LAST TIME WE CHECKED     |
//+------------------------------------------------------------------+
bool a_trade_has_opened()
  {
   if(current_open_orders<OrdersTotal())
     {
      current_open_orders=OrdersTotal();
      return true;
     }
   return false;
  }

//+------------------------------------------------------------------+
//| RETURN TRUE IF THE CANDLE (x) CANDLES AGO WAS BULLISH            |
//+------------------------------------------------------------------+
bool is_candle_bullish(int timeframe,int how_many_candles_back)
  {
   double candle_open = iOpen(Symbol(),timeframe,how_many_candles_back);
   double candle_close = iClose(Symbol(),timeframe,how_many_candles_back);
   if(candle_open<candle_close)
     {
      return true;
     };
   return false;

  }

//+------------------------------------------------------------------+
//| RETURN TRUE IF THE CANDLE (x) CANDLES AGO WAS BEARISH            |
//+------------------------------------------------------------------+
bool is_candle_bearish(int timeframe,int how_many_candles_back)
  {
   double candle_open = iOpen(Symbol(),timeframe,how_many_candles_back);
   double candle_close = iClose(Symbol(),timeframe,how_many_candles_back);
   if(candle_open>candle_close)
     {
      return true;
     }
   return false;

  }

//+--------------------------------------------------------------------+
//| RETURN THE NUMBER OF OPEN BUYS WITH THE MATCHING MAGIC NUMBER      |
//+--------------------------------------------------------------------+
int number_of_buys(int magic_number=0)
  {

   int number;
   for(int i; i<OrdersTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_TRADES);
      if(OrderMagicNumber()==magic_number || OrderMagicNumber()==0)
         if(OrderType() == OP_BUY)
           {
            number++;
           }
     }
   return number;
  }


//+--------------------------------------------------------------------+
//| RETURN THE NUMBER OF OPEN SELLS WITH THE MATCHING MAGIC NUMBER     |
//+--------------------------------------------------------------------+
int number_of_sells(int magic_number=0)
  {

   int number;
   for(int i; i<OrdersTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_TRADES);
      if(OrderMagicNumber()==magic_number || OrderMagicNumber()==0)

         if(OrderType() == OP_SELL)
           {
            number++;
           }
     }
   return number;
  }


//+--------------------------------------------------------------------+
//| RETURN THE NUMBER OF OPEN TRADES WITH THE MATCHING MAGIC NUMBER    |
//+--------------------------------------------------------------------+
int number_of_open_trades(int magic_number=0)
  {

   int number;
   for(int i; i<OrdersTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_TRADES);
      if(OrderMagicNumber()==magic_number || OrderMagicNumber()==0)
         number++;

     }
   return number;
  }
  
//+--------------------------------------------------------------------+
//| RETURN THE NUMBER OF CLOSED TRADES WITH THE MATCHING MAGIC NUMBER    |
//+--------------------------------------------------------------------+
int number_of_closed_trades(int magic_number=0)
  {

   int number;
   for(int i; i<OrdersHistoryTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_HISTORY);
      if(OrderMagicNumber()==magic_number)
         number++;

     }
   return number;
  }



//+------------------------------------------------------------------+
//|            OPEN A BUY                                            |
//+------------------------------------------------------------------+
int open_buy(
   int risk_setting,
   double risk_variable,
   double tp,
   double sl,
   string pips_or_price="pips",
   string comment="",
   int magic_number=0
)
// Risk setting 1 = Amount in CCY
// Risk setting 2 = Percent
// Risk setting 3 = Volume
  {

   double sl_pip_distance =sl;
   double tp_pip_distance = tp;

   if(pips_or_price=="price")
     {

      sl_pip_distance=(Bid-sl)/pip_value;
      tp_pip_distance=(tp-Bid)/pip_value;
     }

   double lotsize_to_use;

   if(risk_setting==1)
     {
      lotsize_to_use = calculate_lotsize_by_currency_amount(risk_variable,sl_pip_distance);
      add_log("Risk: "+risk_variable+AccountCurrency()+" ("+lotsize_to_use+")");
     }

   if(risk_setting==2)
     {
      lotsize_to_use = calculate_lotsize_by_percent(risk_variable,sl_pip_distance);
      add_log("Risk: "+risk_variable+"% ("+lotsize_to_use+")");

     }

   if(risk_setting==3)
     {
      lotsize_to_use=risk_variable;
      add_log("Risk: "+lotsize_to_use+" lots ("+calculate_profit_by_distance(lotsize_to_use,sl_pip_distance)+")");

     }

   if(lotsize_to_use <0.01)
     {
      lotsize_to_use=0.01;
      add_log("Lotsize too small, changed to 0.01");

     }

   int trade_ticket = OrderSend(Symbol(),OP_BUY,lotsize_to_use,Bid,30,0,0,comment,magic_number);
   if(trade_ticket==-1)
     {
      translate_error(GetLastError());
      return -1;
     }

   double sl_price = sl;
   double tp_price = tp;

   if(pips_or_price=="pips")
     {
      OrderSelect(trade_ticket,SELECT_BY_TICKET);
      sl_price = OrderOpenPrice()-(sl_pip_distance*pip_value);
      tp_price = OrderOpenPrice()+(tp_pip_distance*pip_value);
     }

   int error;
   while(error <10)
     {
      add_log("Modifying ticket "+trade_ticket);
      if(OrderModify(trade_ticket,OrderOpenPrice(),sl_price,tp_price,NULL))
        {
         break;
        };
      add_log(translate_error(GetLastError()));
      error++;

     }

   if(error==10)
     {
      add_log("Order modify failed too many times");
      OrderClose(trade_ticket,OrderLots(),OrderClosePrice(),30);
      return -1;
     }

   add_log("Order Modify Success!");
//  add_log("TP: "+calculate_profit_by_distance(lotsize_to_use,tp_pip_distance)+AccountCurrency());
//   add_log("SL: "+calculate_profit_by_distance(lotsize_to_use,sl_pip_distance)+AccountCurrency());
   return trade_ticket;


  }

//+------------------------------------------------------------------+
//|              OPEN A SELL                                         |
//+------------------------------------------------------------------+
int open_sell(
   int risk_setting,
   double risk_variable,
   double tp,
   double sl,
   string pips_or_price="pips",
   string comment="",
   int magic_number=0
)

// Risk setting 1 = Amount in CCY
// Risk setting 2 = Percent
// Risk setting 3 = Volume
  {

   double sl_pip_distance =sl;
   double tp_pip_distance = tp;

   if(pips_or_price=="price")
     {

      sl_pip_distance=(sl-Ask)/pip_value;
      tp_pip_distance=(Ask-tp)/pip_value;
     }

   double lotsize_to_use;

   if(risk_setting==1)
     {
      lotsize_to_use = calculate_lotsize_by_currency_amount(risk_variable,sl_pip_distance);
      //    add_log("Risk: "+risk_variable+AccountCurrency()+" ("+lotsize_to_use+")");
     }

   if(risk_setting==2)
     {
      lotsize_to_use = calculate_lotsize_by_percent(risk_variable,sl_pip_distance);
      //   add_log("Risk: "+risk_variable+"% ("+lotsize_to_use+")");

     }

   if(risk_setting==3)
     {
      lotsize_to_use=risk_variable;
      //    add_log("Risk: "+lotsize_to_use+" lots ("+calculate_profit_by_distance(lotsize_to_use,sl_pip_distance)+")");

     }

   if(lotsize_to_use <0.01)
     {
      lotsize_to_use=0.01;
      //   add_log("Lotsize too small, changed to 0.01");

     }

   int trade_ticket = OrderSend(Symbol(),OP_SELL,lotsize_to_use,Ask,30,0,0,comment,magic_number);
   if(trade_ticket==-1)
     {
      translate_error(GetLastError());
      return -1;
     }

   double sl_price = sl;
   double tp_price = tp;

   if(pips_or_price=="pips")
     {
      OrderSelect(trade_ticket,SELECT_BY_TICKET);
      sl_price = OrderOpenPrice()+(sl_pip_distance*pip_value);
      tp_price = OrderOpenPrice()-(tp_pip_distance*pip_value);
     }

   int error;
   while(error <10)
     {
      //    add_log("Modifying ticket "+trade_ticket);
      if(OrderModify(trade_ticket,OrderOpenPrice(),sl_price,tp_price,NULL))
        {
         break;
        };
      add_log(translate_error(GetLastError()));
      error++;

     }

   if(error==10)
     {
      //     add_log("Order modify failed too many times");
      OrderClose(trade_ticket,OrderLots(),OrderClosePrice(),30);
      return -1;
     }

//  add_log("Order Modify Success!");
//   add_log("TP: "+calculate_profit_by_distance(lotsize_to_use,tp_pip_distance)+AccountCurrency());
//   add_log("SL: "+calculate_profit_by_distance(lotsize_to_use,sl_pip_distance)+AccountCurrency());
   return trade_ticket;


  }

//+------------------------------------------------------------------+
//|      MAKE A LONG DECIMAL INTO (x) DECIMAL PLACES                 |
//+------------------------------------------------------------------+
string n(string number, int decimalPoints=2)
  {
   int start_index = StringFind(number, ".");
   if(start_index == -1)
      return number;

   string vals[2] = {"", ""};
   StringSplit(number, '.', vals);

   if(StringLen(vals[1]) <= decimalPoints)
      return number;

   return StringConcatenate(vals[0], ".", StringSubstr(vals[1], 0, 2));
  }
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void check_trail(double trail_behind)
  {
   for(int i; i<OrdersTotal(); i++)
     {
      double gap;
      OrderSelect(i,SELECT_BY_POS);
      if(OrderType()==OP_BUY)
        {
         gap = (Bid-OrderStopLoss())/pip_value;
         if(gap>trail_behind)
           {
            OrderModify(OrderTicket(),Bid,Bid-(trail_behind*pip_value),OrderTakeProfit(),NULL);
           }
        }

      if(OrderType()==OP_SELL)
        {
         gap = (OrderStopLoss()-Ask)/pip_value;
         if(gap>trail_behind)
           {
            OrderModify(OrderTicket(),Ask,Ask+(trail_behind*pip_value),OrderTakeProfit(),NULL);
           }
        }
     }
  }

//+------------------------------------------------------------------+
//|              FIND LOWEST CANDLE SINCE (x) AMOUNT OF CANDLES      |
//+------------------------------------------------------------------+
int find_lowest_candle(int since_how_many_candles,int start_at=0)
  {
   int lowest_candle = iLowest(Symbol(),0,MODE_LOW,since_how_many_candles,start_at);

   double low = iLow(Symbol(),0,lowest_candle);
   double high = iHigh(Symbol(),0,lowest_candle);
   double open = iOpen(Symbol(),0,lowest_candle);
   double close = iClose(Symbol(),0,lowest_candle);

   arrow_up("Low number "+low_counter,low,lowest_candle,clrRed);

   add_log("Lowest price since "+since_how_many_candles+" back is "+low);

   low_counter=low_counter+1;

   return lowest_candle;

  }
//+------------------------------------------------------------------+
//|               FIND HIGHEST CANDLE SINCE (x) AMOUNT OF CANDLES    |
//+------------------------------------------------------------------+
int find_highest_candle(int since_how_many_candles,int start_at=0)
  {
   int highest_candle = iHighest(Symbol(),0,MODE_HIGH,since_how_many_candles,start_at);

   double high = iHigh(Symbol(),0,highest_candle);
   double low = iLow(Symbol(),0,highest_candle);
   double open = iOpen(Symbol(),0,highest_candle);
   double close = iClose(Symbol(),0,highest_candle);

   arrow_down("High number "+high_counter,high,highest_candle,clrBlue);

   add_log("Highest price since "+since_how_many_candles+" back is "+high);

   high_counter++;

   return highest_candle;
  }


//+------------------------------------------------------------------+
//|           IS PAIR (x) AT ITS DAILY HIGH                          |
//+------------------------------------------------------------------+
bool is_pair_at_daily_high(string symbol)
  {
   double price = MarketInfo(symbol,MODE_ASK);
   double daily_high = iHigh(symbol,d1,0);
   if(price>=daily_high)
      return True;
   return False;

  }

//+------------------------------------------------------------------+
//|              IS PAIR (x) AT ITS DAILY LOW                        |
//+------------------------------------------------------------------+
bool is_pair_at_daily_low(string symbol)
  {
   double price = MarketInfo(symbol,MODE_BID);
   double daily_low = iLow(symbol,d1,0);
   if(price<=daily_low)
      return True;
   return False;

  }

//+------------------------------------------------------------------+
//|              IS PAIR (x) AT ITS WEEKLY HIGH                      |
//+------------------------------------------------------------------+
bool is_pair_at_weekly_high(string symbol)
  {
   double price = MarketInfo(symbol,MODE_ASK);
   double weekly_high = iHigh(symbol,w1,0);
   if(price>=weekly_high)
      return True;
   return False;

  }

//+------------------------------------------------------------------+
//|              IS PAIR (x) AT ITS WEEKLY LOW                       |
//+------------------------------------------------------------------+
bool is_pair_at_weekly_low(string symbol)
  {
   double price = MarketInfo(symbol,MODE_BID);
   double weekly_low = iLow(symbol,w1,0);
   if(price<=weekly_low)
      return True;
   return False;

  }

//+------------------------------------------------------------------+
//|              IS PAIR (x) AT ITS MONTHLY HIGH                     |
//+------------------------------------------------------------------+
bool is_pair_at_monthly_high(string symbol)
  {
   double price = MarketInfo(symbol,MODE_ASK);
   double monthly_high = iHigh(symbol,mn1,0);
   if(price>=monthly_high)
      return True;
   return False;

  }

//+------------------------------------------------------------------+
//|              IS PAIR (x) AT ITS MONTHLY LOW                      |
//+------------------------------------------------------------------+
bool is_pair_at_monthly_low(string symbol)
  {
   double price = MarketInfo(symbol,MODE_BID);
   double monthly_low = iLow(symbol,mn1,0);
   if(price<=monthly_low)
      return True;
   return False;

  }


//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
int get_most_recently_closed_trade()
  {
   datetime latest_date;
   int ticket;
   for(int i; i<OrdersHistoryTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS,MODE_HISTORY);
      if(OrderCloseTime()>latest_date)
        {
         ticket = OrderTicket();
        }

     }
     
     return ticket;


  }
  

int get_most_recently_opened_trade()
  {
   datetime latest_date;
   int ticket;
   for(int i; i<=OrdersTotal(); i++)
     {
      OrderSelect(i,SELECT_BY_POS);
      if(OrderOpenTime()>latest_date)
        {
         ticket = OrderTicket();
        }

     }
     
     return ticket;


  }
//+------------------------------------------------------------------+
//+------------------------------------------------------------------+
//| TRANSLATE A MT4 ERROR (GetLastError()) INTO HUMAN READABLE FORM  |
//+------------------------------------------------------------------+
string translate_error(int e)
  {
   switch(e)
     {
      case 0:
         return("Error 0000:  No error returned.");
      case 1:
         return("Error 0001:  No error returned, but the result is unknown.");
      case 2:
         return("Error 0002:  Common error.");
      case 3:
         return("Error 0003:  Invalid trade parameters.");
      case 4:
         return("Error 0004:  Trade server is busy.");
      case 5:
         return("Error 0005:  Old version of the client terminal.");
      case 6:
         return("Error 0006:  No connection with trade server.");
      case 7:
         return("Error 0007:  Not enough rights.");
      case 8:
         return("Error 0008:  Too frequent requests.");
      case 9:
         return("Error 0009:  Malfunctional trade operation.");
      case 64:
         return("Error 0064:  Account disabled.");
      case 65:
         return("Error 0065:  Invalid account.");
      case 128:
         return("Error 0128:  Trade timeout.");
      case 129:
         return("Error 0129:  Invalid price.");
      case 130:
         return("Error 0130:  Invalid stops.");
      case 131:
         return("Error 0131:  Invalid trade volume.");
      case 132:
         return("Error 0132:  Market is closed.");
      case 133:
         return("Error 0133:  Trade is disabled.");
      case 134:
         return("Error 0134:  Not enough money.");
      case 135:
         return("Error 0135:  Price changed.");
      case 136:
         return("Error 0136:  Off quotes.");
      case 137:
         return("Error 0137:  Broker is busy.");
      case 138:
         return("Error 0138:  Requote.");
      case 139:
         return("Error 0139:  Order is locked.");
      case 140:
         return("Error 0140:  Long positions only allowed.");
      case 141:
         return("Error 0141:  Too many requests.");
      case 145:
         return("Error 0145:  Modification denied because order too close to market.");
      case 146:
         return("Error 0146:  Trade context is busy.");
      case 147:
         return("Error 0147:  Expirations are denied by broker.");
      case 148:
         return("Error 0148:  The amount of open and pending orders has reached the limit set by the broker.");
      case 149:
         return("Error 0149:  An attempt to open a position opposite to the existing one when hedging is disabled.");
      case 150:
         return("Error 0150:  An attempt to close a position contravening the FIFO rule.");
      case 4000:
         return("Error 4000:  No error.");
      case 4001:
         return("Error 4001:  Wrong function pointer.");
      case 4002:
         return("Error 4002:  Array index is out of range.");
      case 4003:
         return("Error 4003:  No memory for function call stack.");
      case 4004:
         return("Error 4004:  Recursive stack overflow.");
      case 4005:
         return("Error 4005:  Not enough stack for parameter.");
      case 4006:
         return("Error 4006:  No memory for parameter string.");
      case 4007:
         return("Error 4007:  No memory for temp string.");
      case 4008:
         return("Error 4008:  Not initialized string.");
      case 4009:
         return("Error 4009:  Not initialized string in array.");
      case 4010:
         return("Error 4010:  No memory for array string.");
      case 4011:
         return("Error 4011:  Too long string.");
      case 4012:
         return("Error 4012:  Remainder from zero divide.");
      case 4013:
         return("Error 4013:  Zero divide.");
      case 4014:
         return("Error 4014:  Unknown command.");
      case 4015:
         return("Error 4015:  Wrong jump (never generated error).");
      case 4016:
         return("Error 4016:  Not initialized array.");
      case 4017:
         return("Error 4017:  DLL calls are not allowed.");
      case 4018:
         return("Error 4018:  Cannot load library.");
      case 4019:
         return("Error 4019:  Cannot call function.");
      case 4020:
         return("Error 4020:  Expert function calls are not allowed.");
      case 4021:
         return("Error 4021:  Not enough memory for temp string returned from function.");
      case 4022:
         return("Error 4022:  System is busy (never generated error).");
      case 4050:
         return("Error 4050:  Invalid function parameters count.");
      case 4051:
         return("Error 4051:  Invalid function parameter value.");
      case 4052:
         return("Error 4052:  String function internal error.");
      case 4053:
         return("Error 4053:  Some array error.");
      case 4054:
         return("Error 4054:  Incorrect series array using.");
      case 4055:
         return("Error 4055:  Custom indicator error.");
      case 4056:
         return("Error 4056:  Arrays are incompatible.");
      case 4057:
         return("Error 4057:  Global variables processing error.");
      case 4058:
         return("Error 4058:  Global variable not found.");
      case 4059:
         return("Error 4059:  Function is not allowed in testing mode.");
      case 4060:
         return("Error 4060:  Function is not confirmed.");
      case 4061:
         return("Error 4061:  Send mail error.");
      case 4062:
         return("Error 4062:  String parameter expected.");
      case 4063:
         return("Error 4063:  Integer parameter expected.");
      case 4064:
         return("Error 4064:  Double parameter expected.");
      case 4065:
         return("Error 4065:  Array as parameter expected.");
      case 4066:
         return("Error 4066:  Requested history data in updating state.");
      case 4067:
         return("Error 4067:  Some error in trading function.");
      case 4099:
         return("Error 4099:  End of file.");
      case 4100:
         return("Error 4100:  Some file error.");
      case 4101:
         return("Error 4101:  Wrong file name.");
      case 4102:
         return("Error 4102:  Too many opened files.");
      case 4103:
         return("Error 4103:  Cannot open file.");
      case 4104:
         return("Error 4104:  Incompatible access to a file.");
      case 4105:
         return("Error 4105:  No order selected.");
      case 4106:
         return("Error 4106:  Unknown symbol.");
      case 4107:
         return("Error 4107:  Invalid price.");
      case 4108:
         return("Error 4108:  Invalid ticket.");
      case 4109:
         return("Error 4109:  Trade is not allowed. Enable checkbox 'Allow live trading' in the expert properties.");
      case 4110:
         return("Error 4110:  Longs are not allowed. Check the expert properties.");
      case 4111:
         return("Error 4111:  Shorts are not allowed. Check the expert properties.");
      case 4200:
         return("Error 4200:  Object exists already.");
      case 4201:
         return("Error 4201:  Unknown object property.");
      case 4202:
         return("Error 4202:  Object does not exist.");
      case 4203:
         return("Error 4203:  Unknown object type.");
      case 4204:
         return("Error 4204:  No object name.");
      case 4205:
         return("Error 4205:  Object coordinates error.");
      case 4206:
         return("Error 4206:  No specified subwindow.");
      case 4207:
         return("Error 4207:  Some error in object function.");
      //    case 9001:  return("Error 9001:  Cannot close entire order - insufficient volume previously open.");
      //    case 9002:  return("Error 9002:  Incorrect net position.");
      //    case 9003:  return("Error 9003:  Orders not completed correctly - details in log file.");
      default:
         return("Error " + IntegerToString(e) + ": ??? Unknown error.");
     }
   return("");
  }
//+------------------------------------------------------------------+
