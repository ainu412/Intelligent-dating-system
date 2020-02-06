#pragma once
#include <iostream>
#include <vector>
#include "Single.h"
using namespace std;
class Girl;

class Boy:public Single{
public:
	Boy(string name, int age, int salary);

	int getSalary()const{
		return salary;
	}
	bool satisfied(const Girl& girl)const;
	//string description()const;

	bool operator>(Boy& boy);

	static void inputBoys(vector<Boy>& boys);//����̨��ת������,������ת���ļ�

	friend ostream& operator<<(ostream& os, const Boy& boy);
private:
	int salary;
};
ostream& operator<<(ostream& os, const Boy& boy);



