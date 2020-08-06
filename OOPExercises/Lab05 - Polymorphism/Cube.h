#pragma once
#include "Square.h"
#include "Shape3D.h"
class Cube :
    public Square, public Shape3D
{
public:
    Cube(double r) :Square(r) {}
    //Cube() :Square() {}
    double volume();
    double CalcSurface();
    double CalcPerimeter();
};

