#include "CP1.h"

void operator>>(istream& is, CP1& input)
{
	cout << "Real = ";
	is >> input.r;
	cout << "Imaginary = ";
	is >> input.i;
}

ostream& operator<<(ostream& os, CP1& input)
{
	os << input.r << " + " << input.i << "i";
	return os;
}

CP1::CP1()
{
	this->i = 0;
	this->r = 0;
}

CP1::CP1(double r, double i)
{
	this->i = i;
	this->r = r;
}
