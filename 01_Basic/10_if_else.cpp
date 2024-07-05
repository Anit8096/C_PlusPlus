#include<iostream>
using namespace std;
int main(){
    int age;
    cout << "Enter your Age" << endl;
    cin >> age;
    if (age>18){
        cout << "you are eligible to vote" << endl;
    }
    else{
        cout << "you are ineligible to vote" << endl;
    }
}