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

	int getSalary()const{
		return salary;
	}
	bool satisfied(const Girl& girl)const;
	string description()const;

	static void inputBoys(vector<Boy>& boys);//控制台中转至容器,容器中转至文件

private:
	int salary;
};



