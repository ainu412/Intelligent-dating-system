#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Father
{public:
	//Father();
	Father(string name = "δ֪����", int age = 0);
	~Father();

	string getName();
	int getAge();
	string description();

	void ball() {
		cout << "�ְ�ϲ������" << endl;
	}
protected:
	string name;
private:
	int age;
};

