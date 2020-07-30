#include "QuanLyHinhHocPhang.h"

HinhChuNhat::HinhChuNhat(float e1, float e2)
{
	Edge[0] = e1;
	Edge[1] = e2;
}

float HinhChuNhat::dienTich()
{
	return Edge[0]*Edge[1];
}

float HinhChuNhat::chuvi()
{
	return Edge[0]*2+Edge[1]*2;
}

float HinhTron::dienTich()
{
	return r*r*PI;
}

float HinhTron::chuvi()
{
	return 2*r*PI;
}
