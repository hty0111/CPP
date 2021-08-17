//
// Created by hty on 2021/8/11.
//

#include <iostream>
using namespace std;

struct chaff
{
    char dross[20];
    int slag;
};

char buffer[512];
void input(chaff *pt);
void show(chaff *pt);

int main()
{
    chaff *p = new (buffer) chaff[2];
    cout << p[0].slag << endl;
    input(p);
    show(p);
}

void input(chaff *pt)
{
    cout << "输入两个字符串:\n";
    cin >> pt[0].dross;
    cin >> pt[1].dross;
}

void show(chaff *pt)
{
    cout << pt[0].dross << endl;
    cout << pt[1].dross << endl;
}