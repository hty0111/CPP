//
// Created by hty on 2021/8/30.
//

/*非约束模板友元函数*/

#include <iostream>
using namespace std;

template <class T>
class Friend {
private:
    T item;
public:
    Friend(const T & i) : item(i) {}
    //友元的所有具体化都是类的每一个具体化的友元
    template<class A, class B> friend void show(A &a, B &b);
};

template<class A, class B> void show(A &a, B &b)
{
    cout << a.item << ", " << b.item << endl;
}

int main()
{
    using Fi = Friend<int>;     //模板别名，与typedef一致
    Fi int1(1);
    Fi int2(2);
    Friend<double> dbl1(1.5);
    show(int1, int2);
    show(int1, dbl1);
}