#include "Triangle.h"

void EqTriangle::setEdge(double e)
{
	edge = e;
}

double EqTriangle::getEdge()
{
	return edge;
}

double EqTriangle::CalcSurface()
{
	return edge*edge* 0.43301270189;
}

double EqTriangle::CalcPerimeter()
{
	return edge*3.0;
}
