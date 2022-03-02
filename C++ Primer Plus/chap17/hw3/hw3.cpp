//
// Created by hty on 2021/9/5.
//

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[])
{
    //向源文件写入内容
    ofstream fout(argv[1], ios_base::out);
    if (fout.is_open())
        fout << "Copy the context.";
    fout.close();
    //复制内容
    ifstream fin(argv[1]);
    fout.open(argv[2], ios_base::out);
    if (fin.is_open() && fout.is_open())
    {
        char ch;
        while (fin.get(ch))
            fout << ch;
    }
    fin.close(); fout.close();
}