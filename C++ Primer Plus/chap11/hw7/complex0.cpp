//
// Created by hty on 2021/8/15.
//

#include "complex0.h"

Complex::Complex(double a, double b)
{
    re = a; im = b;
}
Complex::~Complex() { }

Complex Complex::operator + (const Complex &c) const
{
    Complex sum;
    sum.re = re + c.re;
    sum.im = im + c.im;
    return sum;
}

Complex Complex::operator - (const Complex &c) const
{
    Complex sub;
    sub.re = re - c.re;
    sub.im = im - c.im;
    return sub;
}

Complex Complex::operator * (const Complex &c) const
{
    Complex pro;
    pro.re = re * c.re - im * c.im;
    pro.im = re * c.im + im * c.re;
    return pro;
}

Complex Complex::operator ~ () const
{
    Complex reverse;
    reverse.re = re;
    reverse.im = -im;
    return reverse;
}

Complex Complex::operator * (double n) const
{
    Complex p;
    p.re = n * re;
    p.im = n * im;
    return p;
}

Complex operator * (double n, const Complex &c)
{
    return c * n;
}

std::istream & operator >> (std::istream & is, Complex & c)
{
    is >> c.re; is >> c.im;
    return is;
}

std::ostream & operator << (std::ostream & os, const Complex & c)
{
    os << "(" << c.re << ", " << c.im << "i)";
    return os;
}