//
// Created by hty on 2021/8/30.
//

/*约束模板友元函数*/

#include <iostream>
using namespace std;

//在类定义前声明每个模板函数，即为约束模板友元函数，每种类的具体化都有对应函数的具体化
template <class T> void counts();
template <class T> void reports(T &);

//声明模板类
template <class T>
class Friend {
private:
    T item;
    static int ct;
public:
    Friend(const T & i) : item(i) { ct++; }
    ~Friend() { ct--; }
    //将模板声明为友元
    friend void counts<T>();
    friend void reports<>(Friend<T> &);
};

template <class T>
int Friend<T>::ct = 0;

//约束模板友元函数的定义，每种T类型都有自己的友元函数
template <class T>
void counts()
{
    cout << "template size: " << sizeof(Friend<T>) << endl;
    cout << "template counts: " << Friend<T>::ct << endl;
}

template <class T>
void reports(T & f)
{
    cout << f.item << endl;
}

int main()
{
    counts<int>();
    Friend<int> int1(1);
    Friend<int> int2(2);
    Friend<double> dbl1(1.5);
    counts<int>();
    counts<double>();
}