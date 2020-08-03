#include "Sphere.h"

double Sphere::volume()
{
    return r*r*PI*r*(4.0/3.0);
}

double Sphere::CalcSurface()
{
    return r*r*PI*4.0;
}

double Sphere::CalcPerimeter()
{
    return 0.0;
}
