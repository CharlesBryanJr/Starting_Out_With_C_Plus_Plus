//+------------------------------------------------------------------+
//|                                                       shapes.mqh |
//|                                                             Mike |
//|                                                              yes |
//+------------------------------------------------------------------+
#property copyright "Mike"
#property link      "yes"
#property strict
string PREFIX; // Reference for all objects related to dashboard

int _X; // X axis
int _Y; // Y axis
int _W; // Width
int _H ; // Height
//+------------------------------------------------------------------+
//|                    CREATE A LABEL IN THE CHART                   |
//+------------------------------------------------------------------+
void label(string name, int x, int y, ENUM_BASE_CORNER corner, string text, int font_size, color clr, string font = "Arial")
  {
   name = PREFIX + name ; //Unique name for the label
   ObjectDelete(0, name); //Delete an object if it already exists this name
   ObjectCreate(0, name, OBJ_LABEL, 0, 0, 0); //Create an object with this name
   ObjectSetInteger(0, name, OBJPROP_XDISTANCE, x);//Set object with this name X axis distance
   ObjectSetInteger(0, name, OBJPROP_YDISTANCE, y);//Set object this name Y axis distance
   ObjectSetInteger(0, name, OBJPROP_CORNER, corner);//Position this object in which corner
   ObjectSetString(0, name, OBJPROP_TEXT, text);//Add the text for the label
   ObjectSetString(0, name, OBJPROP_FONT, font);//Set the font of the text for the label
   ObjectSetInteger(0, name, OBJPROP_FONTSIZE, font_size);//Set the font size of the text for the label
   ObjectSetInteger(0, name, OBJPROP_COLOR, clr);//Set the color of the text for the label
   ObjectSetInteger(0, name, OBJPROP_SELECTABLE, true);//Is this object selectable (can you click on it?)
   ObjectSetInteger(0, name, OBJPROP_SELECTED, false);//Is the object already selected (already clicked on?)
   ObjectSetInteger(0, name, OBJPROP_HIDDEN, false);//Is this object hidden from the object
  }

//+------------------------------------------------------------------+
//|                     CREATE A RECTANGLE IN THE CHART              |
//+------------------------------------------------------------------+
void rectangle(string name, int x, int y, int width, int height, ENUM_BASE_CORNER corner, ENUM_BORDER_TYPE border, ENUM_LINE_STYLE style, int line_width, color back_clr)
  {
   name = PREFIX + name ; //Unique name for the rectangle
   ObjectDelete(0, name); //Delete an object if it already exists with this name
   ObjectCreate(0, name, OBJ_RECTANGLE_LABEL, 0, 0, 0); //Create an object with this name
   ObjectSetInteger(0, name, OBJPROP_XDISTANCE, x); //Set object with this name X axis distance
   ObjectSetInteger(0, name, OBJPROP_YDISTANCE, y); //Set object with this name Y axis distance
   ObjectSetInteger(0, name, OBJPROP_XSIZE, width); //Set object with this name Width
   ObjectSetInteger(0, name, OBJPROP_YSIZE, height); //Set object with this name Height
   ObjectSetInteger(0, name, OBJPROP_BGCOLOR, back_clr);//Set background color of this object
   ObjectSetInteger(0, name, OBJPROP_CORNER, corner);//Position this object in which corner
   ObjectSetInteger(0, name, OBJPROP_BORDER_TYPE, border);//Set border type
   ObjectSetInteger(0, name, OBJPROP_STYLE, style);//Set border style
   ObjectSetInteger(0, name, OBJPROP_WIDTH, line_width);//Set object line width around the border of the rectangle
   ObjectSetInteger(0, name, OBJPROP_COLOR, clrBlack);//Set object line colour around the border of the rectangle
   ObjectSetInteger(0, name, OBJPROP_SELECTABLE, false);//Is this object selectable (can you click on it?)
   ObjectSetInteger(0, name, OBJPROP_SELECTED, false);//Is the object already selected (already clicked on?)
   ObjectSetInteger(0, name, OBJPROP_HIDDEN, true);//Is this object hidden from the object
  };

//+------------------------------------------------------------------+
//|                  CREATE A BUTTON ON THE CHART                    |
//+------------------------------------------------------------------+
void button(string name, int x, int y, int width, int height, ENUM_BASE_CORNER corner, string text, int font_size, color clr, color back_clr, color border_clr)
  {
   name = PREFIX + name ;
   ObjectDelete(0, name);
   ObjectCreate(0, name, OBJ_BUTTON, 0, 0, 0);
   ObjectSetInteger(0, name, OBJPROP_XDISTANCE, x);
   ObjectSetInteger(0, name, OBJPROP_YDISTANCE, y);
   ObjectSetInteger(0, name, OBJPROP_XSIZE, width);
   ObjectSetInteger(0, name, OBJPROP_YSIZE, height);
   ObjectSetInteger(0, name, OBJPROP_CORNER, corner);
   ObjectSetString(0, name, OBJPROP_TEXT, text);
   ObjectSetInteger(0, name, OBJPROP_FONTSIZE, font_size);
   ObjectSetInteger(0, name, OBJPROP_COLOR, clr);
   ObjectSetInteger(0, name, OBJPROP_BGCOLOR, back_clr);
   ObjectSetInteger(0, name, OBJPROP_BORDER_COLOR, border_clr);
   ObjectSetInteger(0, name, OBJPROP_SELECTABLE, false);
   ObjectSetInteger(0, name, OBJPROP_SELECTED, false);
   ObjectSetInteger(0, name, OBJPROP_HIDDEN, true);
  }

