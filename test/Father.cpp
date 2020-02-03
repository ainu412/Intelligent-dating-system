#include "Father.h"

Father::Father()
{
	name = "未知父亲姓名";
	age = 0;
	cout << __FUNCTION__ <<"不带参数"<< endl;
}

Father::Father(string name, int age)
{
	this->name = name;
	this->age = age;
	cout << __FUNCTION__ <<"带参数"<< endl;
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
	ret << "姓名:" << name << ",年龄:" << age << endl;
	return ret.str();
}
