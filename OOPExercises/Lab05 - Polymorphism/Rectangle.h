#include "Shape.h"
class Rectangle :
	public Shape
{
protected:
	double e[2];
public:
	Rectangle(double e, double e2);
	Rectangle();
	double CalcSurface();
	double CalcPerimeter();
	void setLong(double);
	void setShort(double);
	double getLong();
	double getShort();
};

