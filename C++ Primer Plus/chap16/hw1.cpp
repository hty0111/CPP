//
// Created by hty on 2021/9/3.
//

/*判断简单回文*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool judge(const string & str)
{
    string temp = str;
    reverse(temp.begin(), temp.end());
    return temp == str;
}

int main()
{
    cout << "Enter a string('q' to quit): ";
    string str;
    getline(cin, str);
    while (str != "q")
    {
        if (judge(str))
            cout << "Yes\n";
        else
            cout << "No\n";
        cout << "Enter a string('q' to quit): ";
        getline(cin, str);
    }
}