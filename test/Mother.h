#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Mother
{public:
	Mother(string food = "未知食物", string name = "未知姓名", int age = 0);//把父亲的定义过的写在后面,因只能从后往前省略默认参数
	~Mother();

	string getName();
	int getAge();
	string description();

	void dance(){
		cout << "妈妈喜欢跳舞" << endl;
	}

protected:
	string name;
private:
	int age;
	string food;
};
