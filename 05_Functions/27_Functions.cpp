#include<iostream>
using namespace std;
int sum(int a, int b){
   int Sum = a + b;
   cout << "Sum = " << Sum;
   return Sum;
}
int main(){
    int num1 = 1, num2 = 3;
    sum(num1,num2);
}