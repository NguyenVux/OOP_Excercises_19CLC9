#include "Cube.h"

double Cube::volume()
{
    return Square::CalcSurface()*this->getEdge();
}

double Cube::CalcSurface()
{
    return Square::CalcSurface()*6;
}

double Cube::CalcPerimeter()
{
    return 0.0;
}
