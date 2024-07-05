#include<iostream>
using namespace std;

union biodata{
    string name;
    int age;
    string DOB;
} anit, anav ;

int main(){

    cout << "Your Name : ";
    getline(cin >> ws, anit.name);

    cout << "your Age  : ";
    cin >> anit.age;

    cout << "Hello " << anit.name << endl;
    cout << "You Are " << anit.age << " years old" << endl;
}