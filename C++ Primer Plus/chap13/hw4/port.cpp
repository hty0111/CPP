//
// Created by hty on 2021/8/20.
//

#include "port.h"
#include <iostream>
#include <cstring>
using namespace std;

Port::Port(const char * br, const char * st, int b)
{
    int len_br = strlen(br);
    brand = new char[len_br + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port & p)
{
    int len_br = strlen(p.brand);
    brand = new char[len_br + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port & Port::operator=(const Port & p)
{
    if (this == &p)
        return *this;
    delete [] brand;
    int len_br = strlen(p.brand);
    brand = new char[len_br + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}

void Port::show() const
{
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p)
{
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

VintagePort::VintagePort(Port & p, const char * nn, int y) : Port(p)
{
    int len_nn = strlen(nn);
    nickname = new char[len_nn + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const char * br, const char * st, int b, const char * nn, int y) : Port(br, st, b)
{
    int len_nn = strlen(nn);
    nickname = new char[len_nn + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
    int len_nn = strlen(vp.nickname);
    nickname = new char[len_nn + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if (this == &vp)
        return *this;
    delete [] nickname;
    int len_nn = strlen(vp.nickname);
    nickname = new char[len_nn + 1];
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::show() const
{
    Port::show();
    cout << "Nickname: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp)
{
    os << (Port &) vp << ", " << vp.nickname << ", " << vp.year;
    return os;
}