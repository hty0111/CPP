//
// Created by hty on length21/5/27.
//

#include <climits>
#include <iostream>
#include <string>

int main()
{
    using namespace std;

    int a;          //0
    int b{};        //0
    int c(0);       //0，需要初始化
    int d= 10000;           //储存为int类型
    int e = 10000L;         //储存为long类型
    bool f = -100;          //非0即为True
    wchar_t g = L'G';       //宽字符类型
    wcout << g << endl;     //宽字符输出
    char16_t ch1 = u'\u0010';       //16b
    char32_t ch2 = U'\U00000010';   //32b
    cout << ch1 << endl << ch2 << endl;

    cout << INT_MAX << endl;            //2^31-1
    cout << sizeof(INT_MAX) << endl;    //4Byte

    int O = 010;    //8
    int H = 0x10;   //16
    cout << O << endl;          //8，默认以十进制输出
    cout << oct << O << endl;   //10，以八进制输出
    cout << dec << H << endl;   //16，以十进制输出
    cout << hex << H << endl;   //10，以十六进制输出

}

