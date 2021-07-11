#include <iostream>

using namespace std;

union info
{
    unsigned long birthday;
    unsigned short age;
    char * pet;
};

int main()
{
    info hty;

    //赋值
    hty.birthday = 20010111;
    cout << hty.birthday << endl;
    //重新赋值
    hty.pet = (char*)"dog";
    cout << hty.pet << endl;
    //覆盖原来的数据
    cout << hty.birthday << endl;
    //变成字符串的首地址
}

/*
可以容纳多种不同类型的值，但每次只能存储一种的某一个
*/