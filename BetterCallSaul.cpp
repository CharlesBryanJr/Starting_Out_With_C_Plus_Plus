// Create a C++ text adventure with the storyline of your choosing. 
// The program should use your knowledge of C++ conditionals, logic, and loops.
// Story: Ending to Better Call Saul

#include <iostream>

double ending;

int main() {

  std::cout << "This story is based on the possible ending of season 6 of Better Call Saul." << "\n";

  // beginning 
  std::cout << "Better Call Saul is an American crime and legal drama television series created by Vince Gilligan and Peter Gould." << "\n";
  std::cout << "Part of the Breaking Bad franchise, it is a spin-off, prequel and occasional sequel to Gilligan's previous series, Breaking Bad." << "\n"; 

  std::cout << "At the start of the series, Jimmy struggles financially while he mostly works on court-appointed cases as a public defender." << "\n";

  std::cout << "Now, in season 6, Jimmy has grown into a con artist that becomes increasingly involved in the city's criminal underworld." << "\n";
  std::cout << "As Jimmy slowly loses his morality along the way, he also loses his birth name and enbraces the new person he has become, also known as Saul Goodman."<< "\n";

  std::cout << "As the finial season come to an end. Please choice a possible ending."<< "\n";
  std::cout << "If you were Jimmy, would you, confess to your crimes? quit while your ahead? or double down?" << "\n";
  std::cout << "Enter 1, if you would confess to your crimes." << "\n";
  std::cout << "Enter 2, if you would quit while you're ahead." << "\n";
  std::cout << "Enter 3, if you would continue being a criminal." << "\n";
  std::cin >> ending;

  while (ending < 1 || ending > 3 ){
    std::cout << "Try again. Please enter 1, 2, or 3. " << "\n";
    std::cout << "Enter 1, if you would confess to your crimes." << "\n";
    std::cout << "Enter 2, if you would quit while you're ahead." << "\n";
    std::cout << "Enter 3, if you would continue being a criminal." << "\n";
    std::cin >> ending;
  }

  while( ending != 1.2 )

    // ending 1
    if(ending == 1) {
        while (ending != 1.2) {
          std::cout << "You picked ending 1, which means you will confess to your crimes." << "\n";
          std::cout << "Enter 1.1, if you would ask for a reduced sentence." << "\n";
          std::cout << "Enter 1.2, if you would ask for the fullest extent of the law." << "\n";
          std::cin >> ending;
          std::cout << "\n";
          std::cout << "Try again." << "\n";
          std::cout << "Enter 1.1, if you would ask for a reduced sentence." << "\n";
          std::cout << "Enter 1.2, if you would ask for the fullest extent of the law." << "\n";
        }
    }

    // ending 2
    else if(ending == 2) {
      std::cout << "You picked ending 2, which means you will quit while you're ahead." << "\n";
      std::cout << "Enter 2.1, if you would quit practicing law" << "\n";
      std::cout << "Enter 2.2, if you would continue practicing law." << "\n";
      std::cin >> ending;
    }

    // ending 3
    else if(ending == 3) {
      std::cout << "You picked ending 3, which means you will continue being a criminal." << "\n";
      std::cout << "Enter 3.1, if you would continue as you are." << "\n";
      std::cout << "Enter 3.2, if you would double down." << "\n";
      std::cin >> ending;
    }
    else {
      std::cout << "Try again. Please enter 1, 2, or 3. " << "\n";
      std::cout << "Enter 1, if you would confess to your crimes." << "\n";
      std::cout << "Enter 2, if you would quit while you're ahead." << "\n";
      std::cout << "Enter 3, if you would continue being a criminal." << "\n";
      std::cin >> ending;
    }
  std::cout << "The End." << "\n";
  return 0;
}




