//
// Created by hty on 2021/8/15.
//

#include <iostream>

class Class;

int main()
{
    Class a;
    Class b = a; // <=> Class b = Class(a);
    Class(const Class &);   //复制构造函数的声明，默认的复制构造函数逐个复制非静态成员
}