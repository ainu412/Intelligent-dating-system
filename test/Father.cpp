#include "Father.h"

Father::Father()
{
	name = "δ֪��������";
	age = 0;
	cout << __FUNCTION__ <<"��������"<< endl;
}

Father::Father(string name, int age)
{
	this->name = name;
	this->age = age;
	cout << __FUNCTION__ <<"������"<< endl;
}

Father::~Father()
{
	cout << __FUNCTION__ << endl;
}

string Father::getName()
{
	return name;
}

int Father::getAge()
{
	return age;
}

string Father::description()
{
	stringstream ret;
	ret << "����:" << name << ",����:" << age << endl;
	return ret.str();
}
