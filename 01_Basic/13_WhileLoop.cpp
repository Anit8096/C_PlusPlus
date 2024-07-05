#include<iostream>
using namespace std;
int main(){
    int n,i;
    cout << "enter maximum number of terms : ";
    cin >> n;
    cout << "enter starting term : ";
    cin >> i;
    while (i<=n){
        cout << i <<" ";
        i++;
    }
}