/*

****
 ***
  **
   *

*/
#include <iostream>
using namespace std;

 int main(){

for(int j = 1; j<=4;j++){

        for(int i = 1; i<j; i++){
                cout << " ";   // öne boşluk koyduk
        }

        for(int k = 1;k<=4-j+1;k++){
                cout << "*";
        }

cout << endl;

}



 }