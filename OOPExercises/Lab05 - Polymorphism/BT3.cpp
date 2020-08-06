#include "BT3.h"

string component::getID()
{
    return this->ID;
}

float component::getWeight()
{
    return this->weight;
}

float component::getPrice()
{
    return this->price;
}

void ComplexComponent::CalcWeight()
{
    for (auto i : ComponentList)
    {
        this->price += i->getPrice();
    }
    this->price *= 1.1;
}

void ComplexComponent::CalcPrice()
{
    for (auto i : ComponentList)
    {
        this->weight += i->getWeight();
    }
    this->weight *= 1.2;
}

void ComplexComponent::addComponent(component* Component)
{
    this->ComponentList.push_back(Component);
    CalcPrice();
    CalcWeight();
}

string ComplexComponent::findComponent(string ID, int level)
{
    for (auto i : ComponentList)
    {
        if (i->getID() == ID)
        {
            string r = "     ";
            string r2 = "";
            for (int i = 0; i < level; i++)
            {
                r2 += r;
            }

            return r2 + i->getID()+"\n" + r2+"  " +"Price:"+to_string(i->getPrice())+ "\n" + r2 + "  " + "Weight:" + to_string(i->getWeight());
        }
        else if (dynamic_cast<ComplexComponent*>(i) != nullptr)
        {
            string r = "     ";
            string r3 = "";
            for (int i = 0; i < level; i++)
            {
                r3 += r;
            }
            string rk = dynamic_cast<ComplexComponent*>(i)->findComponent(ID, level + 1);
            r3 += dynamic_cast<ComplexComponent*>(i)->getID() + "\n"+rk;
            if (rk == "")
            {
                continue;
            }
            return r3 ;
        }
    }
    return "";
}

ComplexComponent::~ComplexComponent()
{
    for (auto i : ComponentList)
    {
        if (i != nullptr)
        {
            delete i;
        }
    }
}

void SingleComponent::setPrice(int price)
{
    this->price = price;
}

void SingleComponent::setWeight(float weight)
{
    this->weight = weight;
}

void Machine::AddComponent(component* cp)
{
    ComponentList.push_back(cp);
}

int Machine::getPrice()
{
    int price = 0;
    for (auto i : ComponentList)
    {
        price += i->getPrice();
    }
    return price;
}

float Machine::getWeight()
{
    float result = 0;
    for (auto i : ComponentList)
    {
        result += i->getWeight();
    }
    return 0.0f;
}

void Machine::findComponent(string ID)
{
    string result;
    for (auto i : ComponentList)
    {
        if (i->getID() == ID)
        {

            cout <<  i->getID() + "\n" + "  " + "Price:" + to_string(i->getPrice()) + "\n" + "  " + "Weight:" + to_string(i->getWeight());
        }
        else if (dynamic_cast<ComplexComponent*>(i) != nullptr)
        {
            string r = (dynamic_cast<ComplexComponent*>(i)->findComponent(ID, 1));
            cout <<( r==""?"Component not found":i->getID() + "\n"+r);
        }
    }
}

Machine::~Machine()
{
    for (auto i : ComponentList)
    {
        if (i != nullptr)
        {
            delete i;
        }
    }
}
