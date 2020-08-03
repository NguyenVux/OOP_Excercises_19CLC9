#include "NGUOI.h"

void NGUOI::Input()
{
	cout << "Ho Va Ten: " << endl;
	getline(cin, HoVaTen);
	//cin.ignore();
	cout << "Ngay Sinh: " << endl;
	cout << "Ngay: ";
	cin >> DOB.date;
	cout << "Thang: ";
	cin >> DOB.month;
	cout << "Nam: ";
	cin >> DOB.year;
	cout << "Dia chi: " << endl;
	cin.ignore();
	getline(cin, address);
}

void NGUOI::Show()
{
	cout << "Ho va ten: " << HoVaTen << endl << "Ngay Sinh: " << DOB.date << '/' << DOB.month << '/' << DOB.year << endl << "Dia chi: " << address << endl;
}
