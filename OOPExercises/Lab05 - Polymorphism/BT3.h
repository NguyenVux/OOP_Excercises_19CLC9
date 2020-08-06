#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class component
{
protected:
	int price = 0;
	float weight = 0;
	const string ID;
public:
	component(string ID) :ID(ID) {}
	string getID();
	virtual float getWeight();
	virtual float getPrice();

};

class ComplexComponent :public component {
	vector<component*> ComponentList;


	void CalcWeight();
	void CalcPrice();
public:
	ComplexComponent(string ID) : component(ID)
	{
	}
	void addComponent(component* Component);
	string findComponent(string ID, int level);
	~ComplexComponent();
};

class SingleComponent :public component {
public:
	SingleComponent(string ID) : component(ID)
	{
	}
	void setPrice(int price);
	void setWeight(float weight);
};

class Machine
{
private:
	vector<component*> ComponentList;
public:
	void AddComponent(component* cp);
	int getPrice();
	float getWeight();
	void findComponent(string ID);
	~Machine();
};

