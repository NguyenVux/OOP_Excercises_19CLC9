#include "BT2.H"

void QuanLy::calcSalary()
{
	this->salary = this->salaryCo * this->base;
}

void QuanLy::outPut()
{
	cout << "Quan ly: ";
	NhanVien::outPut();
	cout  << "\t || Luong: " << this->salary << endl;
}

bool QuanLy::operator<(NhanVien& nhanvien)
{
	return dynamic_cast<QuanLy*>(&nhanvien) == nullptr;
}

bool QuanLy::operator>(NhanVien& nhanvien)
{
	return !(*this < nhanvien || *this == nhanvien);
}

bool QuanLy::operator==(NhanVien& nhanvien)
{
	return dynamic_cast<QuanLy*>(&nhanvien) != nullptr;;
}


void NVSanXuat::calcSalary()
{
	this->salary = this->products * 25000;
}

void NVSanXuat::addProducts(int prd)
{
	this->products += prd;
	this->calcSalary();
}

void NVSanXuat::outPut()
{
	cout << "NV San Xuat: ";
	NhanVien::outPut();
	cout << "\t || Luong: " << this->salary << endl;
}



bool NVSanXuat::operator<(NhanVien& nhanvien)
{
	return !(*this>nhanvien || *this == nhanvien);
}

bool NVSanXuat::operator>(NhanVien& nhanvien)
{
	return dynamic_cast<QuanLy*>(&nhanvien) != nullptr || dynamic_cast<NVCongNhat*>(&nhanvien) != nullptr;
}

bool NVSanXuat::operator==(NhanVien& nhanvien)
{
	return dynamic_cast<NVSanXuat*>(&nhanvien) != nullptr;
}

int NhanVien::getSalary()
{
	return this->salary;
}

void NhanVien::outPut()
{
	cout << this->Name;
}

void NVCongNhat::calcSalary()
{
	this->salary = this->days * 50000;
}

void NVCongNhat::addDaysOfWork(int days)
{
	this->days += days;
	this->calcSalary();
}
void NVCongNhat::outPut()
{
	cout << "NV Cong Nhat: ";
	NhanVien::outPut();
	cout << "\t || Luong: " << this->salary << endl;
}

bool NVCongNhat::operator<(NhanVien& nhanvien)
{
	return dynamic_cast<NVSanXuat*>(&nhanvien) != nullptr;
}

bool NVCongNhat::operator>(NhanVien& nhanvien)
{
	return dynamic_cast<QuanLy*>(&nhanvien) != nullptr;
}

bool NVCongNhat::operator==(NhanVien& nhanvien)
{
	return dynamic_cast<NVCongNhat*>(&nhanvien) != nullptr;
}

void Company::init(int number)
{
	srand(time(NULL));
	cin.ignore();
	for (int i = 0; i < number; i++)
	{
		int a = -1;
		while (!(a >= 0 && a <= 2))
		{
			cout << "Chon loai nhan vien: " << endl
				<< "0. Quan Ly" << endl
				<< "1. NV Cong Nhat" << endl
				<< "2. NV San Xuat" << endl;
			cin >> a;
		}
		cin.ignore();
		if (a == 0)
		{
			
			string name;
			cout << "Nhap ten Nhan vien: ";
			getline(cin, name);
			cout << "Nhap he so luong: ";
			float Co;
			cin >> Co;
			cout << "Nhap luong co ban: ";
			float base;
			cin >> base;
			QuanLy* ptr = new QuanLy(rand(),name,Co,base);
			vNhanVien.push_back(ptr);
		}
		else if (a == 1)
		{
			string name;
			cout << "Nhap ten Nhan vien: ";
			getline(cin, name);
			cout << "Nhap he so ngay cong: ";
			float Co;
			cin >> Co;
			NVCongNhat* ptr = new NVCongNhat(rand(), name);
			ptr->addDaysOfWork(Co);
			vNhanVien.push_back(ptr);
		}
		else if (a == 2)
		{
			string name;
			cout << "Nhap ten Nhan vien: ";
			getline(cin, name);
			cout << "Nhap he so san pham: ";
			float Co;
			cin >> Co;
			NVSanXuat* ptr = new NVSanXuat(rand(), name);
			ptr->addProducts(Co);
			vNhanVien.push_back(ptr);
		}
	
	}
}

void Company::addNhanVien()
{
	this->init(1);
}

void Company::sort()
{
	for (int i = 0; i < vNhanVien.size(); i++)
	{
		for (int j = 0; j < vNhanVien.size() - 1; j++)
		{
			if ((*vNhanVien[j]) > (*vNhanVien[j + 1]))
			{
				NhanVien* ptr = vNhanVien[j];
				vNhanVien[j] = vNhanVien[j + 1];
				vNhanVien[j + 1] = ptr;
			}
		}
	}
}

void Company::output()
{
	cout << "danh sach nhan vien: " << endl;
	for (auto i : vNhanVien)
	{
		i->outPut();
	}
}

void Company::ManagerCount()
{
	int k = 0;
	for (auto i : vNhanVien)
	{
		QuanLy* ptr = dynamic_cast<QuanLy*>(i);
		if (ptr != nullptr)
		{
			++k;
		}
	}
	cout << "So quan Ly: " << k;
}

Company::~Company()
{
	while (!vNhanVien.empty())
	{
		if (vNhanVien[vNhanVien.size() - 1] != nullptr)
		{
			delete vNhanVien[vNhanVien.size() - 1];
		}
		vNhanVien.pop_back();
	}
}
