#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout << "enter maximum number of terms : ";
    cin >> n;
    cout << "enter starting term : ";
    cin >> i;
    do{
        cout << i <<" ";
        i++;
    } while (i<=n);
}