#include<iostream>
using namespace std;
int factorial(long int n){
    if (n == 1 || n == 0){
        return 1; 
    }
    return n * factorial(n-1);
}
int main(){
    long int num;
    cout << "Enter a +ve Number : ";
    cin >> num;
    cout << "Factorial of the given number is : " << factorial(num) << endl;
}