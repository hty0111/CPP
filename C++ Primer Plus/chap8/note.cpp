//
// Created by hty on 2021/8/9.
//

#include <iostream>
using namespace std;

inline double sqr(double t) { return t * t; }   //内联函数，以空间换时间
void mul(int & t, int times = 2) { t *= times; }    //声明时从右向左添加默认参数，定义时无需默认参数

struct my_struct{string name; int age;};
template <class T>   //模板，并非函数定义，class可替换为typename
void Swap(T &x, T &y) {x ^= y; y ^= x; x ^= y;}     //隐式实例化
template void Swap<char> (char &, char &);    //显式实例化，使用Swap()模板生成double类型的函数定义
template <> void Swap<my_struct> (my_struct &s1, my_struct &s2)     //显式具体化，优先级高于模板
        {
    Swap(s1.age, s2.age);
        }

template<class T1, class T2>
auto f(int x, float y) -> decltype(x+y);    //在xy定义后确定函数的返回类型

int main()
{
    int a = 0;
    int & alias = a;    //引用变量，同一内存地址，相当于起别名，必须在声明的同时初始化
    int b = 1;
    Swap(a, b);    //传引用的同时直接赋值
    cout << a << " " << b << endl;      //1 0
    mul(a);
    cout << a << endl;  //2

    char ch1 = 'a', ch2 = 'b';
    Swap(ch1, ch2);
    cout << ch1 << " " << ch2 << endl;      //b a

    my_struct s1 = {"hty", 21};
    my_struct s2 = {"zxa", 20};
    Swap(s1, s2);
    cout << s1.age << " " << s2.age << endl;    //20 21

    decltype(a+b) c = a;    //使c的类型与a+b相同
}