#include <iostream>
#include <string>

using namespace std;

class Person
{
protected:
	string pName;
	string pAdress;
	string pPhoneNumber;
public:
	Person()
	{
		pName = "Default";
		pAdress = "Default";
		pAdress = "Default";
	}
	Person(string name, string address, string phoneNumber)
	{
		pName = name;
		pAdress = address;
		pPhoneNumber = phoneNumber;
	}

	void setName(string name)
	{
		pName = name;
	}
	void setAdress(string add)
	{
		pAdress = add;
	}
	void setPhoneNumber(string phone)
	{
		pPhoneNumber = phone;
	}

	string getName()
	{
		return pName;
	}
	string getAddress()
	{
		return pAdress;
	}
	string getPhoneNumber()
	{
		return pPhoneNumber;
	}
};

class Customer : public Person
{
protected:
	const int CustomerNumber;
	Customer* Spouse;
	bool isOnMailingList;
public:
	Customer(int ID, bool mailingList = false) :Person(),isOnMailingList(mailingList),CustomerNumber(ID) {
		Spouse = nullptr;
	}
	Customer(int ID, bool mailingList,Customer& Sp) :Person(), isOnMailingList(mailingList), CustomerNumber(ID),Spouse(&Sp) {
	}

	Customer(string name, string address, string phoneNumber,int ID,bool mailingList = false) :Person(name, address, phoneNumber),CustomerNumber(ID), isOnMailingList(mailingList)
	{
		Spouse = nullptr;
	}
	Customer(string name, string address, string phoneNumber, int ID, bool mailingList,Customer& Sp) :Person(name, address, phoneNumber), CustomerNumber(ID), isOnMailingList(mailingList), Spouse(&Sp)
	{
	}

	void setSpouse(Customer& sp)
	{
		this->Spouse = &sp;
	}
	Customer& getSpouse()
	{
		return *(this->Spouse);
	}

	void toggleMailingStatus()
	{
		this->isOnMailingList = !this->isOnMailingList;
	}
	bool getMailingStatus()
	{
		return this->isOnMailingList;
	}
	int getCustomerNumber()
	{
		return this->CustomerNumber;
	}
};

class PreferredCustomer:public Customer
{
private:
	float totalPurchase = 0;
	float currentDiscount = 0.0f;
public:
	PreferredCustomer(int ID, bool mailingList = false) : Customer(ID, mailingList) {}
	PreferredCustomer(int ID, bool mailingList, Customer& Sp) :Customer(ID, mailingList, Sp) {}
	PreferredCustomer(string name, string address, string phoneNumber, int ID, bool mailingList = false) :Customer (name, address, phoneNumber, ID, mailingList) {}
	PreferredCustomer(string name, string address, string phoneNumber, int ID, bool mailingList, Customer& Sp) :Customer( name, address, phoneNumber, ID, mailingList, Sp) {}
	float getDiscount()
	{
		return this->currentDiscount;
	}
	float getTotalPurchase()
	{
		return this->totalPurchase;
	}
	void addPurchase(int amount)
	{
		PreferredCustomer* ptr = static_cast<PreferredCustomer*>(Spouse);
		this->totalPurchase +=(float)amount - (float)amount * currentDiscount;
		if (ptr != nullptr && totalPurchase + ptr->getTotalPurchase() >= 2500)
		{
			this->currentDiscount = 0.15f;
		}else if (totalPurchase >= 2000)
		{
			this->currentDiscount = 0.10f;
		}else if(totalPurchase >= 1500)
		{
			this->currentDiscount = 0.07f;
		}
		else if (totalPurchase >= 1000)
		{
			this->currentDiscount = 0.06f;
		}
		else if (totalPurchase >= 500)
		{
			this->currentDiscount = 0.05f;
		}
	}

};



int main()
{
	PreferredCustomer Van(1), Khang(2), Lam(3);
	Lam.setName("Lam");
	Van.setName("van");
	Van.setSpouse(Lam);
	Lam.setSpouse(Van);
	Khang.setName("Khang");
	Van.addPurchase(700);
	Khang.addPurchase(850);
	Lam.addPurchase(850);

	Van.addPurchase(700);	
	Khang.addPurchase(750);
	Lam.addPurchase(750);
	
	
	Lam.addPurchase(2000);
	Van.addPurchase(1500);	
	Khang.addPurchase(2000);
	cout << "Total purchase of Van, Lam, Khang: " << Lam.getTotalPurchase() + Khang.getTotalPurchase() + Van.getTotalPurchase() << endl;
	return 0;
}