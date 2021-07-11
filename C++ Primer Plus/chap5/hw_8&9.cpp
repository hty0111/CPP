//
// Created by hty on 2021/5/30.
//

/*读取单词并输出，直到输入位done，输出单词数量*/
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word;
    cin >> word;
    int count = 0;
    while( word != "done" )
    {
        cout << word << " ";
        count++;
        cin >> word;
    }
    cout << endl << count << " words in total.\n";
}