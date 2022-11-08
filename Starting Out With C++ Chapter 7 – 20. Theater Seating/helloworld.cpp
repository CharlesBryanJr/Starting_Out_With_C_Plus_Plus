/*
Starting Out With C++ Chapter 7 – 20. Theater Seating
Here is the assignment: Write a program that can be used by a small theater to sell tickets for performances. 
The theater’s auditorium has 15 rows of seats, with 30 seats in each row. 
The program should display a screen that shows which seats are available and which are taken. 
For example, the following screen shows a chart depicting each seat in the theater. 
Seats that are taken are represented by an * symbol, and seats that are available are represented by a # symbol:

Here is a list of tasks this program must perform:
• When the program begins, it should ask the user to enter the seat prices for each row.
The prices can be stored in a separate array. (Alternatively, the prices may be read from a file.)

• Once the prices are entered, the program should display a seating chart similar to the one shown above. 
The user may enter the row and seat numbers for tickets being sold. 

Every time a ticket or group of tickets is purchased, the program should display the total ticket prices and update the seating chart.
• The program should keep a total of all ticket sales. The user should be given an option of viewing this amount.
• The program should also give the user an option to see a list of how many seats have been sold, how many seats are available in each row, and how many seats are available in the entire auditorium.

Input Validation: When tickets are being sold, do not accept row or seat numbers that do not exist. 
When someone requests a particular seat, the program should make sure that seat is available before it is sold.
*/

#include <iostream>
#include <iomanip>
char inputValidation_y_or_n( char &letter)
{
    std::cin >> letter;

    while ( !(letter == 'y' || letter == 'n') )
    {
        std::cout << "ERROR: a 'y' or an 'n' must be entered: ";
        std::cin.clear();
        std::cin >> letter;
    }
    return letter;
}

int inputValidation_postiveInteger_array(int row_seatPrices[], const int &row_ele)
{
	std::cout << "For row " << row_ele+1 << ", input the seat price : ";
        std::cin >> row_seatPrices[row_ele];

    while( row_seatPrices[row_ele] < 0 )
    {
        std::cin.clear();
        std::cout << "Input Validation: Must be a postive integer" << "\n";
        std::cout << "For row " << row_ele+1 << ", input the seat price : ";
            std::cin >> row_seatPrices[row_ele];
    }
    return row_seatPrices[row_ele];
}

int inputValidation_array2D(char auditorium[][30], int row_ele, int column_ele)
{
    std::cout << "Where would you like to sit?" << "\n";
    std::cout << "Row? : ";
        std::cin >> row_ele;

    std::cout << "Column? : ";
        std::cin >> column_ele;
    
    while( auditorium[row_ele][column_ele] == '*' )
    {
        std::cin.clear();
        std::cout << "Input Validation: SEAT NOT AVAILABLE." << "\n";
        std::cout << "Where would you like to sit?" << "\n";
        std::cout << "Row? : ";
            std::cin >> row_ele;

        std::cout << "Column? : ";
            std::cin >> column_ele;
    }

    auditorium[row_ele][column_ele] = '*';
    return row_ele;
}

void create_auditorium(char auditorium[][30], 
                       const int &numberOFrows, 
                       const int &numberOFcolumns, 
                       int &row_ele, 
                       int &column_ele)
{
    std::cout << "---create_auditorium---" << "\n"; std::cout << " " << "\n";
    for(row_ele=0;row_ele<numberOFrows;++row_ele)
    {
        for(column_ele=0;column_ele<numberOFcolumns;++column_ele)
        {
            auditorium[row_ele][column_ele] = '#';
        }
    }
}

void display_auditorium(char auditorium[][30], 
                        const int &numberOFrows, 
                        const int &numberOFcolumns, 
                        int &row_ele, 
                        int &column_ele)
{
    std::cout << "---display_auditorium---" << "\n"; std::cout << " " << "\n";

    for(row_ele=0;row_ele<numberOFrows;++row_ele)
    {
        for(column_ele=0;column_ele<numberOFcolumns;++column_ele)
        {
            std::cout << auditorium[row_ele][column_ele];
        }
        std::cout << " " << "\n";
    }
    std::cout << " " << "\n";
}

void GET_row_seatPrices(int row_seatPrices[], const int &numberOFrows, int &row_ele)
{
    std::cout << "---GET_row_seatPrices---" << "\n"; std::cout << " " << "\n";

    for(row_ele=0;row_ele<numberOFrows;++row_ele)
    {
        inputValidation_postiveInteger_array(row_seatPrices, row_ele);
            std::cout << " " << "\n";
    } 
}

