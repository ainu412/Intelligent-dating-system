#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Father
{public:
	Father();
	Father(string name, int age);
	~Father();

	string getName();
	int getAge();
	string description();

protected:
	string name;
private:
	int age;
};

