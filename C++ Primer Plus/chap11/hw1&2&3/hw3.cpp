//
// Created by hty on 2021/8/15.
//

#include "vector.h"
#include <cstdlib>
#include <ctime>

int main()
{
    using namespace std;
    srand(time(0));

    double step, target, degree;
    cout << "Input step: ";
    cin >> step;
    cout << "Input target: ";
    cin >> target;
    const int MaxLoop = 1e6;
    int times = 1;
    Vector result, randomWalker;

    for (times = 0; times < MaxLoop; times++)
    {
        degree = rand() % 360;
        randomWalker = Vector(step, degree, Vector::Polar);
        result = result + randomWalker;
        if (result.ret_mag() >= target)
            break;
    }
    cout << "times: " << times << endl;
    cout << result << endl;

    return 0;
}