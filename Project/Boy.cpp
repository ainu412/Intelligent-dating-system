#include "Boy.h"
#include <sstream>
#include "Girl.h"

#define SALARY_COEFFICIENT 0.006
Boy::Boy() {
	name = "";
	age = 0;
	salary = 0;
}
Boy::Boy(string name, int age, int salary) {
	this->name = name;
	this->age = age;
	this->salary = salary;
}
string Boy::getName()const {
	return name;
}

int Boy::getAge()const {
	return age;
}

int Boy::getSalary()const {
	return salary;
}

bool Boy::satisfied(const Girl& girl)const
{	
	if (girl.getFaceScore() > salary* SALARY_COEFFICIENT) return true;
	return false;
}

string Boy::description()const
{
	stringstream ret;
	ret << "��:����(" << name << "),����(" << age << "),н��(" << salary << ").";//����ret;cout<<xxx,Ϊ��xxx�������̨���
	return ret.str();
}