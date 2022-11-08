#include <iostream>

// Using the following chart, write an if/else if statement that assigns .10, .15, or .20 to commission, depending on the value in sales.

int main(){
    int sales{12345};
    int commission{0};

    if( sales <= 10000 )
    {
        commission = 0.10;
    }
    else if( sales > 10000 && sales < 15000 )
    {
        commission = 0.15;
    }
    else
    {
        commission = 0.20;
    }

    return 0;
} 