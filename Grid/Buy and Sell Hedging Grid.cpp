//+------------------------------------------------------------------+
//|                                            live_outer_grid_2.mq4 |
//|                        Copyright 2021, MetaQuotes Software Corp. |
//|                                             https://www.mql5.com |
//+------------------------------------------------------------------+
#property copyright "Copyright 2021, MetaQuotes Software Corp."
#property link      "https://www.mql5.com"
#property version   "1.00"
#property strict


#include <stash.mqh>
#include <dashboard.mqh>
#include <core_grid.mqh>

enum trend_or_range
  {
   trending=0,
   ranging=1
  };

enum direction
  {
   up=0,
   down=1,
   both=2
  };
extern string EA_NAME = "Outer Grid";
extern double EDGE_PIPS = 125;
extern double RISK_PERCENTAGE = 1;
extern int INTERVALS = 10;
extern double PARTIAL_CLOSE =10;
extern trend_or_range MARKET_CONDITION = trending;
extern direction UP_OR_DOWN = up;
extern bool CLOSE_ON_RETRACEMENT = True;
extern int MAGIC_NUMBER = 5555;
extern double COMPOUND = 1;


//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
  {

   init_dashboard("Outer Grid");
   if(UP_OR_DOWN!=both)
     {
      new_outer_grid(EDGE_PIPS,INTERVALS,MARKET_CONDITION,UP_OR_DOWN,MAGIC_NUMBER,Symbol());
     }
   if(UP_OR_DOWN==both)
     {
      new_outer_grid(EDGE_PIPS,INTERVALS,MARKET_CONDITION,up,MAGIC_NUMBER,Symbol());
      new_outer_grid(EDGE_PIPS,INTERVALS,MARKET_CONDITION,down,MAGIC_NUMBER*100,Symbol());
     }

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

   check_outer_grids();
  }
//+------------------------------------------------------------------+

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
class OuterGrid
  {
public:
   void              initialise(string _name, double _outer_edge_pips, int intervals,int _up_or_down, int _market_condition,int _magic_number, string _asset);
   void              create_grid();
   void              check();
   void              open();
   void              new_core_grid(string _asset,int _buy_or_sell,int _partial_close,   double _interval_pips,   double _sl_pips,   double _risk_percentage,   string _name,   int _magic_number,   bool _reopen,   double _compound_percentage);
   void              check_inner_grids();


   int               intervals;
   string            asset;
   direction         up_or_down;
   trend_or_range    market_condition;



   double            starting_price;
   double            outer_edge_pips;
   double            outer_edge_price;
   double            price_points[];
   int               magic_number;
   string            name;
   double            interval_distance_pips;
   double            grid_pip_value;
   int               current_interval_point;
   CoreGrid          core_grid_array[];




  };

//+------------------------------------------------------------------+
void OuterGrid::initialise(
   string _name,
   double _outer_edge_pips,
   int _intervals,
   int _up_or_down,
   int _market_condition,
   int _magic_number,
   string _asset=""
)
  {
   market_condition = _market_condition;
   up_or_down = _up_or_down;
   asset = _asset;
   intervals = _intervals;

   outer_edge_pips = _outer_edge_pips;
   magic_number=_magic_number;
   name=_name;
   grid_pip_value = grab_pip_value(_asset);



  }

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void OuterGrid::create_grid()
  {

   starting_price=(Ask+Bid)/2;
   h_line(name+"_starting_point",clrBlue,starting_price,"Starting Point: "+starting_price);
   if(up_or_down==up)
     {
      outer_edge_price = starting_price + (outer_edge_pips*grid_pip_value);
      h_line(name+"_upper edge",clrRed,outer_edge_price,"Upper Edge: "+outer_edge_price);
      interval_distance_pips = outer_edge_pips/(intervals+1);
      current_interval_point = 0;
      ArrayResize(price_points,intervals+1);
      price_points[0]=starting_price;
      for(int i=1; i<=intervals; i++)
        {
         price_points[i]= starting_price+((interval_distance_pips*grid_pip_value)*i);
         h_line(up_or_down+name+"_point_"+i,clrLightBlue,price_points[i],"Point "+i);
        }

     }

   if(up_or_down==down)
     {
      outer_edge_price = starting_price - (outer_edge_pips*grid_pip_value);
      h_line(name+"_lower edge",clrRed,outer_edge_price,"Lower Edge: "+outer_edge_price);
      interval_distance_pips = outer_edge_pips/(intervals+1);
      current_interval_point =0;
      ArrayResize(price_points,intervals+1);
      price_points[0]=starting_price;
      for(int i=1; i<=intervals; i++)
        {
         price_points[i]= starting_price-((interval_distance_pips*grid_pip_value)*i);
         h_line(up_or_down+name+"_point_"+i,clrLightBlue,price_points[i],"Point "+i);
        }

     }

  }


