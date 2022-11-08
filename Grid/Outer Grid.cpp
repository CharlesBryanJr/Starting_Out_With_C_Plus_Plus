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
   down=1
  };
extern string EA_name = "Outer Grid";
extern double edge_pips = 125;
extern int intervals = 10;
extern double partial_close =10;
extern trend_or_range market_condition = trending;
extern direction up_or_down = up;
extern int magic_number = 555;
extern double compound = 1;

//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
  {
//---
   init_dashboard("Outer Grid");
   outer.initialise(EA_name,edge_pips,intervals,magic_number,Symbol());
   outer.create_grid();
//---
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
   outer.check();
  }
//+------------------------------------------------------------------+

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
class OuterGrid
  {
public:
   void              initialise(string _name, double _outer_edge_pips, int intervals,int _magic_number, string _asset);
   void              create_grid();
   void              check();
   void              open();
   void              new_core_grid(string _asset,int _buy_or_sell,int _partial_close,   double _interval_pips,   double _sl_pips,   double _risk_percentage,   string _name,   int _magic_number,   bool _reopen,   double _compound_percentage);
   void              check_inner_grids();
   int               intervals;
   string            asset;


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
void OuterGrid::initialise(string _name,double _outer_edge_pips,int _intervals, int _magic_number,string _asset="")
  {

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
   int _partial_close=partial_close;
   double _sl_pips =100;
   double _risk_percentage=1;

   if(up_or_down==up && market_condition == trending)
     {
      _buy_or_sell=0;

     }
   if(up_or_down==up && market_condition == ranging)
     {
      _buy_or_sell=1;
      _sl_pips= (outer_edge_price - price_points[current_interval_point])/grid_pip_value;
     }

   if(up_or_down==down && market_condition == trending)
     {
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
      compound
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