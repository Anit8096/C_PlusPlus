#include<iostream>
using namespace std;

class complex {
    int a,b;
    public:
        
        void setnumber(int n1,int n2){
            a = n1;
            b = n2;
        }

        void printnumber(){
            cout <<"your complex number is : "<<a<<" + i" << b << endl;
        }
    
    friend complex Sumofcomplex(complex c1, complex c2);
};

complex Sumofcomplex(complex c1, complex c2){
    complex c3;
    c3.setnumber((c1.a + c2.a),(c1.b + c2.b));
    return c3;
}

int main(){
    complex c1, c2, sum;
    c1.setnumber(1,4);
    c1.printnumber();
    
    c2.setnumber(5,8);
    c2.printnumber();
    
    sum = Sumofcomplex(c1, c2);
    sum.printnumber();

    return 0;
}