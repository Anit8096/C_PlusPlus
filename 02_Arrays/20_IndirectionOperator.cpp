#include<iostream>
using namespace std;
int main(){
    int a = 10;
    cout << "Value of variable a stored at addres " << &a << " is " << (*(&a)) << endl;

}