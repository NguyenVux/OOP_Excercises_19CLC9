#pragma once
#include "Shape.h"
class EqTriangle :
    public Shape
{
private:
    double edge;
public:
    EqTriangle(double e) : edge(e) {}
    EqTriangle() : edge(0.0) {}
    void setEdge(double);
    double getEdge();
    double CalcSurface();
    double CalcPerimeter();
};

