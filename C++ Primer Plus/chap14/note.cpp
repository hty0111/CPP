//
// Created by hty on 2021/8/20.
//

#include <iostream>
#include <valarray>
#include <cstring>

using namespace std;
typedef valarray<double> ArrayDbl;

template <class T, int n>   //后者为表达式参数，只能为整型、枚举、引用、指针，不能修改参数的值，不能使用参数的地址，在实例化时必须为常量

//私有继承
class Student : private string, private valarray<double> {
public:
    Student(const char * str, const double * pd, int n) : string(str), ArrayDbl(pd, n) {}
    double average() const { return ArrayDbl::sum() / ArrayDbl::size(); }   //使用类名和作用域解析符调用方法
    const string & name() const { return (const string &) *this; }  //访问基类对象，用强制类型转换
};

int main()
{
    valarray<int> v1;       //size 0
    valarray<int> v2(8);    //8个int
    valarray<int> v3(10, 8);    //8个int，值为10
    int array[5];
    valarray<int> v4(array, 2); //取array的前两个元素
}