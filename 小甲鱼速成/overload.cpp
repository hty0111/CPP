//重载+号，实现有理数的加法
//重载插入器<<，使有理数和字符串正常输出

#include <iostream>
#include <math.h>

class Rational
{
public:
    Rational(int num, int denom);
    Rational operator+(Rational rhs);    //right hand side
    void print();

private:
    void normalize();   //化简
    int numerator;
    int denomerator;

    friend std::ostream& operator<<(std::ostream& os, Rational f);  //声明友元函数
};

Rational::Rational(int num, int denom)      //构造器
{
    numerator = num;
    denomerator = denom;
    normalize();
}

void Rational::normalize()      //辗转相除
{
    if( denomerator < 0 )
    {
        numerator = -numerator;
        denomerator = -denomerator;
    }

    int a = abs(numerator);
    int b = abs(denomerator);
    while( b > 0 )
    {
        int t = a % b;
        a = b;
        b = t;
    }
    numerator /= a;
    denomerator /= a;
}

Rational Rational::operator+(Rational rhs)
{
    int a = numerator;
    int b = denomerator;
    int c = rhs.numerator;
    int d = rhs.denomerator;
    int e = a*d + c*b;
    int f = b * d;
    return  Rational(e, f);
}

void Rational::print()
{
    if( numerator % denomerator == 0 )
        std::cout << numerator / denomerator;
    else
        std::cout << numerator << "/" << denomerator;
}

std::ostream& operator<<(std::ostream& os, Rational f);     //函数声明

int main()
{
    Rational a(4, 2);
    Rational b(7, 5);
    std::cout << a << " + " << b << " = " << (a+b) << "\n";
}

std::ostream& operator<<(std::ostream& os, Rational f)
{
    os << f.numerator << "/" << f.denomerator;
    return os;
}

/*
不能改变操作数、级别、结合性
无默认参数，知道有一个类对象的引用
*/

