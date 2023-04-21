#include <iostream>
//using namespace std;

int main(){

    int num1;
    int num2;
    int num3;

    std::cout << "enter the first number: ";
    std::cin >> num1;
    std::cout << "enter the second number: ";
    std::cin >> num2;
    std::cout << "enter the third number: ";
    std::cin >> num3;

    if (num1 > num2){  // when biggest val. is num1
        
        if (num2 > num3){
            std::cout << "num1 > num2 > num3" << std::endl;
        }
        if (num3>num2){
            std::cout << "num1 > num3 > num2" << std::endl;
        }
        else{
            std::cout << "num1 > num2 = num3" << std::endl;
        }
    }

    if (num2 > num1){  // when biggest val. is num2
        if(num1 > num3){
            std::cout << "num2 > num1 > num3";
        }
        if(num3 > num1){
            std::cout << "num2 > num3 > num1";
        }
        else{
            std::cout << "num2 > num1 = num3";
        }
    }
    
    if (num3 > num2){
        if(num2 > num1){
            std::cout << "num3 > num2 > num1";
        }
        if(num1 > num2){
            std::cout << "num3 > num1 > num2";
        }
        else {
            std::cout << "num3 > num2 = num1";
        }

    }

    else{
        std::cout << "num1 = num2 = num3";
    }

}