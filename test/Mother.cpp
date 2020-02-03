#include "Mother.h"

Mother::Mother(string food, string name, int age)
{
	this->food = food;
	this->name = name;
	this->age = age;
	cout << __FUNCTION__ << "������" << endl;
}

Mother::~Mother()
{
	cout << __FUNCTION__ << endl;
}

string Mother::getName()
{
	return name;
}

int Mother::getAge()
{
	return age;
}

string Mother::description()
{
	stringstream ret;
	ret << "����:" << name << ",����:" << age << ",ϲ����ʳ��:" << food << endl;
	return ret.str();
}
