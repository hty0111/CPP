//
// Created by hty on 2021/8/10.
//

#include <iostream>
using namespace std;

void str_to_upper(string &str);

int main()
{
    string str;
    cout << "输入小写字符串：";
    cin >> str;
    while (str != "q")
    {
        str_to_upper(str);
        cout << str << endl;
        cout << "输入小写字符串：";
        cin >> str;
    }
}

void str_to_upper(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
    }
}