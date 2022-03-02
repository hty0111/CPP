//
// Created by hty on 2021/8/30.
//

/*非模板友元函数*/

#include <iostream>
using namespace std;

template <class T>
class Friend {
private:
    T item;     //储存变量
    static int ct;  //储存变量个数
public:
    Friend(const T & i) : item(i) { ct++; }
    ~Friend() { ct--; }
    friend void counts();
    friend void reports(Friend<T> &);
};

template <class T>
int Friend<T>::ct = 0;

/*非模板友元，对所有友元类都起作用*/
void counts()
{
    cout << "int: " << Friend<int>::ct << endl;
    cout << "double: " << Friend<double>::ct << endl;
}

/*int模板的友元函数*/
void reports(Friend<int> & f) { cout << "int item: " << f.item << endl; }

/*double模板的友元函数*/
void reports(Friend<double> & f) { cout << "double item: " << f.item << endl; }

int main()
{
    counts();
    Friend<int> int1(1);
    Friend<int> int2(2);
    Friend<double> dbl1(1.5);
    counts();
    reports(int1);
    reports(int2);
    reports(dbl1);
}