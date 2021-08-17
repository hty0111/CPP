//
// Created by hty on 2021/8/17.
//

#include "string0.h"
#include <cstring>

int String::strNum = 0;
using std::cout;
using std::endl;

String::String()
{
    strNum++;
    len = 5;
    str = new char[5];
    strcpy(str, "NULL");
    cout << "\"" << str << "\" created by default constructor, " << strNum << " left.\n";
}

String::String(const char * s)
{
    strNum++;
    len = strlen(s);
    str = new char[len + 1];
    strcpy(str, s);
    cout << "\"" << str << "\" created by non-default constructor, " << strNum << " left.\n";
}

String::String(const String & s)
{
    std::cout << "!\n";
    strNum++;
    len = s.len;
    str = new char[len + 1];
    strcpy(str, s.str);    //深度复制，而不是传递地址
    cout << "\"" << str << "\" created by copy constructor, " << strNum << " left.\n";
}

String::~String()
{
    strNum--;
    std::cout << "\"" << str << "\"deleted, " << strNum << " left.\n";
    delete [] str;
}

String & String::operator=(const String & s)
{
    if (this == &s)
        return *this;
    delete [] str;
    len = s.len;
    str = new  char[len + 1];
    std::strcpy(str, s.str);
    return *this;
}

String & String::operator=(const char * s)
{
    delete [] str;
    len = strlen(s);
    str = new  char[len + 1];
    strcpy(str, s);
    return *this;
}

char & String::operator[](int i)
{
    return str[i];
}

String operator+(String & s1, String & s2)
{
    int length = s1.len + s2.len;
    char * str = new char[length + 1];
    strcpy(str, s1.str);
    strcat(str, s2.str);
    String temp(str);
    delete [] str;
    return temp;
}

std::ostream & operator<<(std::ostream & os, const String & s)
{
    os << s.str;
    return os;
}

std::istream & operator>>(std::istream & is, String & s)
{
    char temp[String::MaxCin];
    is.get(temp, String::MaxCin);
    if (is)
        s = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}