#pragma once
#include "Circle.h"
#include "Shape3D.h"
class Sphere :
    public Circle,public Shape3D
{
public:
    Sphere(double r) :Circle(r) {}
    Sphere() :Circle() {}
    double volume();
    double CalcSurface();
    double CalcPerimeter();
};

