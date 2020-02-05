#include "Single.h"
Single::Single() {
	name = "";
	age = 0;
}
Single::Single(string name, int age) {
	this->name = name;
	this->age = age;
}
string Single::getName()const {
	return name;
}
int Single::getAge()const {
	return age;
}