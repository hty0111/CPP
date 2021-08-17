//
// Created by hty on 2021/8/9.
//

#include <iostream>

int main()
{
    const int *p;   //无法通过指针p修改值
    int * const p;  //无法修改指针的值

    std::array<int, 4> my_array;    //四个int类型的变量

    func1(func3);   //func3作为参数传入
    func2(func2()); //func2的值作为参数传入
}

