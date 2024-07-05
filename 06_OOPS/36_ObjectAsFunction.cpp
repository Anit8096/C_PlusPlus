#include <iostream>
using namespace std;

class complex
{
    int a, b;

public:
    void setdata(int v1, int v2)
    {
        a = v1;
        b = v2;
    }

    void setdatabysum(complex c1, complex c2)
    {
        a = c1.a + c2.a;
        b = c1.b + c2.b;
    }

    void printnumber()
    {
        cout << "Your complex number is : " << a << " + i" << b << endl;
    }
};
int main()
{
    complex x1, x2, x3;

    x1.setdata(3, 9);
    x1.printnumber();

    x2.setdata(4, 7);
    x2.printnumber();

    x3.setdatabysum(x1, x2);
    x3.printnumber();

    return 0;
}