#ifndef _NV_H
#define _NV_H
#include "NGUOI.h"
class NV :
	public NGUOI
{
private:
	string Ban;
	double SalaryCo;
	double Extra;
public:
	void Input();
	void Show();
};
#endif // !_NGUOI_H



