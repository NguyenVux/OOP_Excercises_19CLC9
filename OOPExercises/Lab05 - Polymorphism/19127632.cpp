#include "Sphere.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Triangle.h"
#include "BT2.H"
#include "BT3.h"
#include "BT04.h"

using namespace std;
void Ex01()
{
	cout << "==========================Ex01================================" << endl;
	vector<Shape*> vShape;
	int choice = 0;
	while (choice != 4)
	{
		system("cls");
		cout << "0.Add Circle" << endl << "1. Add Rec" << endl << "2. add Square" << endl << "3.Add Triangle" << endl << "4.Next" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
		{
			float rad;
			cout << "Enter Radius:";
			cin >> rad;
			vShape.push_back(new Circle(rad));
			break;
		}
		case 1:
		{
			float h, w;
			cout << "Enter Height:";
			cin >> h;
			cout << "Enter Width:";
			cin >> w;
			vShape.push_back(new Rectangle(h, w));
			break;
		}
		case 2:
		{
			float h;
			cout << "Enter Edge size:";
			cin >> h;
			vShape.push_back(new Square(h));
			break;
		}
		case 3:
		{
			float h;
			cout << "Enter Edge size:";
			cin >> h;
			vShape.push_back(new EqTriangle(h));
			break;
			break;
		}
		default:
			break;
		}
	}
	for (auto i : vShape)
	{
		if (dynamic_cast<Circle*>(i) != nullptr)
		{
			cout << "Circle: " << endl;
		}
		if (dynamic_cast<Rectangle*>(i) != nullptr)
		{
			if (dynamic_cast<Square*>(i) != nullptr)
			{
				cout << "Square: " << endl;
			}
			else
			{
				cout << "Rectangle: " << endl;
			}

		}

		if (dynamic_cast<EqTriangle*>(i) != nullptr)
		{
			cout << "EqTriangle: " << endl;
		}
		cout << "Surface: " << i->CalcSurface() << endl << "Perimeter: " << i->CalcPerimeter();
	}
	for (auto i : vShape)
	{
		delete i;
	}
	cout << "================================================================" << endl;
}

void Ex02()
{
	cout << "==========================Ex02================================" << endl;
	Company congTy;
	int num;
	cout << "Nhap so nhan vien: ";
	cin >> num;
	congTy.init(num);
	cout << "Them mot nhan vien" << endl;
	congTy.addNhanVien();
	congTy.sort();
	cout << endl;
	congTy.output();
	cout << endl;
	congTy.ManagerCount();
	cout << "================================================================" << endl;
}

ComplexComponent* addComplex()
{
	srand(time(NULL));
	string ID;
	cout << "Enter Component ID: ";
	cin >> ID;
	ComplexComponent* c = new ComplexComponent(ID);
	int count1;
	cout << "How many components your Complex machine has? ";
	cin >> count1;
	for (int i = 0; i < count1; i++)
	{
		int choice = -1;
		while (choice < 0 || choice > 1)
		{
			system("cls");
			cout << "Select your component type" << endl;
			cout << "0.Single Component" << endl << "1. Complex Component" << endl;
			cin >> choice;
		}
		if (choice == 0)
		{
			cout << "Enter Component ID: ";
			cin >> ID;
			SingleComponent* s = new SingleComponent(ID);
			int price, weight;
			cout << "Enter Weight: ";
			cin >> weight;
			cout << "Enter Price: ";
			cin >> price;
			s->setPrice(price);
			s->setWeight(weight);
			c->addComponent(s);
		}
		else
		{
			c->addComponent(addComplex());
		}

	}
	return c;
}
void Ex03()
{
	int count;
	cout << "How many components your machine has? ";
	cin >> count;
	Machine m;
	for (int i = 0; i < count; i++)
	{
		int choice = -1;
		while (choice < 0 || choice > 1)
		{
			system("cls");
			cout << "Select your component type" << endl;
			cout << "0.Single Component" << endl << "1. Complex Component" << endl;
			cin >> choice;
		}
		if (choice == 0)
		{
			string ID;
			cout << "Enter Component ID: ";
			cin >> ID;
			SingleComponent* s = new SingleComponent(ID);
			int price, weight;
			cout << "Enter Weight: ";
			cin >> weight;
			cout << "Enter Price: ";
			cin >> price;
			s->setPrice(price);
			s->setWeight(weight);
			m.AddComponent(s);
		}
		else
		{
			m.AddComponent(addComplex());
		}

	}
	cout << "Which Component you want to find? " << endl;
	string ID;
	cin >> ID;
	m.findComponent(ID);
	cout << "Machine Weight: " << m.getWeight();
	cout << "Machine Price: " << m.getPrice();
}

Folder* addFolder()
{
	Folder* f = new Folder;
	cout << "Enter Folder name: ";
	string name;
	getline(cin, name);
	f->setName(name);
	int choice = -1;
	while (choice != 2)
	{
		system("cls");
		cout << "Would you like to add Anything to your folder?\n 0.Add File\n1.Add Folder\n2.Exit\n";
		cin >> choice;
		cin.ignore();
		if (choice == 0)
		{
			File* ptr = new File();
			cout << "Enter File name: ";
			string name;
			getline(cin, name);
			cout << "Enter File size: ";
			int size;
			cin >> size;
			ptr->setName(name);
			ptr->setSize(size);
			f->addStorageUnit(ptr);
		}
		else if(choice == 1)
		{
			f->addStorageUnit(addFolder());
		}
	}
	return f;
}
void Ex04()
{
	Folder root;
	root.setName("C");
	int choice = -1;
	while (choice != 4)
	{
		system("cls");
		cout << "0.Add File\n1.Add Folder\n2.View Directory tree\n3.Count Item in Folder\n4.Exit\n";
		cin >> choice;
		cin.ignore();
		if (choice == 0)
		{
			File* ptr = new File();
			cout << "Enter File name: ";
			string name;
			getline(cin, name);
			cout << "Enter File size: ";
			int size;
			cin >> size;
			ptr->setName(name);
			ptr->setSize(size);
			root.addStorageUnit(ptr);
		}
		else if( choice == 1)
		{
			root.addStorageUnit(addFolder());
			
		}
		else if (choice == 2)
		{
			root.outPut(0);
			system("pause");
		}
		else if(choice == 3)
		{
			cout << "Enter Folder name: ";
			string name;
			getline(cin, name);
			Folder *ptr = root.FindFolder(name);
			if (ptr == nullptr)
			{
				cout << "Folder not found" << endl;
			}
			else
			{
				cout << "There are " << ptr->countItem() << " files and folders";
			}
			system("pause");
		}
	}

}
int main()
{
	Ex01();
	Ex02();
	Ex03();
	Ex04();
	return 0;
}