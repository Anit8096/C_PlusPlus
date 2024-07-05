#include <iostream>
using namespace std;
 
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
} 
int main(){
    int x = 4, y = 7;                                                              //A call by the pointer is a method in C++ to pass the values to the function
    cout << "The value of x is " << x << " and the value of y is " << y << endl;   //arguments. In the case of call by pointer, the address of actual parameters is
    swap(&x, &y);                                                                  //sent to the formal parameter, which means that if we change the values inside 
    cout << "The value of x is " << x << " and the value of y is " << y << endl;   //the function that will affect the actual values.
}