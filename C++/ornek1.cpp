#include <iostream>
using namespace std;

int main(){

    float score;
 cout << "Enter the exam score: " << endl;
 cin >> score;

 if (score <50 && score >0){
    cout << "F";
 }
 else if(score >= 50 && score<70){
    cout << "C";
 }
 else if(score<90 && score>=70){
    cout << "B";
 }
 else if (score <= 100 && score >=90){
    cout << "A";
 }
 else {
    cout << "your exam score should be between in 0-100";
 }





}