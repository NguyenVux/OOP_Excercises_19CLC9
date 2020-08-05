#ifndef _SHAPE_H
#define _SHAPE_H
class Shape
{
public:
	virtual double CalcSurface() = 0;
	virtual double CalcPerimeter() = 0;
};

#endif // !_SHAPE_H
