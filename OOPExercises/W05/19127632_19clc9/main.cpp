#include "PS2.h"
#include "CP2.h"
#include "NV.h"
#include <iostream>
using namespace std;


void Ex01()
{
	cout << "==============  Ex02 =============="<< endl;
	PS2 a(0,1), b(0,1);
	cout << "Nhap phan so thu nhat: " << endl;
	cin >> a;
	cout << "Nhap phan so thu hai: " << endl;
	cin >> b;
	PS2 c = a + b;
	cout << c << endl;
	cout << ((a > b) ? "a > b" : "a <= B") << endl;
	cout << "===================================" << endl;
}
void Ex02()
{
	cout << "==============  Ex03 ==============" << endl;
	CP2 a,b;
	cout << "Nhap So phuc thu nhat: " << endl;
	cin >> a;
	cout << "Nhap So phuc thu hai: " << endl;
	cin >> b;
	CP2 r1 = a + b;
	CP2 r2 = a - b;
	CP2 r3 = a * b;
	CP2 r4 = a / b;
	cout << a << "+" << b << " = " << r1 << endl;
	cout << a << "-" << b << " = " << r2 << endl;
	cout << a << "*" << b << " = " << r3 << endl;
	cout << a << "/" << b << " = " << r4 << endl;
	cout << "===================================" << endl;
}

int main()
{
	Ex01();
	Ex02();
	return 0;
}