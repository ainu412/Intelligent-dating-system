#pragma once
#include "Father.h"//??

class Son:private Father//��ΪҪдFather,����Father���÷�ҲҪ�̳�
{public:
	//Son();//Ĭ�ϵ��ø���˽����Ϣ
	Son(string name = "δ֪����", int age = 0, string game = "δ֪��Ϸ");
	~Son();

	string getGame();
	string description();

private:
	string game;
};