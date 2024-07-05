#include<iostream>
using namespace std;
int main(){
    int a = 100;
    int *b = &a;
    int **c = &b;
    int d = (*(&a));
    cout <<"Value of variable a is " << a << endl;
    cout <<"Addres of variable a is " << b << endl;
    cout <<"addres of pointer b is " << c << endl;
    cout <<"Value of pointer d is " << d << endl;
    return 0; 
}