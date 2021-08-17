//
// Created by hty on 2021/8/11.
//

#include <iostream>
using namespace std;

extern "C" void f(int i);   //使用C语言链接性

char buffer[20];

int main()
{
    volatile int i; //硬件可能修改变量的值，改善编译器的优化能力
    struct info{string name; mutable int age;}; //即使结构或类为const，其某个成员也可被修改
    info hty = {"HTY", 20};
    hty.age ++; //可被修改

    double *p = new (buffer) double[10];    //将double数组放在buffer中
    cout << (void *)buffer << endl << p << endl;

}