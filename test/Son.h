#pragma once
#include "Father.h"//??
#include "Mother.h"
class Son: public Father,public Mother//��:��ΪҪдFather,����Father���÷�ҲҪ�̳�
{public:
	//Son();//Ĭ�ϵ��ø���˽����Ϣ
	Son(string name = "δ֪����", int age = 0, string food="δ֪ʳ��", string game = "δ֪��Ϸ");
	~Son();

	string getGame();
	string description();
	void dance();
private:
	string game;
};