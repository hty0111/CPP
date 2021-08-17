//
// Created by hty on 2021/8/9.
//

#include <iostream>
using namespace std;

struct name{ string str; }my_name{"hty"};
//传引用方式修改结构体
void change_name(name & temp)
{
    temp.str = "zxa";
}

int main()
{
    cout << my_name.str << endl;
    change_name(my_name);
    cout << my_name.str << endl;
}