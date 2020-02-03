#include "Mother.h"

Mother::Mother(string food, string name, int age)
{
	this->food = food;
	this->name = name;
	this->age = age;
	cout << __FUNCTION__ << "带参数" << endl;
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
	ret << "姓名:" << name << ",年龄:" << age << ",喜欢的食物:" << food << endl;
	return ret.str();
}
