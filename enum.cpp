#include <iostream>

using namespace std;

int main()
{
    enum weekdays{Mon, Tue, Wed, Thu, Fri};
    weekdays today;

    today = Mon;
    cout << today << endl;      //0
    today = Wed;
    cout << today << endl;      //2

    switch (today)
    {
    case Mon:       //字符串不可以switch，但是枚举中存储的是数字
        break;
    
    default:
        break;
    }

}

/*
创建一个可取值的列表
无需引号
编译器以0 ~ n-1的整数将变量关联起来
*/