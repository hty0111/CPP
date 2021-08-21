//
// Created by hty on 2021/8/20.
//

#ifndef C_PRIMER_PLUS_PORT_H
#define C_PRIMER_PLUS_PORT_H

#include <iostream>
using std::ostream;

class Port {
private:
    char * brand;
    char style[20];
    int bottles;
public:
    Port(const char * br = "none", const char * st = "none", int b = 0);
    Port(const Port & p);
    virtual ~Port() { delete [] brand; }
    Port & operator=(const Port & p);
    Port & operator+=(int b);   //add b to bottles
    Port & operator-=(int b);
    int bottleCount() const { return bottles; }
    virtual void show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
};

class VintagePort : public Port{
private:
    char * nickname;
    int year;
public:
    VintagePort(Port & p, const char * nn, int y);
    VintagePort(const char * br, const char * st, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() { delete [] nickname; }
    VintagePort & operator=(const VintagePort & vp);
    void show() const;
    friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

#endif //C_PRIMER_PLUS_Port_H
