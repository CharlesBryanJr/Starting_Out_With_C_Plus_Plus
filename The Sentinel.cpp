//+------------------------------------------------------------------+
//|                                               high_frequency.mq4 |
//|                        Copyright 2021, MetaQuotes Software Corp. |
//|                                             https://www.mql5.com |
//+------------------------------------------------------------------+
#property copyright "Copyright 2021, MetaQuotes Software Corp."
#property link      "https://www.mql5.com"
#property version   "1.00"
#property strict
#include <stash.mqh>
#include <dashboard.mqh>


extern string EA_NAME="SENTINEL!";
extern int TRIGGER_MAGIC_NUMBER=1111;
extern double INTERVAL_PIPS=2;
extern double TRAIL_DISTANCE=3;
extern double LOTSIZE=0.01;
extern bool RETRACE=False;
extern bool HEDGE=False;
extern int MAGIC_NUMBER=222;
//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
  {
//---
   init_dashboard("Sentinel!!!!!");
   pip_value = grab_pip_value();
   s.initialise(EA_NAME,TRIGGER_MAGIC_NUMBER,INTERVAL_PIPS,TRAIL_DISTANCE,LOTSIZE,RETRACE,HEDGE,MAGIC_NUMBER);
//   b.initialise(EA_NAME,TRIGGER_MAGIC_NUMBER,INTERVAL_PIPS,TRAIL_DISTANCE,LOTSIZE,RETRACE,HEDGE,MAGIC_NUMBER+1);
   open_buy(3,1,1000,1000,"pips","TRIGGER!!!!",1111);




   return(INIT_SUCCEEDED);
  }
//+------------------------------------------------------------------+
//| Expert deinitialization function                                 |
//+------------------------------------------------------------------+
void OnDeinit(const int reason)
  {
//---

  }
//+------------------------------------------------------------------+
//| Expert tick function                                             |
//+------------------------------------------------------------------+
void OnTick()
  {
//---
if(s.is_running==False){s.check_for_open();}
else
{
s.check();
s.check_trail();

}
  }
//+------------------------------------------------------------------+
class Sentinel
  {

public:

   void              initialise(string _name, int _trigger_magic_number, double _interval_pips, double _trail_distance, double _lotsize, bool _retracement, bool _hedge,int _magic_number);
   void              check();
   void              check_();
   void              check_for_open();
   void              check_trail();
   void execute();


   int               trigger_magic_number;
   bool              hedge;
   bool              retracement;
   double            lotsize;
   double            trail_pips;
   double            interval_pips;
   int               magic_number;
   string            name;
   int               buy_or_sell;

   double            upper_limit;
   double            lower_limit;

   double            tp_pips;

   bool              is_running;
   
   int               trigger_trade;






  };

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void Sentinel::initialise(string _name,int _trigger_magic_number,double _interval_pips,double _trail_distance,double _lotsize,bool _retracement,bool _hedge,int _magic_number)
  {
   name = _name;
   trigger_magic_number = _trigger_magic_number;
   trail_pips = _trail_distance;
   interval_pips = _interval_pips;
   lotsize = _lotsize;
   retracement = _retracement;
   hedge = _hedge;
   magic_number = _magic_number;
   is_running = False;
   tp_pips = 1000;




  };

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void Sentinel::check_for_open()
  {

   if(a_trade_has_opened())
     {

      int ticket = get_most_recently_opened_trade();
      OrderSelect(ticket,SELECT_BY_TICKET);
      if(OrderMagicNumber()== trigger_magic_number)
        {
         buy_or_sell=OrderType();
         trigger_trade=OrderType();
         if(OrderType()==OP_BUY && hedge==True)
            buy_or_sell=OP_SELL;
         if(OrderType()==OP_SELL && hedge==True)
            buy_or_sell=OP_BUY;

         upper_limit = OrderOpenPrice() + (interval_pips*pip_value);
         lower_limit = OrderOpenPrice() - (interval_pips*pip_value);
         is_running = True;


        }

     }

  }
