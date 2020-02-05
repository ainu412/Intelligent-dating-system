#include "Single.h"

Single::Single(string name = "", int age = 0) {
	this->name = name;
	this->age = age;
}
string Single::getName()const {
	return name;
}
int Single::getAge()const {
	return age;
}
