#include "PS1.h"

void PS1::input(const int& num, const int& de)
{
	numerator = num;
	denonimator = de;
	if (denonimator == 0)
	{
		throw;
	}
	this->toigian();
}

PS1::PS1(const int& num, const int& de)
{
	numerator = num;
	denonimator = de;
	if (denonimator == 0)
	{
		throw;
	}
	this->toigian();
}

int PS1::ucln(int m, int n)
{
	int sodu, tich = m * n;
	while (n != 0) { sodu = m % n; m = n; n = sodu; }
	return m;
}

void PS1::toigian()
{
	int ucln = this->ucln(this->numerator, this->denonimator);
	this->numerator  /= ucln;
	this->denonimator /= ucln;
}

PS1 PS1::operator+(const PS1& Left)
{
	PS1 result(this->numerator * Left.denonimator + Left.numerator * this->denonimator, this->denonimator * Left.denonimator);
	result.toigian();
	return result;
}
