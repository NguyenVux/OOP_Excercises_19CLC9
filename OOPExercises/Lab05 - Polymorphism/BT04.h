#ifndef _BT04_H
#define _BT04_H
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class StorageUnit
{
protected:
	string name;
	int size;
public:
	StorageUnit() {}

	int getSize();
	void setName(string name);
	string getName();
	virtual void setSize(int size) = 0;
};

class File :public StorageUnit
{
public:
	File() :StorageUnit() {}
	void setSize(int size);
};

class Folder :public StorageUnit
{
private:
	vector<StorageUnit*> ChildNode;
public:
	Folder() :StorageUnit() {}
	void setSize(int size);
	void CalcSize();
	void addStorageUnit(StorageUnit* unit);
	void outPut(int level);
	int countItem();
	Folder* FindFolder(string name);
	~Folder();

};
#endif