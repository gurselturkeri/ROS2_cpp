
/* 
Ekrana 4 kolon şeklinde aşağıdaki serileri bastırınız:

    Kolonda: 1'den 100'e kadar olan 15'in katları
    Kolonda: 1'den 30'a kadar olan 5'in katları
    Kolonda 100'den 50'ye kadar olan 10'un katları
    Kolonda 2'den 64'e kadar olan 2'nin üstleri */

#include <iostream>
using namespace std;    

int main(){
int i,j,k,l;
i=15;
j=5;
k=100;
l=2;

while(i<100){
    cout << i << " " << j << " "<< k << " " << l << endl;

    i +=15;
    j += 5;
    k -= 10;
    l *= 2;
}
}