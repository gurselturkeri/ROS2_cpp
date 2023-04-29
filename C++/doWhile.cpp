#include <iostream>


int main(){
    int x = 100;

    do{ // her halükarda do içine girecek
        std::cout << "GURSEL" << std::endl;
        x++;
    }
    while(x<10);
    std::cout << x << std::endl;
    
}