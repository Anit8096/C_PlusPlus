#include <iostream>
using namespace std;

class Employee
{
    int ID;
    string Name;
    static int count;

public:
    void setdata(void)
    {
        cout << "Enter employee ID : ";
        cin >> ID;
        cout << "Enter employee Name : ";
        getline(cin >> ws, Name);
    }
    void Displaydata(void)
    {
        cout << "Welcome " << Name << " ID Number " << ID << endl;
    }
};

int main()
{
    int num;
    string akashay;
    Employee MANiT[100];
    cout << "Enter number of employee's for data-entry : ";
    cin >> num;
    for (int i = 0; i <= num; i++)
    {
        MANiT[i].setdata();
        MANiT[i].Displaydata();
    }
}