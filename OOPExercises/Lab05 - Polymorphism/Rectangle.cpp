#include "Rectangle.h"

Rectangle::Rectangle(double e, double e2)
{
	this->e[0] = e;
	this->e[1] = e2;
}

Rectangle::Rectangle()
{
	this->e[0] = 0;
	this->e[1] = 0;
}

double Rectangle::CalcSurface()
{
	return 0.0;
}

double Rectangle::CalcPerimeter()
{
	return 0.0;
}

void Rectangle::setLong(double f)
{
	e[0] = f;
}

void Rectangle::setShort(double f)
{
	e[1] = f;
}

double Rectangle::getLong()
{
	return e[0];
}

double Rectangle::getShort()
{
	return e[1];
}
