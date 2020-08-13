#include "BT04.h"

string StorageUnit::getName()
{
	return this->name;
}

int StorageUnit::getSize()
{
	return this->size;
}


void StorageUnit::setName(string name)
{
	this->name = name;
}


void File::setSize(int size)
{
	this->size = size;
}

void Folder::setSize(int size)
{
}

void Folder::CalcSize()
{
	this->size = 0;
	for (auto i : ChildNode)
	{
		this->size += i->getSize();
	}
}

void Folder::addStorageUnit(StorageUnit* unit)
{
	ChildNode.push_back(unit);
	CalcSize();
}

void Folder::outPut(int level)
{
	for (int i = 0; i < level; i++)
	{
		cout << "     ";
	}
	cout << "[" +this->name + "]" << endl;
	for (auto i : ChildNode)
	{
		if (dynamic_cast<Folder*>(i) != nullptr)
		{
			dynamic_cast<Folder*>(i)->outPut(level + 1);
		}
		else
		{
			for (int i = 0; i < level + 1; i++)
			{
				cout << "     ";
			}
			cout << i->getName() << "     " << i->getSize() <<"B" << endl;
		}

	}

}

int Folder::countItem()
{
	int result = 0;
	for (auto i : ChildNode)
	{
		if (dynamic_cast<Folder*>(i) != nullptr)
		{
			result += dynamic_cast<Folder*>(i)->countItem()+1;
		}
		else
		{
			result += 1;
		}
	}
	return result;
}

Folder* Folder::FindFolder(string name)
{
	for (auto i : ChildNode)
	{
		
		if (dynamic_cast<Folder*>(i) != nullptr)
		{
			if (i->getName() == name)
			{
				return this;
			}
			else
			{
				return dynamic_cast<Folder*>(i)->FindFolder(name);
			}
		}
	}
	return nullptr;
}

Folder::~Folder()
{
	while (!ChildNode.empty())
	{
		if (ChildNode[ChildNode.size() - 1] != nullptr)
		{
			delete ChildNode[ChildNode.size() - 1];
		}
		ChildNode.pop_back();
	}
}



