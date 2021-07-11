#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    ifstream in;
    in.open("cpp/file.txt");
    //fstream in("cpp/test.txt");
    if( !in )
    {
        cerr << "fail to open" << endl;
        return 0;
    }
    char x;
    while( in >> x )
    {
        cout << x;
    }

    cout << endl;
    in.close();

    ofstream out;
    out.open("cpp/file.txt", ios::app);
    //fstream out("cpp/test.txt"); 
    for( int i = 0; i < 10; i++ )
    {
        out << i;
    }

    out << endl;
    out.close();

    return 0;
}

/*文件打开模式
ios::in         打开可读文件
ios::out        打开可写文件
ios::binary     二进制打开
ios::app        追加到文件末尾
ios::trunk      删除内容
ios::nocreate   如果打开文件不存在，则无法以此参数调用open
ios::noreplace  如果打开文件已存在，则调用open返回错误
ios::beg        使得文件指针指向文件头
ios::end        使得文件指针指向文件尾
*/