//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void OuterGrid::check()
  {
   check_inner_grids();

   if(up_or_down==up)
     {
      double next_price_point_up = 9999;
      if(current_interval_point<intervals)
         next_price_point_up = price_points[current_interval_point+1];
      if(Ask>=next_price_point_up)
        {
         current_interval_point++;
         open();
        }
     }

   if(up_or_down==down)
     {
      double next_price_point_down = 0;
      if(current_interval_point<intervals)
         next_price_point_down = price_points[current_interval_point+1];
      if(Ask<=next_price_point_down)
        {
         current_interval_point++;
         open();

        }
     }
  }

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void OuterGrid::open()
  {
   int _buy_or_sell=0;
   int _partial_close=PARTIAL_CLOSE;
   double _sl_pips =100;
   double _risk_percentage=RISK_PERCENTAGE/intervals;

   if(up_or_down==up && market_condition  == trending)
     {
      _buy_or_sell=0;
      _sl_pips=((price_points[current_interval_point]-starting_price)/grid_pip_value)+outer_edge_pips;

     }
   if(up_or_down==up && market_condition  == ranging)
     {
      _buy_or_sell=1;
      _sl_pips= (outer_edge_price - price_points[current_interval_point])/grid_pip_value;
     }

   if(up_or_down==down && market_condition  == trending)
     {
      _sl_pips=((starting_price-price_points[current_interval_point])/grid_pip_value)+outer_edge_pips;
      _buy_or_sell=1;

     }
   if(up_or_down==down && market_condition == ranging)
     {
      _buy_or_sell=0;
      _sl_pips= (price_points[current_interval_point]-outer_edge_price)/grid_pip_value;

     }
   new_core_grid(
      asset,
      _buy_or_sell,
      _partial_close,
      interval_distance_pips,
      _sl_pips,
      _risk_percentage,
      name,
      magic_number,
      true,
      COMPOUND
   );
   magic_number++;

  }

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void OuterGrid::new_core_grid(
   string _asset,int _buy_or_sell,
   int _partial_close,
   double _interval_pips,
   double _sl_pips,
   double _risk_percentage,
   string _name,
   int _magic_number,
   bool _reopen,
   double _compound_percentage
)
  {
   CoreGrid g;
   g.initialise(_asset,_buy_or_sell,_partial_close,_interval_pips,_sl_pips,_risk_percentage,_name,_magic_number,_reopen, _compound_percentage);
   g.show_lines = False;
   g.close_on_retracement = CLOSE_ON_RETRACEMENT;
   g.launch();

   ArrayResize(core_grid_array,ArraySize(core_grid_array)+1);
   core_grid_array[ArraySize(core_grid_array)-1]=g;

  }

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void OuterGrid::check_inner_grids()
  {
   for(int i; i<ArraySize(core_grid_array); i++)
     {
      core_grid_array[i].check();
     }

  }
//+------------------------------------------------------------------+
OuterGrid outer;

//+------------------------------------------------------------------+

OuterGrid outer_grids[];

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void new_outer_grid(double _outer_edge_pips,int _intervals,
                    int _market_condition,
                    int _up_or_down,
                    int _magic_number, string _asset)
  {
   OuterGrid o;
   o.initialise(
      EA_NAME,
      _outer_edge_pips,
      _intervals,
      _up_or_down,
      _market_condition,
      _magic_number,
      _asset
   );
   o.create_grid();
   ArrayResize(outer_grids,ArraySize(outer_grids)+1);
   outer_grids[ArraySize(outer_grids)-1]=o;
  }

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void check_outer_grids()
  {
   for(int i; i<ArraySize(outer_grids); i++)
     {
      outer_grids[i].check();

     }

  }
//+------------------------------------------------------------------+