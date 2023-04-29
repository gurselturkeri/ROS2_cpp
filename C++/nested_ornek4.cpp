#include <iostream>

using namespace std;

int main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4-(i+1);j++){ // boşluklar
            cout << " ";
        }
        for(int k=0;k<i+1;k++){ // yildizlar
            cout << "*";
        }
       cout << endl;
}
}