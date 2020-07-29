#include "PS2.h"

PS2::PS2(const int& num, const int& de) :PS1(num, de)
{
	if (this->numerator * this->denonimator < 0)
	{
		this->isNeg = true;
	}
	else
	{
		this->isNeg = false;
	}
	this->numerator = abs(this->numerator);
	this->denonimator = abs(this->denonimator);
}

PS2::PS2(PS1& in) :PS1(in)
{
	if (this->numerator * this->denonimator < 0)
	{
		this->isNeg = true;
	}
	else
	{
		this->isNeg = false;
	}
	this->numerator = abs(this->numerator);
	this->denonimator = abs(this->denonimator);
}

bool PS2::operator<(const PS2& Left)
{
	if ((*this - Left).isNeg)
	{
		return true;
	}
	else
	{
		return false;
	}
}

PS2 PS2::operator-(const PS2& Left)
{
	PS1 R(this->isNeg ? -this->numerator : this->numerator, this->denonimator);
	PS1 L(Left.isNeg ? Left.numerator : -Left.numerator, Left.denonimator);
	PS1 result = R + L;
	PS2 resultPs2(result);
	return result;
}

PS2 PS2::operator+(const PS2& Left)
{
	PS1 R(this->isNeg ? -this->numerator : this->numerator, this->denonimator);
	PS1 L(Left.isNeg ? -Left.numerator : Left.numerator, Left.denonimator);
	PS1 result = R + L;
	PS2 resultPs2(result);
	return result;
}

bool PS2::isNegative()
{
	return this->isNeg;
}
