#include<iostream>
using namespace std;

class Student{
public:
    int eID;
    string NAME;
    int Age;
    
    void printNAME();
};

void Student::printNAME(){
    cout << NAME << endl;
}

int main(){
    Student Student1;
    cout << "Enter Your Name : ";
    getline(cin >> ws, Student1.NAME);
    cout << "Enter Your eID : ";
    cin >> Student1.eID;
    cout << "Enter Your Age : ";
    cin >> Student1.Age;
    cout << "Student with eID - " << Student1.eID << " is " << Student1.NAME << " of Age - " << Student1.Age << endl;
}