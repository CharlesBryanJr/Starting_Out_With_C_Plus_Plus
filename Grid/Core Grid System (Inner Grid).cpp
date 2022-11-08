//+------------------------------------------------------------------+
//|                                                  core_grid_1.mq4 |
//|                        Copyright 2021, MetaQuotes Software Corp. |
//|                                             https://www.mql5.com |
//+------------------------------------------------------------------+
#property copyright "Copyright 2021, MetaQuotes Software Corp."
#property link      "https://www.mql5.com"
#property version   "1.00"
#property strict

#include <core_grid.mqh>

string ea_name = "COOL GRID";
int magic_number = 5678;

//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
  {
   init_dashboard(ea_name);
      new_grid(Symbol(),OP_BUY,10,10,50,10,ea_name,magic_number,true,0.5);
      new_grid(Symbol(),OP_SELL,10,10,50,10,ea_name,magic_number+1,true,0.5);
   
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
   check_grids();
  }
//+------------------------------------------------------------------+