void total_all_ticket_sales(int &all_ticket_sales)
{
    std::cout << "---total_all_ticket_sales---" << "\n"; std::cout << " " << "\n";
    bool view_sales;

    std::cout << "Input 'true' if you like to view the total of all ticket sales? : ";
        std::cin >> std::boolalpha >> view_sales;

    if(view_sales==true)
    {
        std::cout << "The total of all ticket sales is : $" << all_ticket_sales << '\n';
        std::cout << " " << "\n";
    }
}

void total_seat_sold(int &all_ticket_sales, int &seats_sold)
{
    std::cout << "---total_seat_sold---" << "\n"; std::cout << " " << "\n";
    bool view_seats_sold;

    std::cout << "Input 'true' if you like to view how many seats have been sold? : ";
        std::cin >> std::boolalpha >> view_seats_sold;

    if(view_seats_sold==true)
    {
        std::cout << "The number of seats sold is : " << seats_sold << '\n';
        std::cout << " " << "\n";
    }
}

void available_seats_perRow(char auditorium[][30], 
                            const int &numberOFrows, 
                            const int &numberOFcolumns, 
                            int &row_ele, 
                            int &column_ele)
{
    std::cout << "---available_seats_perRow---" << "\n"; std::cout << " " << "\n";
    bool available;
    int available_seats_perRow{0};

    std::cout << "Input 'true' if you like to view how many seats seats are available per row? : ";
        std::cin >> std::boolalpha >> available;

    if(available==true)
    {
        for(row_ele=0;row_ele<numberOFrows;++row_ele)
        {
            available_seats_perRow = 0;
            for(column_ele=0;column_ele<numberOFcolumns;++column_ele)
            {
                if( auditorium[row_ele][column_ele] == '#')
                {
                    available_seats_perRow += 1;
                }
            }
            std::cout << "The number of seats available for row " << row_ele+1 << ", is : " << available_seats_perRow << "\n";
        }
    } 
}

void available_seats(char auditorium[][30], 
                     const int &numberOFrows, 
                     const int &numberOFcolumns, 
                     int &row_ele, 
                     int &column_ele)
{
    std::cout << "---available_seats---" << "\n"; std::cout << " " << "\n";
    bool available;
    int available_seats{0};

    std::cout << "Input 'true' if you like to view how many seats are available? : ";
        std::cin >> std::boolalpha >> available;

    if(available==true)
    {
        for(row_ele=0;row_ele<numberOFrows;++row_ele)
        {
            for(column_ele=0;column_ele<numberOFcolumns;++column_ele)
            {
                if( auditorium[row_ele][column_ele] == '#')
                {
                    available_seats += 1;
                }
            }
        }
        std::cout << "The number of seats available is : " << available_seats << "\n";
    } 
}

void sell_tickets(char auditorium[][30], 
                  int row_seatPrices[], 
                  const int &numberOFrows, 
                  const int &numberOFcolumns, 
                  int &row_ele, 
                  int &column_ele, 
                  int &all_ticket_sales)
{
    std::cout << "---sell_tickets---" << "\n"; std::cout << " " << "\n";
    char buy_more;
    int seats_sold{0};

    while(buy_more != 'n')
    {   
        display_auditorium(auditorium, numberOFrows, numberOFcolumns, row_ele, column_ele);
            std::cout << " " << "\n";

        row_ele = inputValidation_array2D(auditorium,row_ele,column_ele);
            std::cout << "The price for this ticket is : $" << row_seatPrices[row_ele] << "\n";
            all_ticket_sales += row_seatPrices[row_ele];
            seats_sold += 1;
            std::cout << " " << "\n";
        
        total_all_ticket_sales(all_ticket_sales);

        total_seat_sold(all_ticket_sales, seats_sold);

        available_seats_perRow( auditorium, 
                                numberOFrows, 
                                numberOFcolumns, 
                                row_ele,
                                column_ele);

        available_seats( auditorium, 
                         numberOFrows, 
                         numberOFcolumns, 
                         row_ele,
                         column_ele);

        std::cout << "Would you like to buy another seat? (y/n) : ";
            std::cin >> buy_more;
    }
}

int main()
{
	char letter;
    int row_ele,
        column_ele,
        numberOFrows{15},
        numberOFcolumns{30},
        all_ticket_sales{0};
    char auditorium[numberOFrows][30];
    int row_seatPrices[numberOFrows];

	while(letter != 'n')
	{
        create_auditorium(auditorium, numberOFrows, numberOFcolumns, row_ele, column_ele);
        display_auditorium(auditorium, numberOFrows, numberOFcolumns, row_ele, column_ele); std::cout << " " << "\n";
        GET_row_seatPrices(row_seatPrices, numberOFrows, row_ele); 
        sell_tickets(auditorium, 
                    row_seatPrices, 
                    numberOFrows, 
                    numberOFcolumns, 
                    row_ele,
                    column_ele, 
                    all_ticket_sales);

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}

