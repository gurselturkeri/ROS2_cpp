#include <iostream>

int main(){

    int boyut;
    std::cout << "Boyut giriniz: ";
    std::cin >> boyut;

    for(int i = 0;i<boyut;i++){
        for (int j = 0; j<boyut; j++)
        {
            if(i+j == boyut-1)
            std::cout << "1";
            else
            std::cout << "0";
        }
        std::cout << std::endl;
    }

}




