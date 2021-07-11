/*
向用户提出一个Y/N的问题，赋值给answer变量，过滤大小写
*/

#include <iostream>

int main()
{
    char answer;
    std::cout << "请问可以格式化硬盘吗" << "\n";
    std::cin >> answer;
    switch ( answer )
    {
    case 'Y':
    case 'y':
        std::cout << "不可以这样哦\n";
        break;
    case 'N':
    case 'n':
        std::cout << "正确的选择\n";
        break;
    default:
        std::cout << "输入不符合要求\n";
        break;
    }
    std::cin.ignore(100, '\n');     //一百个字符内忽略回车
    std::cout << "按任意键结束" << "\n";
    std::cin.get();
}