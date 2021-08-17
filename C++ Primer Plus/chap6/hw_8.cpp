//
// Created by hty on 2021/5/31.
//

#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main()
{
    ifstream readfile;
    readfile.open("hw_8.txt");
    if( !readfile.is_open() )
    {
        cout << "Fail to open file!\n";
        exit(EXIT_FAILURE);
    }
    char ch;
    int count = 1;
    while( !readfile.eof() )
    {
        readfile.get(ch);
        if (ch != '\r' && ch != '\n')
        {
            cout << ch << " count=" << count << endl;
            count++;
        }
    }
    readfile.close();
}