//
// Created by hty on 2021/5/31.
//

#include <iostream>

using namespace std;

const int Strsize = 20;

struct bop
{
    char name[Strsize];
    char title[Strsize];
    char alias[Strsize];
    int preference;         //0 or 1 or 2
};

void print_info(bop * st, int pre)
{
    switch (pre)
    {
        case 1: cout << st->name << endl; break;
        case 2: cout << st->title << endl; break;
        case 3: cout << st->alias << endl; break;
    }
}

int main()
{
    bop hty = {"HTY", "diligent", "hh", 1};
    bop zxa = {"ZXA", "clever", "zz", 2};
    bop mhy = {"HTY", "genius", "mm", 3};
    cout << "a. display by name\tb. display by title\n";
    cout << "c. display by alias\td. display by references\nq. quit\n";
    cout << "Enter your choice:";
    char ch;
    cin >> ch;
    while( ch != 'q' )
    {
        switch (ch) {
            case 'a':
                print_info(&hty, 1);
                print_info(&zxa, 1);
                print_info(&mhy, 1);
                break;
            case 'b':
                print_info(&hty, 2);
                print_info(&zxa, 2);
                print_info(&mhy, 2);
                break;
            case 'c':
                print_info(&hty, 3);
                print_info(&zxa, 3);
                print_info(&mhy, 3);
                break;
            case 'd':
                print_info(&hty, hty.preference);
                print_info(&zxa, zxa.preference);
                print_info(&mhy, mhy.preference);
                break;
        }
        cout << "Enter your choice:";
        cin >> ch;
    }
}

