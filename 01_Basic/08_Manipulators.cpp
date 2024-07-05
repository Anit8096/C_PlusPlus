#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    float PI = 3.14;
    int num = 100;
    cout << "New Line" << endl;
    cout << setw(30) << "Output" << endl;
    cout << setprecision(20) << PI << endl;
    cout << setbase(16) << num << endl;     //set bas to 16
}