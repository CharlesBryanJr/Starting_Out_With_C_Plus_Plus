
    // =============================================================
    // This is a program to of Programming Challenge 5.03
    // =============================================================

    #include <iostream>
    #include <iomanip>

    // =============================================================

    int main(){
        std::cout<<"============================================\n";
        std::cout<<"\t     :: Information ::\n";
        std::cout<<"This program is used to display the annual\n";
        std::cout<<"increase of the ocean\'s level compared to\n";
        std::cout<<"the current level over the coming 25 years\n";
        std::cout<<"============================================\n";
        
        // ---------------------------------------------------------
        // Definitions
        float increment = 1.5;
        
        for(int year=1; year<=25; year++){
            // -----------------------------------------------------
            // Within each iteration, we multiply the ratio by the
            // iteration number starting from 1 to 25 because the
            // increment ratio doubles over the years.
            // :::::::::::::::::::::::::::::::::::::::::::::::::::::
            // setw and setfill are for formatting only and defined
            // in <iomanip> header.
            // -----------------------------------------------------
            std::cout<<"After "<<std::setw(2)<<year<<" year(s), the increase would be "<< year*increment<<std::endl;
        }
        
        std::cout<<"============================================\n";
        return 0;
    }
    
    // =============================================================





