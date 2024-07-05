#include<iostream>
using namespace std;

class c2;

class c1 {
    int val;
    friend void Swap(c1 &, c2 &);
    public:
        void setvalue(int a){
            val = a;
        }

        void displayvalue() {
            cout << val <<endl;
        }
};

class c2 {
    int val2;
    friend void Swap(c1 &, c2 &);
    public:
        void setvalue(int b){
            val2 = b;
        }

        void displayvalue() {
            cout << val2 <<endl;
        }
};

void Swap(c1 &p, c2 &q){
    int w = p.val;
    p.val = q.val2;
    q.val2 = w;

}

int main(){
    c1 oc1;
    c2 oc2;

    oc1.setvalue(78);
    oc2.setvalue(67);

    Swap(oc1, oc2);
    cout <<"Value of c1 after swap is : ";
    oc1.displayvalue();

    cout <<"Value of c2 after swap is : ";
    oc2.displayvalue();

    return 0;
}