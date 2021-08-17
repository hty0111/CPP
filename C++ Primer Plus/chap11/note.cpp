//
// Created by hty on 2021/8/13.
//

#include <iostream>
using namespace std;

class Time{
private:
    int min;
    int hour;
public:
    Time()
    {
        hour = min = 0;
    }
    explicit Time(int min, int hour = 0)    //必须显示转换，只有一个构造参数时使用
    {
        this->hour = hour;
        this->min = min;
    }
    Time operator + (const Time &t) const   //重载运算符
    {
        Time sum;
        sum.min = min + t.min;
        sum.hour = hour + t.hour + sum.min/60;
        sum.min %= 60;
        return sum;
    }
    friend ostream & operator << (ostream & os, const Time &t);   //友元函数声明
    operator double()      //转换函数，实现类类型到某种类型的转换，无返回类型和参数，必须是类方法
    {
        return hour + (double) min / 60;
    }
};

int main()
{
    Time time1(10, 1);
    Time time2(20);
    Time sum;
    sum = time1 + time2;
    cout << sum;
    cout << (double) sum << endl;
}

ostream & operator << (ostream & os, const Time &t)   //友元函数定义时无需关键词friend
{
    os << "hour: " << t.hour << "\tminute: " << t.min << endl;
    return os;
}