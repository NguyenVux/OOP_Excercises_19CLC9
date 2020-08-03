#ifndef _PS2_H
#define _PS2_H

#include "PS1.h"
#include <math.h>
#include <iostream>
using namespace std;
class PS2 :
    public PS1
{
private:
    bool isNeg = false;
public:
    PS2(const int& num, const int& de);
    PS2(PS1& in);
    bool operator<(const PS2& Left);
    bool operator>(const PS2& Left);
    bool operator>=(const PS2& Left);
    bool operator<=(const PS2& Left);
    PS2 operator-(const PS2& Left);
    PS2 operator+(const PS2& Left);
    PS2 operator*(const PS2& Left);
    PS2 operator/(const PS2& Left);
    PS2 operator++();
    PS2 operator++(int);
    PS2 operator--();
    PS2 operator--(int);
    friend ostream& operator<<(ostream& os, PS2& data);
    friend void operator>>(istream& is, PS2& data);
    bool isNegative();

};


#endif
