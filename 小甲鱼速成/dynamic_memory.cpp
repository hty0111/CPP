#include <iostream>
#include <string>
using namespace std;

class Company
{
public:
    Company(string name)
    {
        this->name = name;
    }
    virtual void printInfo()
    {
        cout << "这家公司是" << name << "\n";
    }

protected:
    string name;
};

class TechCompany : public Company
{
public:
    TechCompany(string name, string product) : Company(name)
    {
        this->product = product;
    }
    void printInfo()
    {
        cout << name << "公司生产" << product << "\n";
    }

private:
    string product;
};

int main()
{
    Company * company = new Company("APPLE");
    company->printInfo();
    delete company;
    company = NULL;

    company = new TechCompany("APPLE", "IPHONE");
    company->printInfo();
    delete company;
    company = NULL;
}

/*
 内存块分为堆和栈，堆往上增长，栈往下增长
 new必须对应delete(malloc & free)
 delete语句只释放指针指向的内存块，但指针变量依然健在，须设置为NULL
 函数中申请的内存不会在函数结束后释放
*/

