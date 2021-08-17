//
// Created by hty on 2021/8/15.
//

/*实现复数的基本运算*/

#ifndef C_PRIMER_PLUS_COMPLEX0_H
#define C_PRIMER_PLUS_COMPLEX0_H

#include <iostream>

class Complex {
public:
    double re;
    double im;
    Complex(double a = 0, double b = 0);
    ~Complex();
    Complex operator + (const Complex &c) const;
    Complex operator - (const Complex &c) const;
    Complex operator * (const Complex &c) const;
    Complex operator ~ () const;
    Complex operator * (double n) const;
    friend Complex operator * (double n, const Complex &c);
    friend std::istream & operator >> (std::istream & is, Complex & c);
    friend std::ostream & operator << (std::ostream & os, const Complex & c);
};


#endif //C_PRIMER_PLUS_COMPLEX0_H
