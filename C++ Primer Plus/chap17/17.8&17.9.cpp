//
// Created by hty on 2021/9/4.
//

#include <iostream>
#include <cmath>
using namespace std;

void display()
{
    long n;
    for (n = 1; n < 41; n += 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }
}

int main()
{
    /*一个参数的setf()*/
    int temperature = 38;
    cout << "Today's temperature: ";
    cout.setf(ios_base::showpos);   //在正数前面加上+
    cout << temperature << endl;

    cout << "For programming friends, that's: \n";
    cout << hex << temperature << " or ";     //16进制
    cout.setf(ios_base::uppercase);     //对16进制输出，使用大写字母
    cout.setf(ios_base::showbase);      //对输出使用基数前缀(0, 0x)
    cout << temperature << endl;

    cout << "How " << true << "! oops -- How ";
    cout.setf(ios_base::boolalpha);     //输入或输出bool值
    cout << true << "!\n\n";

    /*两个参数的setf()*/
    cout.setf(ios_base::left, ios_base::adjustfield);   //左对齐
    cout.setf(ios_base::showpos);       //在正数前面加上+
    cout.setf(ios_base::showpoint);     //显示末尾小数点
    cout.precision(3);
    ios_base::fmtflags old = cout.setf(ios_base::scientific, ios_base::floatfield);     //科学计数法
    cout << "Left Justification:\n";
    display();

    cout.setf(ios_base::internal, ios_base::adjustfield);  //中间对齐
    cout.setf(old, ios_base::floatfield);   //恢复默认的浮点数显示方法
    cout << "Internal Justification:\n";
    display();

    cout.setf(ios_base::right, ios_base::adjustfield);  //右对齐
    cout.setf(ios_base::fixed, ios_base::floatfield);   //定点计数法
    cout << "Right Justification:\n";
    display();

}