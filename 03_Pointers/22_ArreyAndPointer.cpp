#include<iostream>
using namespace std;
int main(){
    int marks[3]={80,89,79};
    int *p = marks;
    cout << "value of marks[0] is " << *p << endl;
    cout << "value of marks[1] is " << *(p + 1) << endl;
    cout << "value of marks[2] is " << *(p + 2) << endl;
}
