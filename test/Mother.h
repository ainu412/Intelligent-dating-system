#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Mother
{public:
	Mother(string food = "δ֪ʳ��", string name = "δ֪����", int age = 0);//�Ѹ��׵Ķ������д�ں���,��ֻ�ܴӺ���ǰʡ��Ĭ�ϲ���
	~Mother();

	string getName();
	int getAge();
	string description();

	void dance(){
		cout << "����ϲ������" << endl;
	}

protected:
	string name;
private:
	int age;
	string food;
};
