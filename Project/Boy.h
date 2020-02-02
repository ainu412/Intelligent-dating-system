#pragma once
#include <iostream>
#include <vector>
using namespace std;
class Girl;

class Boy{
public:
	Boy();
	Boy(string name, int age, int salary);

	string getName()const;
	int getAge()const;
	int getSalary()const;
	bool satisfied(const Girl& girl)const;
	string description()const;

	static void inputBoys(vector<Boy>& boys);

private:
	string name;
	int age;
	int salary;
};



