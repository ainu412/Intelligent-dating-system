#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Single {
public:
	Single(string name, int age);

	string getName()const;
	int getAge()const;

	virtual int trait()const = 0;

protected:
	string name;
	int age;
};

