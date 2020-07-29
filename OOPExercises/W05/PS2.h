#ifndef _PS2_H
#define _PS2_H

#include "PS1.h"
#include <math.h>
class PS2 :
    public PS1
{
private:
    bool isNeg = false;
public:
    PS2(const int& num, const int& de);
    PS2(PS1& in);
    bool operator<(const PS2& Left);
    PS2 operator-(const PS2& Left);
    PS2 operator+(const PS2& Left);
    bool isNegative();

};


#endif
