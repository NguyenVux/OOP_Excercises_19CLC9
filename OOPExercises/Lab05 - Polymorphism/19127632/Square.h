#pragma once
#include "Rectangle.h"
class Square :
    public Rectangle
{
public:
    Square(double e) : Rectangle(e, e) {}
    Square() :Rectangle() {}
    double getEdge();
    void setEdge(double);
    
};

