//
// Created by hty on 2021/8/11.
//

#include <iostream>

//只能通过类的公有函数和友元函数访问私有成员
class Company
{
private:
    enum {MAX = 10};    //在类中创建常量
    std::string name_;
    double shares_;
public:
    Company()   //默认构造函数，无需参数
    {
        name_ = "hty";
        shares_ = 0.5;
    }
    Company(std::string name, double shares)    //非默认构造函数
    {
        name_ = name;
        shares_ = shares;
    }
    ~Company()
    {
        std::cout << "Bye!" << name_ << std::endl;
    }
    void show() const   //const成员函数
    {
        std::cout << name_ << ": " << shares_ << std::endl;
    }
};

int main()
{
    Company HTY;    //使用默认构造函数
    Company ZXA("zxa", 0.2);
    HTY.show();     //hty: 0.5
    ZXA.show();     //zxa: 0.2
    return 0;
}