#pragma once
#include "Father.h"//??
#include "Mother.h"
class Son: public Mother, public Father//��ΪҪдFather,����Father���÷�ҲҪ�̳�
{public:
	//Son();//Ĭ�ϵ��ø���˽����Ϣ
	Son(string name = "δ֪����", int age = 0, string food="δ֪ʳ��", string game = "δ֪��Ϸ");
	~Son();

	string getGame();
	//string description();

private:
	string game;
};