#pragma once
#include "Father.h"//??
#include "Mother.h"
class Son: public Mother, public Father//因为要写Father,所有Father的用法也要继承
{public:
	//Son();//默认调用父亲私人信息
	Son(string name = "未知姓名", int age = 0, string food="未知食物", string game = "未知游戏");
	~Son();

	string getGame();
	//string description();

private:
	string game;
};