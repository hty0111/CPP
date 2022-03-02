//
// Created by hty on 2021/8/30.
//

#include "wine.h"

Wine::Wine(const char* n, int y, const int yr[], const int bot[]) : name(n), yearNum(y)
{
    ArrayInt i1(yr, y), i2(bot, y);
    pa = make_pair(i1, i2);
}

void Wine::getBottles()
{
    pa.first.resize(yearNum);
    pa.second.resize(yearNum);
    cout << "Enter " << name << " date for " << yearNum << " year(s):\n";
    for (int i = 0; i < yearNum; i++)
    {
        cout << "Enter year: ";
        cin >> pa.first[i];
        cout << "Enter bottles for that year: ";
        cin >> pa.second[i];
    }
}

int Wine::sum2()
{
    return pa.second.sum();
}

void Wine::show()
{
    cout << "Wine: " << name << endl;
    cout << "\tYear\tBottles\n";
    for (int i = 0; i < yearNum; i++)
    {
        cout << "\t" << pa.first[i] << "\t" << pa.second[i] << endl;
    }
}