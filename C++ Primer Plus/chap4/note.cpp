//
// Created by hty on 2021/5/30.
//

#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int main()
{
    int list[]{0,1,2};         //初始化可省略'='
    int length;
    cout << "Input length of list\n";
    (cin >> length).get();              //cin会将换行符留在输入队列中
    char list1[length], list2[length], list3[length];
    cout << "Input 3 sentences:\n";
    cin.getline(list1, length);        //读取19个字符，丢弃换行符
    cin.get(list2, length);            //读取下一行，换行符仍在输入队列中
    cin.get();                          //读取一个字符，即换行符
    string str;
    getline(cin, str);                 //读取下一行
    cout << list1 << endl << list2 << endl << str << endl;

    string str1, str2;
    str2 = "HTY";                       //程序能自动处理string的长度
    str1 = str2;                        //string可以赋值，数组不可以
    //strcpy(str2, str1);
    str2 += str1;                       //拼接
    //strcat(str2, str1);
    int len1 = str1.size();             //长度
    //strlen(str1);

    cout << R"("HTY" uses '\n' instead of 'endl'.)" << '\n';
    cout << R"+*("(Who wouldn't?)", HTY whispered.)+*" << endl;

    struct info
    {
        string name;
        int age;
    }zxa = {"ZXA", 20};
    info hty = {"HTY", 21};         //定义可以省略关键词'struct'，逗号分隔

    struct my_register
    {
        unsigned int SN : 4;        //4位的SN值
        unsigned int : 4;           //保留4位
        bool goodIn : 1;
    };
    my_register reg = {10, true};

    enum my_color{red, yellow, blue, green, purple, pink, white};
    my_color color;
    color = red;
    cout << color << endl;      //0
    color = my_color(1);        //yellow
    cout << color << endl;      //1

    enum bits{one = 1, two = 2, six = 6};
    bits flag;
    flag = bits(4);             //取值范围[-2^n or 0, 2^m]，此处为[0, 8]

    int * pt = new int;
    pt = (int *) 0xB8000000;    //不能用整型赋值
    delete pt;
    int * psome = new int [10];
    delete [] psome;
    
    int n = 4;
    vector<int> vi(n);          //n个元素的整型数组，不能初始化
    array<int, 2> ai = {0, 1};  //元素个数只能是常量，可以初始化
    vi.at(1) = 0;               //可以捕获下标越界
    
    return 0;
}