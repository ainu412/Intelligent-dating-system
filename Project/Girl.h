#pragma once
#include <iostream>
#include <vector>
#include "Single.h"
using namespace std;
class Boy;
class Girl:public Single{
public:
	Girl();
	Girl(string name, int age, int faceScore);

	int getFaceScore()const{
		return faceScore;
	}
	bool satisfied(const Boy& boy)const;
	string description()const;

	static void inputGirls(vector<Girl>& girls);

private:
	int faceScore;//—’÷µ
};