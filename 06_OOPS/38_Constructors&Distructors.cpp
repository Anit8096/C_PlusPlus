#include<iostream>
using namespace std;

class complex {
    
    // Creating a constructor :-
    // 1.constructo ris a special number function with the same name as the class.
    // 2.it is used to initialize the object of it class.
    // 3.It is automatically invoked whenever an object is created.

    int a,b;

    public:
        complex(void){                  //constructor declaration   //this is a default constructor as it takes no arguments
            cout <<"Enter 2 values : ";
            cin >> a >> b;        
        };

        void Displaynumber(){
            cout <<"Coplex umber is : " << a <<" + i" << b <<endl;
        };
};

int main(){
    complex c1;
    c1.Displaynumber();
    return 0;    
}