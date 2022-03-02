//
// Created by hty on 2021/9/5.
//

#include <iostream>
using namespace std;

int main()
{
    int ct = 0;
    char ch;
    cin.get(ch);
    while (ch != '$')
    {
        ct++;
        cin.get(ch);
    }
    cin.putback(ch);
    ch = cin.get();
    cout << ch << endl;     //验证下一个字符是否为$
}