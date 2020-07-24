#include "BigInt.h"

BigInt::BigInt()
{
	digit.AddTail(0);
}
BigInt::BigInt(const int& i)
{
	int numb = i;
	do
	{
		digit.AddTail(numb % 10);
		numb /= 10;
	} while (numb >0);
}

BigInt BigInt::operator+(const BigInt& Right)
{
	Node* L = ;
	Node* R = Right.digitg.
	return ;
}
