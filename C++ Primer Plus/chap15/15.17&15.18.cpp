//
// Created by hty on 2021/8/31.
//

/*RTTI--dynamic_cast，确保指针转换是安全的*/

#include <iostream>
#include <typeinfo>
using namespace std;

class Grand {
private:
    int hold;
public:
    Grand(int h = 0) : hold(h) {}
    virtual int value() { return hold; }
};

class Superb : public Grand {
public:
    Superb(int h = 0) : Grand(h) {}
    virtual void say() { cout << "I hold the superb value of " << value() << "!\n"; }
};

class Magnificent : public Superb {
public:
    Magnificent(int h = 0) : Superb(h) {}
    void say() { cout << "I hold the magnificent value of " << value() << "\n"; }
};

int main()
{
    Grand * pg = new Grand;
    Superb * ps;
    Magnificent *pm = new Magnificent;
    if ((ps = dynamic_cast<Superb *>(pg)))    //将基类指针赋给子类，不安全，返回空指针
        ps->say();
    if ((ps = dynamic_cast<Superb *>(pm)))    //安全，返回Superb类型的指针
        cout << "Now processing type " << typeid(*pg).name() << "!\n";
        ps->say();
        if (typeid(Magnificent) == typeid(*ps))
            cout << "Yes, you are really magnificent!\n";

}
