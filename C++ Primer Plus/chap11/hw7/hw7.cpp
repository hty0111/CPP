//
// Created by hty on 2021/8/15.
//

#include "complex0.h"

int main()
{
    using namespace std;
    Complex a, b;
    double n;
    cout << "Input one complex: ";
    cin >> a;
    cout << "Input another complex:";
    cin >> b;
    cout << "Input times: ";
    cin >> n;
    cout << "a + b: " << a + b << endl;
    cout << "a - b: " << a - b << endl;
    cout << "a * b: " << a * b << endl;
    cout << "a * n: " << a * n << endl;
    cout << "n * a: " << n * a << endl;
    cout << "~a: " << ~a << endl;
}