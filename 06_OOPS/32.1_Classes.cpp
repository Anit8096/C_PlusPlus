#include<iostream>
using namespace std;
class XYZ{
    private:
        int a,b,c;
    
    public:
        int d,e;
    
    void setdata(int a1, int b1, int c1);
    
    void getdata(){
        cout << "Value of a is " << a << endl;
        cout << "Value of b is " << b << endl;
        cout << "Value of c is " << c << endl;
        cout << "Value of d is " << d << endl;
        cout << "Value of e is " << e << endl;
    }
};

void XYZ :: setdata(int a1, int b1 ,int c1){
    a = a1;
    b = b1;
    c = c1;
};
int main(){
    XYZ Anit;
    // Anit.a = 112 ->error as this is private
    Anit.d = 123;
    Anit.e = 56;
    Anit.setdata(234,789,23);
    Anit.getdata(); 
}