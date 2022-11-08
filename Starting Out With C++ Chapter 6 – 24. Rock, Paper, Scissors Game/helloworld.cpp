/*
24. Rock, Paper, Scissors Game
Write a program that lets the user play the game of Rock, Paper, Scissors against the computer. 

The program should work as follows.

1. When the program begins, a random number in the range of 1 through 3 is generated. 
If the number is 1, then the computer has chosen rock. 
If the number is 2, then the computer has chosen paper. 
If the number is 3, then the computer has chosen scissors. 
(Don’t display the computer’s choice yet.)

2. The user enters his or her choice of “rock”, “paper”, or “scissors” at the keyboard.
(You can use a menu if you prefer.)

3. The computer’s choice is displayed.

4. A winner is selected according to the following rules:

• If one player chooses rock and the other player chooses scissors, then rock wins.
(The rock smashes the scissors.)

• If one player chooses scissors and the other player chooses paper, then scissors wins. 
(Scissors cuts paper.)

• If one player chooses paper and the other player chooses rock, then paper wins.
(Paper wraps rock.)

• If both players make the same choice, the game must be played again to determine the winner.

Be sure to divide the program into functions that perform each major task.
*/

#include <iostream>

char inputValidation_y_or_n(char &letter)
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

int inputValidation_user_choice(int &user_choice)
{
    while( !(std::cin >> user_choice) || (user_choice<1) || (user_choice>3) )
    {
        std::cout << " " << "\n";
        std::cout << "Input Validation : must be 1, 2 or 3." << "\n";
        std::cout << "For rock, input 1" << "\n";  
        std::cout << "For paper, input 2" << "\n";  
        std::cout << "For scissors, input 3" << "\n"; 
        std::cout << "User Choice : ";
        std::cin.clear();
    }
    return user_choice;
}

void input_userChoice(int &user_choice)
{
    std::cout << "User, it's your turn." << "\n";
    std::cout << "Choose either rock, paper, or sissors." << "\n";
    std::cout << "For rock, input 1" << "\n";  
    std::cout << "For paper, input 2" << "\n";  
    std::cout << "For scissors, input 3" << "\n";   
    std::cout << "Choice : ";
        inputValidation_user_choice(user_choice);
    std::cout << " " << "\n";
}

void computer_choice_is_user_choice(int computer_choice, int user_choice)
{
    if( computer_choice == user_choice )
    {
        std::cout << "The computer_choice was : " << computer_choice << "\n";
        std::cout << "The user_choice was : " << user_choice << "\n";
        std::cout << "both players made the same choice, the game must be played again to determine the winner." << "\n";
    }
}

void computer_choice_is_rock(int &computer_choice, int &user_choice)
{
    if(computer_choice == 1)
    {
        if(user_choice == 2) 
        {
            std::cout << "The computer_choice was : " << computer_choice << ", rock" << "\n";
            std::cout << "The user_choice was : " << user_choice << ", paper" << "\n";
            std::cout << "(Paper wraps rock.)" << "\n";
            std::cout << "---User wins!---" << "\n";
        }
        else if (user_choice == 3)
        {
            std::cout << "The computer_choice was : " << computer_choice << ", rock" << "\n";
            std::cout << "The user_choice was : " << user_choice << ", scissors" << "\n";
            std::cout << "(The rock smashes the scissors.)" << "\n";
            std::cout << "---Computer wins!---" << "\n";
        }
    }
}

void computer_choice_is_paper(int &computer_choice, int &user_choice)
{
    if(computer_choice == 2)
    {
        if(user_choice == 1)
        {
            std::cout << "The computer_choice was : " << computer_choice << ", paper" << "\n";
            std::cout << "The user_choice was : " << user_choice << ", rock" << "\n";
            std::cout << "(Paper wraps rock.)" << "\n";
            std::cout << "---Computer wins!---" << "\n";
        }
        else if (user_choice == 3)
        {
            std::cout << "The computer_choice was : " << computer_choice << ", paper" << "\n";
            std::cout << "The user_choice was : " << user_choice << ", scissors" << "\n";
            std::cout << "(Scissors cuts paper.)" << "\n";
            std::cout << "---User wins!---" << "\n";
        }
    }
}

void computer_choice_is_sissor(int &computer_choice, int &user_choice)
{
    if(computer_choice == 3)
    {
        if(user_choice == 1)
        {
            std::cout << "The computer_choice was : " << computer_choice << ", sissors" << "\n";
            std::cout << "The user_choice was : " << user_choice << ", rock" << "\n";
            std::cout << "(The rock smashes the scissors.)" << "\n";
            std::cout << "---User wins!---" << "\n";
        }
        else if (user_choice == 2)
        {
            std::cout << "The computer_choice was : " << computer_choice << ", sissors" << "\n";
            std::cout << "The user_choice was : " << user_choice << ", paper" << "\n";
            std::cout << "(Scissors cuts paper.)" << "\n";
            std::cout << "---Computer wins!---" << "\n";
        }
    }
}

int main()
{
	char letter;
    int user_choice;

	while(letter != 'n')
	{
        int computer_choice{rand()%3+1};

        input_userChoice(user_choice);
        computer_choice_is_user_choice(computer_choice, user_choice);
        computer_choice_is_rock(computer_choice, user_choice);
        computer_choice_is_paper(computer_choice, user_choice);
        computer_choice_is_sissor(computer_choice, user_choice);

		std::cout << " " << "\n";			
		std::cout << "Would you like to run the program again? (y/n) : "; 
		inputValidation_y_or_n(letter);			
		std::cout << " " << "\n";
    }
	
	return 0;
}