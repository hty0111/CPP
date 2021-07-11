#include <iostream>

int main()
{   
    const unsigned short ITEM = 10;
    int num[ITEM];
    std::cout << "请输入十个整型数据\n";
    for( int i = 0; i < ITEM; i++ )
    {
        std::cout << "请输入第" << i+1 << "个数据：";
        while( !(std::cin >> num[i]) )      //发生意外返回0
        {
            std::cin.clear();
            std::cin.ignore(10, '\n');
            std::cout << "重新输入：";
        }
    }

    int total = 0;          //局部变量存放在栈中，需初始化
    for( int j = 0; j < ITEM; j++ )
    {
        total += num[j];
    }

    std::cout << "总和为：" << total << "\n";
    std::cout << "平均值为：" << (float)total / ITEM;
}