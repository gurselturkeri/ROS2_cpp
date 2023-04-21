#include <iostream>

using namespace std;

int main(){
    for (int i = 0; i < 10; i++)
    {
        if(i==4)
       // break;       // 4'e gelince döngüyü kıracak
       continue;       // 4'e gelince atladı direkt 5'e geçti
        cout << i << endl;
    }
    
}