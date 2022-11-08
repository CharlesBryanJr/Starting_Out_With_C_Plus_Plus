#include <iostream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cctype>
#include <cstring>
#include <string>
#include <cstdlib>
#include <limits>
#include <ctime>
#include <cmath>

class GameOf21
{
    private:

        // ***--- attributes or member variables ---***
        // What private data is the class responsible of storing
        int PlayerScore;
        int DealerScore;
        const int DIE_SIDES = 6;
        const int BLACKJACK21 = 21;

        Die PlayerDie(DIE_SIDES);
        Die PlayerDie(DIE_SIDES);

        // ***--- methods or member functions ---***
        // What private actions is the class responsible of executing 

    public:
        
        // ***--- attributes or member variables ---***
        // What public data is the class responsible of storing 

        // ***--- methods or member functions ---***
        // What public actions is the class responsible of executing 

            // ***--- costructors ---***
            // Useful for initializing private member variables or executing private member functions
            GameOf21()
            { 
                // PlayerDie(DIE_SIDES);
                // DealerScore(DIE_SIDES);

                // Die PlayerDie(DIE_SIDES);
                // Die PlayerDie(DIE_SIDES);
                PlayerScore = 0; 
                DealerScore = 0;  
            }

            // ***--- accessor or getter ---***
            // Write public accessor functions that return the values in the member variables.
            int getPlayerScore(){ return 0; }
            int getDealerScore(){ return 0; }

            // ***--- mutator or setter  ---***
            // Write public mutator functions to store values in the member variables.
            // Update other member variables if needed.
            void roll(){} 

            // ***--- destructors ---***
            // Useful to free memory that was dynamically allocated by the class object
            ~GameOf21(){}
            
};