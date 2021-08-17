//
// Created by hty on 2021/8/17.
//

#ifndef C_PRIMER_PLUS_STRING0_H
#define C_PRIMER_PLUS_STRING0_H

#include <iostream>

class String {
private:
    char *str;  //字符串
    int len;    //string的长度
    static int strNum;  //生成的字符串数量
    static const int MaxCin = 20;   //字符串最长数量
public:
    String();   //默认构造器
    String(const char *);   //非默认构造器
    String(const String &); //复制构造器
    ~String();  //析构器
    int length() const { return len; }
    String & operator=(const String &);
    String & operator=(const char *);
    char & operator[](int i);
    friend String operator+(String &, String &);
    friend std::ostream & operator<<(std::ostream & os, const String & s);
    friend std::istream & operator>>(std::istream & is, String & s);
    static int howMany() { return strNum; }
};


#endif //C_PRIMER_PLUS_STRING0_H
