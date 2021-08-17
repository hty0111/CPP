//
// Created by hty on 2021/8/9.
//

#include <iostream>
#include <array>
#include <string>
using namespace std;

const int Seasons = 4;
void fill(array<double, Seasons> * p)
{
    cout << "输入每个季度的开销：\n";
    for (int i = 0; i < Seasons; i++)
    {
        cin >> (*p)[i];
    }
}

void show(array<string, Seasons> name, array<double, Seasons> exp)
{
    for (int i = 0; i < Seasons; i++)
    {
        cout << name[i] << ": " << exp[i] << endl;
    }
}

int main()
{
    array<double, Seasons> expenses;
    array<string, Seasons> season_name =
            {"Spring", "Summer", "Autumn", "Winter"};
    fill(&expenses);
    show(season_name, expenses);
}
