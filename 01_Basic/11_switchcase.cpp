#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    int a,b;
    char ope;
    cout << "Select one Operation to perform (+,-,*,/,%)" << endl;
    cin >> ope;
    cout << "Enter two values : " << endl;
    cin >> a >> b;
    switch (ope)
    {
    case '+':
        cout << "answer is : " << a+b << endl;
        break;
    case '-':
        cout << "answer is : " << a-b << endl;
        break;
    case '*':
        cout << "answer is : " << a*b << endl;
        break;
    case '/':
        cout << "answer is : " << a/b << endl;
        break;
    case '%':
        cout << "answer is : " << a%b << endl;
        break;
    default:
        cout << "Please select a valid operation" << endl;
        break;
    }
}