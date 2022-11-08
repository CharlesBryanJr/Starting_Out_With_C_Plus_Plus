//+------------------------------------------------------------------+
//|                                                    dashboard.mq4 |
//|                                                             Mike |
//|                                                              yes |
//+------------------------------------------------------------------+
#property copyright "Mike"
#property link      "yes"
#property version   "1.00"
#property strict
#include <shapes.mqh>
string dash_label; //Title of the dashboard
int text_size; // Size of text

string dashboard_feed[]; // Array to store logging
int feed_length; // Max logger history size



int counter;
color text_colour;

//+------------------------------------------------------------------+
//|              CREATE THE DASHBOARD ON THE CHART!                  |
//+------------------------------------------------------------------+
void init_dashboard(
   string dashboard_name,
   int logger_text_size=8,
   int dashboard_feed_length=20,
   color header_colour=clrRoyalBlue,
   color header_text_colour=clrWhite,
   color dashboard_box_colour=clrWhiteSmoke,
   color text_color=clrBlack
)
  {
   text_color=text_color;
   ObjectsDeleteAll();
   dash_label = dashboard_name; //Set the title
   PREFIX = dashboard_name; //Set the prefix
   feed_length=dashboard_feed_length; // How many logs will we show

   _X = 10  ; // Set the X axis
   _Y = 20  ; // Set the Y axis
   _W = 300 ; // Set the Width of dashboard
   _H = 190 ; // Set the Height of dashboard
   text_size = logger_text_size ;  //Set the text size

   ArrayResize(dashboard_feed,dashboard_feed_length); //Resize the array to hold (dashboard_feed_length) logs

   show_dashboard_on_chart(
      header_colour=header_colour,
      header_text_colour=header_text_colour,
      dashboard_box_colour = dashboard_box_colour,
      text_color=text_color
   );

  }

//+------------------------------------------------------------------+
//|                      PUT THE DASHBOARD ON THE CHART              |
//+------------------------------------------------------------------+
void show_dashboard_on_chart(color header_colour,color header_text_colour,color dashboard_box_colour,color text_colour)
  {
   int panel_x=_X; //Set panel X axis
   int panel_y=_Y; //Set panel Y axis
   int panel_w=_W; //Set panel Width
   int panel_h=_H; //Set panel Height
   color panel_color=header_colour; //Set panel Color

   int dashboard_window_x=_X; //Set dashboard window X axis
   int dashboard_window_y=_Y+33; //Set dashboard window Y axis
   int dashboard_window_w=_W; //Set dashboard window Width
   int dashboard_window_h=_H-30; //Set dashboard window Height
   color dashboard_window_color=dashboard_box_colour; //Set dashboard window Color

   string dashboard_title = dash_label; //Set dashboard title
   int dashboard_title_x = _X+8; //Set dashboard title X axis
   int dashboard_title_y = _Y+5; //Set dashboard title Y axis
   color dashboard_title_color=header_text_colour; //Set dashboard title color
   string dashboard_title_font = "Arial Black"; //Set dashboard title font

   rectangle("dasboard", panel_x,panel_y, panel_w, panel_h, CORNER_LEFT_UPPER, BORDER_RAISED, STYLE_SOLID, 1, panel_color); //Create dashboard panel

   label("dashboard_title",dashboard_title_x,dashboard_title_y, CORNER_LEFT_UPPER,dashboard_title, text_size, dashboard_title_color, dashboard_title_font); //Create dashbaord title

   rectangle("logger", dashboard_window_x, dashboard_window_y, dashboard_window_w, dashboard_window_h, CORNER_LEFT_UPPER, BORDER_FLAT, STYLE_SOLID, 1, dashboard_window_color); //Create dashboard window

  };



//+------------------------------------------------------------------+
//|                   Add text to logger                             |
//+------------------------------------------------------------------+
void add_log(string value)
  {
   printf(value);

   value=TimeToStr(Time[0])+" - "+value;
   bool is_full;
   save(value,is_full); //Save the new value and return is_full as being true or false
   if(is_full==true)
     {
      update_log(); // Update the log
      save(value,is_full);// Save the log after update
     }

   update_chart();

  };

//+------------------------------------------------------------------+
void save(string value,bool &is_full)
  {
   is_full = true ;
   for(int i = 0 ; i<feed_length ; i++)
     {
      if(dashboard_feed[i]==NULL)
        {
         dashboard_feed[i] = value;
         is_full = false ;
         break ;
        }
     }
  }

//+------------------------------------------------------------------+


void update_chart()
  {
   int height_shift = _H+25;
   int x_axis_position=_X+10;
   int y_axis_position=_Y+50;

   for(int i = feed_length-1; i>=0; i--)
     {
      if(dashboard_feed[i]!=NULL)  //If there is a value in the array
        {
         ObjectSetInteger(0,PREFIX +"logger", OBJPROP_YSIZE, height_shift);
         label("log_"+IntegerToString(i),x_axis_position, y_axis_position, CORNER_LEFT_UPPER,">> "+dashboard_feed[i], text_size, clrDarkBlue);

         height_shift+=25;
         y_axis_position+=20;
        }
     }
  }

//+------------------------------------------------------------------+
void update_log()
  {
   dashboard_feed[0]=NULL;
   for(int i = 0 ; i<feed_length ; i++)
     {
      if(dashboard_feed[i]==NULL && i+1<feed_length)
        {
         dashboard_feed[i]=dashboard_feed[i+1];
         dashboard_feed[i+1] = NULL ;
        }
     }
  }
//+------------------------------------------------------------------+
