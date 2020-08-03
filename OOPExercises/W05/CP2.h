#ifndef _CP2_H
#define _CP2_H
#include "CP1.h"
class CP2 :
	public CP1
{
public:
	CP2() :CP1(){}
	CP2(double r, double i) :CP1(r, i) {}
	CP2 operator+(const CP2& Left);
	CP2 operator-(const CP2& Left);
	CP2 operator*(const CP2& Left);
	CP2 operator/(const CP2& Left);
	CP2 operator--();
	CP2 operator--(int);
	CP2 operator++();
	CP2 operator++(int);
};
#endif

