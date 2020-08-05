#include "Circle.h"

double Circle::CalcSurface()
{
    return r*r*PI;
}

double Circle::CalcPerimeter()
{
    return 2*r*PI;
}

void Circle::setRadius(double rad)
{
    this->r = rad;
}

double Circle::getRadius(double rad)
{
    return r;
}
