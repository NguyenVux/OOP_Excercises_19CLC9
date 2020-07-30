#include "CP2.h"

CP2 CP2::operator+(const CP2& Left)
{
	return CP2(this->r + Left.r,this->i+Left.i);
}

CP2 CP2::operator-(const CP2& Left)
{
	return CP2(this->r - Left.r, this->i - Left.i);
}

CP2 CP2::operator*(const CP2& Left)
{
	return CP2(this->r*Left.r-this->i*Left.i, this->r*Left.i+Left.r*this->i);
}

CP2 CP2::operator/(const CP2& Left)
{
	double de = (Left.r * Left.r + Left.i * Left.i);
	double i = (Left.r * this->i - Left.i * this->r);
	double r = (Left.r * this->r + Left.i * this->i);
	return CP2(r/de,i/de);
}

CP2 CP2::operator--()
{
	*this = this->operator-(CP2(1, 1));
	return *this;
}

CP2 CP2::operator--(int)
{
	CP2 tmp = *this;
	*this = this->operator-(CP2(1, 1));
	return tmp;
}

CP2 CP2::operator++()
{
	*this = this->operator+(CP2(1, 1));
	return *this;
}


CP2 CP2::operator++(int)
{
	CP2 tmp = *this;
	*this = this->operator+(CP2(1, 1));
	return tmp;
}
