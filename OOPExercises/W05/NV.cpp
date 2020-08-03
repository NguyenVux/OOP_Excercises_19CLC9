#include "NV.h"

void NV::Input()
{
	NGUOI::Input();
	cout << "Nhap Phong ban: ";
	getline(cin, Ban);
	cout << "Nhap he so luong: ";
	cin >> SalaryCo;
	cout << "Nhap phu cap: ";
	cin >> Extra;
}

void NV::Show()
{
	NGUOI::Show();
	cout << "Phong ban: " << Ban << endl << "He so luong: " << SalaryCo << endl << "Phu cap: " <<  Extra << endl;
}
