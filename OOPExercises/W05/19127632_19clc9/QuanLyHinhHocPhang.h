#ifndef _QuanLyHinhHocPhang_H
#define _QuanLyHinhHocPhang_H
#include <math.h>
class QuanLyHinhHocPhang
{

};

class IHinhHocPhang
{
public:
	virtual float dienTich() = 0;
	virtual float chuvi() = 0;
};

class HinhChuNhat : public IHinhHocPhang
{
private:
	float Edge[4];
public:
	HinhChuNhat(float e1, float e2);
	float dienTich();
	float chuvi();
};

class HinhTron : public IHinhHocPhang
{
private:
	float r;
	static const double PI;
public:
	HinhTron(float r) :r(r) {}
	float dienTich();
	float chuvi();
};
const double HinhTron::PI = 3.14;


#endif
