#pragma once
#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Single {
public:
	Single();
	Single(string name, int age);

	string getName()const;
	int getAge()const;

protected:
	string name;
	int age;
};


