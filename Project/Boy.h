#pragma once
#include <iostream>
#include <vector>
#include "Single.h"
using namespace std;

class Girl;
class Boy:public Single{
public:
	Boy();
	Boy(string name, int age, int salary);

	int getSalary()const;
	bool satisfied(const Girl& girl)const;
	string description()const;

	static void inputBoys(vector<Boy>& boys);

private:
	int salary;
};



