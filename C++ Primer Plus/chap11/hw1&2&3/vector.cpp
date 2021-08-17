//
// Created by hty on 2021/8/15.
//

#include "vector.h"

using namespace std;

Vector::Vector()
{
    x = y = mag = ang = 0;
    mode = Rect;
}

Vector::Vector(double n1, double n2, Mode form)
{
    if (form == Rect)
    {
        x = n1; y = n2;
        set_mag();  set_ang();
    }
    if (form == Polar)
    {
        mag = n1; ang = n2 / RAD_to_DEG;
        set_x();    set_y();
    }
}

Vector::~Vector()   { }

void Vector::operator = (Vector v)
{
    x = v.x; y = v.y;
    mag = v.mag; ang = v.ang;
}

void Vector::reset(double n1, double n2, Mode form)
{
    if (form == Rect)
    {
        x = n1; y = n2;
        set_mag();  set_ang();
    }
    if (form == Polar)
    {
        mag = n1; ang = n2 / RAD_to_DEG;
        set_x();    set_y();
    }
}

Vector operator + (Vector &a, Vector &b)
{
    Vector res;
    res.x = a.x + b.x;
    res.y = a.y + b.y;
    res.set_mag();
    res.set_ang();
    return res;
}

std::ostream & operator << (std::ostream & os, const Vector & v)
{
    double ang = v.ang * v.RAD_to_DEG;
    if (ang < -180)
        ang += 360;
    if (ang > 180)
        ang -= 360;
    os << "x: " << v.x << "\ty: " << v.y << endl;
    os << "mag: " << v.mag << "\tangle: " << ang;
    return os;
}