//+------------------------------------------------------------------+
//|                 CREATE A TEXT EDIT BOX ON THE CHART              |
//+------------------------------------------------------------------+
void edit_box(string name, int x, int y, int w, int h, string text, int font_size, color clr = clrBlack, ENUM_BASE_CORNER corner=CORNER_RIGHT_UPPER)
  {
   name = PREFIX + name ;
   ObjectDelete(0, name);
   ObjectCreate(0, name, OBJ_EDIT, 0, 0, 0);
   ObjectSetInteger(0, name, OBJPROP_XDISTANCE, x);
   ObjectSetInteger(0, name, OBJPROP_YDISTANCE, y);
   ObjectSetInteger(0, name, OBJPROP_XSIZE, w);
   ObjectSetInteger(0, name, OBJPROP_YSIZE, h);
   ObjectSetInteger(0, name, OBJPROP_CORNER, corner);
   ObjectSetString(0, name, OBJPROP_TEXT, text);
   ObjectSetString(0, name, OBJPROP_FONT, "Arial");
   ObjectSetInteger(0, name, OBJPROP_FONTSIZE, font_size);
   ObjectSetInteger(0, name, OBJPROP_COLOR, clr);
   ObjectSetInteger(0, name, OBJPROP_BGCOLOR, clrWhite);
   ObjectSetInteger(0, name, OBJPROP_BORDER_COLOR, clrGray);
   ObjectSetInteger(0, name, OBJPROP_SELECTABLE, false);
   ObjectSetInteger(0, name, OBJPROP_SELECTED, false);
   ObjectSetInteger(0, name, OBJPROP_HIDDEN, true);
  }

//+------------------------------------------------------------------+
//|              VERTICAL LINE ON CURRENT CANDLE                     |
//+------------------------------------------------------------------+
void v_line(string line_name,color line_colour)
  {
   delete_line(line_name);
   int line_style = 2;
   ObjectCreate(0,line_name,OBJ_VLINE,0,Time[0],0);
   ObjectSetInteger(NULL,line_name,OBJPROP_COLOR,line_colour);
   ObjectSetInteger(0,line_name,OBJPROP_WIDTH,1);
   ObjectSet(line_name,OBJPROP_STYLE,line_style);
  }
//+------------------------------------------------------------------+
//|                HORIZONTAL LINE AT LINE PRICE INPUT
//+------------------------------------------------------------------+
void h_line(string line_name,color line_colour,double line_price, string label="")
  {
   int line_style = 2;
   delete_line(line_name);
   ObjectCreate(NULL,line_name, OBJ_HLINE, 0, Time[0],line_price, 0,0);
   ObjectSetInteger(0,line_name,OBJPROP_COLOR,line_colour);
   ObjectSetInteger(NULL,line_name,OBJPROP_WIDTH,1);
   ObjectSet(line_name,OBJPROP_STYLE,line_style);
   ObjectCreate(0,line_name+"_label", OBJ_TEXT, 0, Time[0], ObjectGet(line_name, OBJPROP_PRICE1));
   ObjectSetText(line_name+"_label", label, 8, "Arial", clrGray);
  }

//+------------------------------------------------------------------+
//|             ARROW UNDERNEATH A CANDLE POINTING UP                |
//+------------------------------------------------------------------+
void arrow_up(string arrow_name,double price, int shift=0,color clr=clrBlue)
  {
  delete_line(arrow_name);

   datetime time = Time[shift];
   ObjectCreate(NULL,arrow_name,OBJ_ARROW_UP,0,time,price);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_ANCHOR,ANCHOR_TOP);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_COLOR,clr);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_STYLE,STYLE_DOT);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_WIDTH,2);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_BACK,true);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_SELECTABLE,true);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_SELECTED,false);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_HIDDEN,false);

   ObjectSetInteger(NULL,arrow_name,OBJPROP_ZORDER,0);
   ObjectCreate(0,arrow_name+"_label", OBJ_TEXT, 0, time, ObjectGet(arrow_name, OBJPROP_PRICE1));
   ObjectSetText(arrow_name+"_label", arrow_name, 8, "Arial", clrGray);
  }


//+------------------------------------------------------------------+
//|             ARROW ABOVE A CANDLE POINTING DOWN                   |
//+------------------------------------------------------------------+
void arrow_down(string arrow_name,double price, int shift=0,color clr=clrBlue)
  {
  delete_line(arrow_name);

   datetime time = Time[shift];
  // double price = price;//-(2*pip_value);
   ObjectCreate(NULL,arrow_name,OBJ_ARROW_DOWN,0,time,price);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_ANCHOR,ANCHOR_BOTTOM);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_COLOR,clr);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_STYLE,STYLE_DOT);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_WIDTH,2);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_BACK,true);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_SELECTABLE,true);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_SELECTED,false);
   ObjectSetInteger(NULL,arrow_name,OBJPROP_HIDDEN,false);

   ObjectSetInteger(NULL,arrow_name,OBJPROP_ZORDER,0);
   ObjectCreate(0,arrow_name+"_label", OBJ_TEXT, 0, time, ObjectGet(arrow_name, OBJPROP_PRICE1));
   ObjectSetText(arrow_name+"_label", arrow_name, 8, "Arial", clrGray);
  }


//+------------------------------------------------------------------+
//|                   DELETE A LINE BY ITS NAME                      |
//+------------------------------------------------------------------+
void delete_line(string line_name)
  {
   ObjectDelete(NULL,line_name);
   ObjectDelete(NULL,line_name+"_label");
  }
//+------------------------------------------------------------------+