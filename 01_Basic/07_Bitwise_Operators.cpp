#include<iostream>
using namespace std;
int main(){
    int a = 13, b = 5;
    cout <<"The value of a & b is " << (a & b) << endl;    //Bitwise AND
    cout <<"The value of a | b is " << (a | b) << endl;    //Bitwise OR
    cout <<"The value of a ^ b is " << (a ^ b) << endl;    //Bitwise XOR
    cout <<"The value of ~a is " << (~a) << endl;          //Bitwise Complement
    cout <<"The value of a >> 1 is " << (a >> 1) << endl;  //Shift Right Operator
    cout <<"The value of a << 1 is " << (a << 1) << endl;  //Shift Left Operator
}