//+------------------------------------------------------------------+

void Sentinel::check()
{
if(Ask>upper_limit)Sentinel::execute();
if(Ask<lower_limit)Sentinel::execute();



}
void Sentinel::execute(){
int ticket;
if(buy_or_sell==OP_BUY)ticket = open_buy(3,lotsize,tp_pips,trail_pips,"pips",name,magic_number);
if(buy_or_sell==OP_SELL)ticket = open_sell(3,lotsize,tp_pips,trail_pips,"pips",name,magic_number);
OrderSelect(ticket,SELECT_BY_TICKET);
upper_limit = OrderOpenPrice()+(interval_pips*pip_value);
lower_limit = OrderOpenPrice()-(interval_pips*pip_value);
if(buy_or_sell==OP_BUY && retracement== False)lower_limit=0;
if(buy_or_sell==OP_SELL && retracement== False)upper_limit=10000;
}


void Sentinel::check_()
  {
   if(buy_or_sell==OP_BUY)
     {
      if(Ask>upper_limit)
        {
        
         int ticket = open_buy(3,lotsize,tp_pips,trail_pips,"pips",name,magic_number);
         OrderSelect(ticket,SELECT_BY_TICKET);
         upper_limit = OrderOpenPrice()+(interval_pips*pip_value);
         if(retracement==True)
           {
            lower_limit = OrderOpenPrice()-(interval_pips*pip_value);
           }
        }

      if(Ask<lower_limit && retracement)
        {
         int ticket = open_buy(3,lotsize,tp_pips,trail_pips,"pips",name,magic_number);
         OrderSelect(ticket,SELECT_BY_TICKET);
         upper_limit = OrderOpenPrice()+(interval_pips*pip_value);
         lower_limit = OrderOpenPrice()-(interval_pips*pip_value);
        }
     }


   if(buy_or_sell==OP_SELL)
     {
      if(Bid<lower_limit)
        {
         int ticket = open_sell(3,lotsize,tp_pips,trail_pips,"pips",name,magic_number);
         OrderSelect(ticket,SELECT_BY_TICKET);
         lower_limit = OrderOpenPrice()-(interval_pips*pip_value);
         if(retracement==True)
           {
            upper_limit = OrderOpenPrice()+(interval_pips*pip_value);
           }
        }

      if(Bid>upper_limit && retracement)
        {
         int ticket = open_sell(3,lotsize,tp_pips,trail_pips,"pips",name,magic_number);
         OrderSelect(ticket,SELECT_BY_TICKET);
         upper_limit = OrderOpenPrice()+(interval_pips*pip_value);
         lower_limit = OrderOpenPrice()-(interval_pips*pip_value);
        }
     }

  }
//+------------------------------------------------------------------+

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void Sentinel::check_trail()
  {

   for(int i; i<OrdersTotal(); i++)
     {
      double gap;
      OrderSelect(i,SELECT_BY_POS);
      if(OrderType()==OP_BUY && OrderMagicNumber()==magic_number)
        {
         gap = (Bid-OrderStopLoss())/pip_value;
         if(gap >trail_pips)
           {
            OrderModify(OrderTicket(),Bid,Bid-(trail_pips*pip_value),OrderTakeProfit(),NULL);
            h_line("Trail Point",clrLightBlue,Bid-(trail_pips*pip_value),"Trailing Point");
           }
        }

      if(OrderType()==OP_SELL && OrderMagicNumber()==magic_number)
        {
         gap=(OrderStopLoss()-Ask)/pip_value;
         if(gap>trail_pips)
           {
            OrderModify(OrderTicket(),Ask,Ask+(trail_pips*pip_value),OrderTakeProfit(),NULL);
            h_line("Trail Point", clrLightBlue, Ask+(trail_pips*pip_value), "Trailing Point");
           }
        }
     }

  }
//+------------------------------------------------------------------+

Sentinel s;
Sentinel b;
//+------------------------------------------------------------------+