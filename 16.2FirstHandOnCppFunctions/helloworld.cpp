#include <iostream>

//Function that takes a single parameter, and doesn't give back the result explicitly
void enter_bar(unsigned int age){
    if(age>18){
        std::cout << "You're " << age << " years old. Please proced." << "\n"
    }
    else{
        std::cout << "You're not 21, entry not allowed." << "\n";
    }
    return;
}

//Function that takes multiple parameters and returns the result of the computation
int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}

//Function that doesnt' take parameters and returns nothing
void say_hello(){
    std::cout << "Hello there" << std::endl;
    return;
}

//Function that takes no parameters and return something
int lucky_number(){
    return 99;
}

int main(){
    //Calling enter_bar
    enter_bar(33); 
    enter_bar(13);

    for(unsigned int it{0}; it<33; ++it){
        enter_bar(it);
    }
    std::cout << "" << "\n";
    

    int x{22};
    int y{44};
    int result = max(x,y);
    std::cout << "max : " << result << std::endl;
    int result1{max(x,y)};
    std::cout << "max : " << result << std::endl;
    std::cout << "" << "\n";

    return 0;
}

int main(){
    int v1;
    std::cout << "Enter an integer: " << "\n";
    std::cin >> v1;
    
    int v2;
    std::cout << "Enter another integer: " << "\n";
    std::cin >> v2;

    r = v2
    r = v1+v2;

}