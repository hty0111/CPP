//
// Created by hty on 2021/9/5.
//

#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <algorithm>
using namespace std;

void show(const string & str) { cout << str << " "; }

int main()
{
    ifstream finMat, finPat;
    finMat.open("mat.txt");
    finPat.open("pat.txt");
    list<string> patmat;
    if (finMat.is_open() && finPat.is_open())
    {
        char str[10];
        while (finMat >> str)
        {
//            cout << str << " ";
            patmat.push_back(str);
        }
        finMat.close();
        while (finPat >> str)
        {
//            cout << str << " ";
            patmat.push_back(str);
        }
        finPat.close();
    }
    cout << "Original list:\n";
    for_each(patmat.begin(), patmat.end(), show);
    cout << endl;
    patmat.sort();
    patmat.unique();
    cout << "List after sort() and unique():\n";
    for_each(patmat.begin(), patmat.end(), show);
    cout << endl;

    ofstream fout("matpat.txt", ios_base::out);
    for (list<string>::iterator it = patmat.begin(); it != patmat.end(); it++)
        fout << *it << " ";
}