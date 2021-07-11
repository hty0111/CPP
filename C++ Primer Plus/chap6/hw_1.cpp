//
// Created by hty on 2021/5/31.
//

/*遇到@停止输入并回显，数字除外，转换大小写*/
#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char ch;
    cin.get(ch);
    while( ch != '@' )
    {
        if( islower(ch) )
            ch = toupper(ch);
        else if( isupper(ch) )
            ch = tolower(ch);
        cout.put(ch);
        cin.get(ch);
    }
}