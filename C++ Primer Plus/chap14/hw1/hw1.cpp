//
// Created by hty on 2021/8/30.
//

#include "wine.h"

int main()
{
    cout << "Enter name of wine: ";
    char lab[50];
    cin.getline(lab, 50);
    cout << "Enter number of years: ";
    int years;
    cin >> years;

    Wine holding(lab, years);
    holding.getBottles();
    holding.show();

    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    Wine more("Gushing Grape Red", YRS, y, b);
    more.show();
    cout << "Total bottles for " << more.label() << ": " << more.sum2() << endl;
}