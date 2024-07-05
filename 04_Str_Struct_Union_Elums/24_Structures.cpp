#include<iostream>
using namespace std;
struct Biodata{
    string name;
    int age;
    string DOB;
}Anit,Anav;
int main(){
    struct Biodata Papa;
    
    cout << "Your Name : ";
    getline(cin >> ws, Anit.name);

    cout << "your Age  : ";
    cin >> Anit.age;

    cout << "Hello " << Anit.name << endl;
    cout << "You Are " << Anit.age << " years old" << endl;

    int arr[6];
}