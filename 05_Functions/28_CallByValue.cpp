#include<iostream>
using namespace std;
void Swap(int a, int b){
    int temp = a;
    a = b;
    b = temp;
}
int main(){                 // method in C++ to pass the values to the function arguments. 
    int num1 = 3, num2 = 7; // In the case of call by value the copies of actual parameters 
    cout << num1 << num2;   // are sent to the formal parameter, which means that if we change 
    Swap(num1, num2);       // the values inside the function that will not affect the actual values.
    cout << num1 << num2;
}