#pragma once
#include "Shape.h"
class Circle :
    public Shape
{
protected:
    double r;
public:
    Circle(double rad) : r(rad) {}
    Circle():r(0.0) {}
    double CalcSurface();
    double CalcPerimeter();
    void setRadius(double rad);
    double getRadius(double rad);
};

const double PI = 3.14;

