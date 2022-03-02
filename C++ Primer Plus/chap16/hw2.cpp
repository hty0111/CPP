//
// Created by hty on 2021/9/3.
//

/*处理带符号的回文, 不考虑大小写*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

bool judge(const string & str)
{
    string temp;
    for (int i = 0; i < str.size(); i++)
    {
        if (isalpha(str[i]))
            temp.push_back(tolower(str[i]));
    }
    string org = temp;
    reverse(temp.begin(), temp.end());
    return temp == org;
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