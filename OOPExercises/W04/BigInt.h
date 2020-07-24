#ifndef _BIGINT_H
#define _BIGINT_H
#include "LinkedList.h"
class BigInt
{
private:
	LinkedList digit;
public: 
	BigInt();
	BigInt(const int&);
	BigInt operator+(const BigInt& Right);

};
#endif // !_BIGINT_H



