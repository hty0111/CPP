//
// Created by hty on 2021/8/17.
//

#include "string0.h"
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    String zxa;         //默认构造器
    String hty("hty");  //非默认构造器
    zxa = "zxa";        //重载"="
    hty.selfUpper();    //类函数，自身大写
    String cwr = Lower(hty);    //复制构造器，友元函数返回大写
    String mhy = hty + zxa;     //重载"+"，重载"="
    cout << zxa << endl << hty << endl << mhy << endl << cwr << endl;
    cout << "Now " << hty.howMany() << " strings\n";
    char ch = 'z';
    int count = charInString(zxa, ch);
    cout << count << " * \"" << ch << "\" in " << zxa << endl;
}