/*
定义结构，存储姓名、id、性别
实现文件存储
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct INFO
{
    string name;
    string id;
    char sex;
};

void InitInfo();
void SaveInfo();
void PrintInfo();

int main()
{
    int i;
    InitInfo();

    while(1)
    {
        cout << "请选择操作：\n";
        cout << "1、打印数据\n";
        cout << "2、添加数据\n";
        cout << "3、退出程序\n";
        cin >> i;

        switch ( i )
        {
        case 1:
            PrintInfo();
            break;
        case 2:
            SaveInfo();
            break;
        case 3:
            return 0;
        default:
            cerr << "请重新输入：";
            cin >> i;
            break;
        }
    }
}

void InitInfo()
{
    fstream init("cpp/hw3.txt", ios::out);
}

void SaveInfo()
{
    cout << "姓名  ID  性别\n";
    INFO info;
    string temp;
    cin >> info.name;
    cin >> info.id;
    cin >> info.sex;
    getline(cin, temp);
    fstream file("cpp/hw3.txt", ios::app);
    file << info.name << "  " << info.id << "  " << info.sex << "\n";
    file.close();
}

void PrintInfo()
{
    fstream file("cpp/hw3.txt", ios::in);
    char ch;
    int count = 0;
    while(file.read(&ch, 1))
    {
    cout << ch;
    }
    cout << endl;
    file.close();
}