#pragma once
#include <iostream>
#include <vector>
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

	static void inputGirls(vector<Girl>& girls);

private:
	string name;
	int age;
	int faceScore;//—’÷µ
};

