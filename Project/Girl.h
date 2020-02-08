#pragma once
#include <iostream>
#include <vector>
#include "Single.h"
using namespace std;
class Boy;

class Girl:public Single{
public:
	Girl(string name = "", int age = 0, int faceScore = 0);

	int trait()const{
		return faceScore;
	}
	bool satisfied(const Boy& boy)const;
	//string Girl::description()const;
	bool operator>(const Girl& girl)const;
	friend ostream& operator<<(ostream& os, const Girl& girl);

	static void inputGirls(vector<Girl>& girls);

private:
	int faceScore;//бежЕ
};
ostream& operator<<(ostream& os, const Girl& girl);