#ifndef _CP1_H
#define _CP1_H
#include <iostream>
using namespace std;
class CP1
{
protected:
	double i;
	double r;
public:
	CP1();
	CP1(double r, double i);
	friend void operator>>(istream& is, CP1& input);
	friend ostream& operator<<(ostream& os, CP1& input);
};
#endif // !_CP1_H



