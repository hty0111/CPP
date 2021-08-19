//
// Created by hty on 2021/8/18.
//

#include <iostream>
using namespace std;

class Base{
private:
    int x, y;
public:
    Base()  { x = y = 0; }
    Base(int n1, int n2) : x(n1), y(n2)  { }
    virtual int sum()   { return x + y; }   //函数定义时无需virtual
    friend ostream & operator<<(ostream & os, Base & b)
    {
        os << b.sum();
        return os;
    }
};

class Derived : public Base{    //派生类不可以直接访问基类的私有成员
private:
    int z;
    int sumBase;
public:
    Derived() : Base()  { z = 0; }  //初始化成员列表
    Derived(int n, Base & b) : Base(b), z(n), sumBase(b.sum())  { }     //用到了基类的复制构造器
    int sum()   { return sumBase + z; }     //派生类中定义的函数会覆盖基类中所有同名函数，并非重载
    friend ostream & operator<<(ostream & os, Derived & d)
    {
        os << (Base &) d;
//        os << d.sum();
        return os;
    }
};

int main()
{
    Base c1(1, 2);
    cout << c1 << endl;     //3
    Derived c2(3, c1);
    cout << c2 << endl;     //6
    Base * c3 = &c2;    //基类指针和引用可以指向派生类，也可以直接赋值
    cout << *c3 << endl;    //6，虚方法使得调用了派生类中的函数
}