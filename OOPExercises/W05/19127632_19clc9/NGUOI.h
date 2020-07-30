#ifndef _NGUOI_H
#define _NGUOI_H
#include <iostream>
#include <string>
using namespace std;
struct Date
{
	int date;
	int month;
	int year;
};
class NGUOI
{
protected:
	string HoVaTen;
	Date DOB;
	string address;
public:
	void Input();
	void Show();
	
};

#endif // !_NGUOI_H

