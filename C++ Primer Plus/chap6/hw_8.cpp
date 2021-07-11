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
    readfile.open("./hw_8.txt");
    if( !readfile.is_open() )
    {
        cout << "Fail to open file!\n";
        exit(EXIT_FAILURE);
    }
    char ch;
    readfile.get(ch);
    readfile.close();
}