//
// Created by hty on 2021/8/15.
//

/*醉汉随机漫步，给定步长，方向随机*/
#ifndef C_PRIMER_PLUS_VECTOR_H
#define C_PRIMER_PLUS_VECTOR_H

#include <iostream>
#include <cmath>
using namespace std;

class Vector {
public:
    enum Mode {Rect, Polar};
private:
    const double RAD_to_DEG = 45.0 / atan(1);
    double x;   //长
    double y;   //宽
    double mag; //模
    double ang; //度
    Mode mode;  //笛卡尔坐标系或极坐标系
    void set_x()    { x = mag * cos(ang); }
    void set_y()    { y = mag * sin(ang); }
    void set_mag()  { mag = sqrt(x * x + y * y); }
    void set_ang()
    {
        if (x == 0)
            ang = 0;
        else
            ang = atan2(y, x);
    }
public:
    Vector();   //初始化为0
    Vector(double n1, double n2, Mode form = Rect);
    void reset(double n1, double n2, Mode form = Rect);
    ~Vector();
    double ret_x()      { return x; }
    double ret_y()      { return y; }
    double ret_mag()    { return mag; }
    double ret_ang()    { return ang; }
    void operator = (Vector v);
    friend Vector operator + (Vector &a, Vector &b);  //友元方式重载+
    friend std::ostream & operator << (std::ostream & os, const Vector & v);
};


#endif //C_PRIMER_PLUS_VECTOR_H
