//
// Created by hty on 2021/5/30.
//

#include <iostream>

using namespace std;

int main()
{
    for( int x : {0, 1, 2, 3} )
        cout << x << " ";

    char ch;
    int count = 0;
    cin.get(ch);
    while( cin.fail() == false )        //CRTL+Z
    {
        cout << ch;
        cin.get(ch);        //可以读入回车
        count++;
    }
    cout << endl << count << "characters read.\n";
}