#pragma once
#include "Monster.h"
#include <iostream>
#include <vector>
using namespace std;
#define POWER_TO_IMMORTAL_LEVEL_RATIO 200
enum class IMMORTAL_LEVEL {
	LIAN_QI = 1,
	ZHU_JI,
	JIE_DAN,
	YUAN_YING,
	HUA_SHEN,
	LIAN_XV,
	HE_TI,
	DA_CHENG,
	DU_JIE,
	IMMORAL_LEVEL_CNT
};
class Monster;
class Immortal
{
public:
	Immortal(string name = "",//Ϊɶ��const char??
		IMMORTAL_LEVEL level = IMMORTAL_LEVEL::LIAN_QI,
		string faction = "");
	bool alive;

	void mining();//�ڿ�
	//���г�������������
	bool trade();
	//���г�����ָ������
	bool trade(const Monster& monster);//�ǵ�ʹ�ñ���,���⿽���������¶����˷�����
	//����ָ�����޸�����������
	bool trade(Monster& monster, Immortal& other);
	//�����������ߴ�����ָ������
	bool trade(Immortal& otherImmortal, Monster& monster);
	//�����������߽����ȼ���ͬ�Ĳ�ͬ����
	bool trade(Monster& monster, Immortal& aImmortal, Monster& aMonster);

	//��������,����ս������������
	void fight(Monster& monster);

	//��ȡս����ֵ--�Զ����㷨
	int getPower()const;

private:
	string name;
	IMMORTAL_LEVEL level;
	string faction;
	vector<SpriteStone> stones;//��ʯ�ʲ�
	vector<Monster> monsters;//�����ʲ�
	friend ostream& operator<<(ostream& os, const Immortal& immortal);

	bool hasMonster(const Monster& monster)const;//ָ������������public�����ж��õ�,�ʶ���һ���ڲ�����Ѱ��ָ������
	void removeMonster(const Monster& monster);//���Ƴ�ָ������

	void dead();
};

ostream& operator<<(ostream& os, const Immortal& immortal);
ostream& operator<<(ostream& os, const IMMORTAL_LEVEL& level);//����Ҫ�������ݳ�Ա,�ʲ��趨��Ϊfriend��
