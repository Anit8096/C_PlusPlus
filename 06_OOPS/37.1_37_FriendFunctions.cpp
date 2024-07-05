#include<iostream>
using namespace std;

class complex; // forword declaration

class calculator{
    public:
        int add(int a, int b){
            return (a + b);
        }
        int sumreallexnumber(complex , complex);
        int sumcomplexnumber(complex , complex);
};

class complex {
    int a,b;
    /* " friend int calculator :: sumreallexnumber(complex, complex); " -> individual function as friend
     " friend int calculator :: sumcomplexnumber(complex, complex); "  -> individual function as friend   */   
    friend class calculator;  //full class as friend                                          
    public:
        void setdata(int n1, int n2){
            a = n1;
            b = n2;
        }
        void displaydata(){
            cout <<"Your complex number is : "<< a <<" + i"<< b <<endl;
        }
};

int calculator :: sumreallexnumber(complex c1, complex c2){
    return (c1.a + c2.a);
};

int calculator :: sumcomplexnumber(complex c1, complex c2){
    return (c1.b + c2.b);
};

int main(){
    complex o1, o2;
    o1.setdata(2,9);
    o1.displaydata();
    o2.setdata(3,8);
    o2.displaydata();
    calculator calk;
    int real = calk.sumreallexnumber(o1, o2);
    cout <<"The sum of real part of complex is : "<< real <<endl;
    int comp = calk.sumcomplexnumber(o1, o2);
    cout <<"The sum of real part of complex is : i"<< comp <<endl;
    return 0;
}