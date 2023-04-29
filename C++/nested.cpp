#include <iostream>

using namespace std;

int main(){

    for (int i=0;i<10;i++){         // i bir değer artınca içindeki loop tüm işlemini bitirir.
        for(int j=0;j<10;j++){
                cout << i << " " << j << ",";                              // 3 boyutlu
            /* for(int k=0;k<10;k++){
                cout << i << " " << j << " " << k << ",";
            } */
        }
        cout << endl;
    }




}