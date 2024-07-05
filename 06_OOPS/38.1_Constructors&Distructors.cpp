#include <iostream>
#include <cmath>
using namespace std;

class calculator;

class point
{
    int x, y;
    friend class calculator;

public:
    point()
    {
        int a, b;
        cout << "Enter X Co-ordinates : ";
        cin >> a;
        cout << "Enter Y Co-ordinates : ";
        cin >> b;
        x = a;
        y = b;
    }
};

class calculator
{
public:
    int DisplayDistance(point a, point b)
    {
        float p = pow((a.x - b.x), 2);
        float q = pow((a.y - b.y), 2);
        float dis = sqrt(p + q);
        cout << "Distance b/w the two points is - " << dis;
        return dis;
    }
};

int main()
{
    point a, b;
    calculator calk;
    calk.DisplayDistance(a, b);
    return 0;
}