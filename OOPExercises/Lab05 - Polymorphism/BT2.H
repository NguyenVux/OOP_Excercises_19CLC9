#ifndef _BT2_H
#define _BT2_H
#include <iostream>
#include <string>
#include <random>
#include <time.h>
using namespace std;
class NhanVien
{
protected:
	const int ID;
	const string Name;
	int salary = 0;
public:
	NhanVien(int ID, string name) : ID(ID), Name(name) {}
	virtual void calcSalary() = 0;
	virtual int getSalary();
	virtual void outPut();
	virtual bool operator<(NhanVien& nhanvien) = 0;
	virtual bool operator==(NhanVien& nhanvien) = 0;
	virtual bool operator>(NhanVien& nhanvien) = 0;
};
class QuanLy : public NhanVien
{
private:
	float salaryCo;
	int base;
public:
	QuanLy(int ID, string Name,float salaryCo, int base) :NhanVien(ID, Name) {
		this->salaryCo = salaryCo;
		this->base = base;
		calcSalary();
	}
	void calcSalary();
	void outPut();
	bool operator<(NhanVien& nhanvien);
	bool operator>(NhanVien& nhanvien);
	bool operator==(NhanVien& nhanvien);
};

class NVSanXuat : public NhanVien 
{
private:
	int products = 0 ;
public:
	NVSanXuat(int ID, string Name) :NhanVien(ID, Name) {
	}
	void calcSalary();
	void addProducts(int prd);
	void outPut();
	bool operator<(NhanVien& nhanvien);
	bool operator>(NhanVien& nhanvien);
	bool operator==(NhanVien& nhanvien);
};

class NVCongNhat : public NhanVien
{
private:
	int days = 0;
public:
	NVCongNhat(int ID, string Name) :NhanVien(ID, Name) {
		
	}
	void calcSalary();
	void addDaysOfWork(int days);
	void outPut();
	bool operator<(NhanVien& nhanvien);
	bool operator>(NhanVien& nhanvien);
	bool operator==(NhanVien& nhanvien);
};
class Company
{
private:
	vector<NhanVien*> vNhanVien;
public:
	void init(int number);
	void addNhanVien();
	void sort();
	void output();
	void ManagerCount();
	~Company();
};
#endif // !_BT2_H
