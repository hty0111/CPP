//
// Created by hty on 2021/8/9.
//

#include <iostream>
using namespace std;

double add(double a, double b)
{
    return a + b;
}

double sub(double a, double b)
{
    return a - b;
}

void process(double x, double y, double (*fp)(double, double))
{
    cout << (*fp)(x, y) << endl;
}

int main()
{
    double x, y;
    cout << "x, y: ";
    cin >> x; cin >> y;
    process(x, y, add);
    process(x, y, sub);
}