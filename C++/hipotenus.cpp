#include <iostream>
#include <math.h>

using namespace std;

int main(){

int a,b,c;
float plus_squares;

cout << "a: ";
cin >> a;

cout << "b: ";
cin >> b;

plus_squares = a*a + b*b;

cout << "hipotenus: " << sqrt(plus_squares) << endl;


}