//
// Created by hty on 2021/8/15.
//

#include <iostream>

class Class{
    const int INT;
    Class(const Class &);       //复制构造函数的声明，默认的复制构造函数逐个复制非静态成员
    Class(int con) : INT(con);  //构造函数可以用初始化列表语法，非静态const和引用必须使用这种语法
};
Class::Class(int con) : INT(con){}     //给常量赋值

int main()
{
    Class a;
    Class b = a; // <=> Class b = Class(a); 调用了复制构造函数

}