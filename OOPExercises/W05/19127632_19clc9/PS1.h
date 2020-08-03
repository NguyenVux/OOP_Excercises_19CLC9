#pragma once
class PS1
{
protected:
	int numerator;
	int denonimator;
public:
	void input(const int& num, const int& de);
	PS1(const int& num, const int& de);
	int ucln(int m, int n);
	void toigian();
	PS1 operator+(const PS1& Left);

};

