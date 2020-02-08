#include "Single.h"
Single::Single(string name = "", int age = 0)
	   : name(name),age(age){}

string Single::getName()const {
	return name;
}
int Single::getAge()const {
	return age;
}
