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

bool PS2::operator>(const PS2& Left)
{
	PS2 a = (*this - Left);
	if (!a.isNeg && a.numerator !=0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PS2::operator>=(const PS2& Left)
{
	return !(*this < Left);
}

bool PS2::operator<=(const PS2& Left)
{
	return !(*this > Left);
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

PS2 PS2::operator*(const PS2& Left)
{
	PS1 result(this->isNeg ? -this->numerator : this->numerator * Left.isNeg ? -Left.numerator : Left.numerator, this->denonimator * Left.denonimator);
	return PS2(result);
	
}

PS2 PS2::operator/(const PS2& Left)
{
	PS1 result((this->isNeg ? -this->numerator : this->numerator) * Left.denonimator, this->denonimator *( Left.isNeg ? -Left.numerator : Left.numerator));
	return PS2(result);
}

PS2 PS2::operator++()
{
	*this = *this + PS2(1, 1);
	return *this;
}

PS2 PS2::operator++(int)
{
	PS2 a = *this;
	this->operator++();
	return a;
}

PS2 PS2::operator--()
{
	*this = *this - PS2(1, 1);
	return *this;
}

PS2 PS2::operator--(int)
{
	PS2 a = *this;
	this->operator--();
	return a;
}

bool PS2::isNegative()
{
	return this->isNeg;
}

ostream& operator<<(ostream& os, PS2& data)
{
	if (data.isNegative())
	{
		os << '-';
	}
	os << data.numerator << '/' << data.denonimator;
	return os;
}

void operator>>(istream& is,PS2& data)
{
	int num, de;
	is >> num;
	is >> de;
	data = PS2(num, de);
}
