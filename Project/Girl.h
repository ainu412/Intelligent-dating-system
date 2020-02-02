#pragma once
#include <iostream>
using namespace std;
class Boy;

class Girl{
public:
	Girl();
	Girl(string name, int age, int faceScore);

	string getName()const;
	int getAge()const;
	int getFaceScore()const;
	bool satisfied(const Boy& boy)const;
	string description()const;

private:
	string name;
	int age;
	int faceScore;//��ֵ
};

