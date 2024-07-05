#include<iostream>
using namespace std;

class Employee{
private:
    float Salery;
public:
    static int count;
    string eNAME;

    void setname(string NAME){
        eNAME=NAME;
        count++;
    }

    static int getcount(){
        return count;
    }
};

int Employee::count = 0;

int main(){
    Employee Anit;
    Anit.setname("ANIT BANI");
    cout << Employee::getcount() << endl;
}