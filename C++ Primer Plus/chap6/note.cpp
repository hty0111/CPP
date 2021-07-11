//
// Created by hty on 2021/5/31.
//

#include <iostream>
#include <ctype.h>

using namespace std;

int main()
{
    cout << isalpha('a') << endl;
    cout << isspace(' ') << endl;
    cout << isdigit('3') << endl;       //罗马数字，浮点数不行
    cout << ispunct(',') << endl;
    cout << islower('a') << endl;
    char ch;
    ch = tolower('A');
    ch = toupper('a');

}