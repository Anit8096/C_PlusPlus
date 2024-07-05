#include<iostream>
using namespace std;

class Emoloyee{
    int ID;
    string Name;
    static int count;
    public:
        void setdata(void){
            cout <<"Enter employee ID : ";
            cin >> ID;
            cout <<"Enter employee Name : ";
            getline(cin >> ws, Name);
            count++;
        }
        void Displaydata(void){
            cout<<count<<"."<<Name<<" Id number "<<ID<<" report to the office."<<endl;
        }
        static void getcount(void){
            cout <<"Value of count is : "<<count<<endl;
        }
};

int Emoloyee::count;

int main(){
    Emoloyee Anit;
    Anit.setdata();
    Anit.Displaydata();
    Emoloyee::getcount();
    return 0;
}