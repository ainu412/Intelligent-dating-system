#pragma once
#include "Father.h"//??

class Son:private Father
{public:
	Son();//Ĭ�ϵ��ø���˽����Ϣ
	Son(string name, int age, string game);
	~Son();

	string getGame();
	string description();

private:
	string game;
};