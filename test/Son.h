#pragma once
#include "Father.h"//??

class Son:private Father
{public:
	Son();//默认调用父亲私人信息
	Son(string name, int age, string game);
	~Son();

	string getGame();
	string description();

private:
	string game;
};