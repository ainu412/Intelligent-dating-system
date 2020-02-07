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
	Immortal(string name = "",//为啥用const char??
		IMMORTAL_LEVEL level = IMMORTAL_LEVEL::LIAN_QI,
		string faction = "");
	bool alive;

	void mining();//挖矿
	//在市场售卖所有妖兽
	bool trade();
	//在市场售卖指定妖兽
	bool trade(const Monster& monster);//记得使用别名,避免拷贝或生成新对象浪费性能
	//售卖指定妖兽给其他修仙者
	bool trade(Monster& monster, Immortal& other);
	//从其他修仙者处购买指定妖兽
	bool trade(Immortal& otherImmortal, Monster& monster);
	//和其他修仙者交换等级相同的不同妖兽
	bool trade(Monster& monster, Immortal& aImmortal, Monster& aMonster);

	//捕获妖兽,根据战斗力捕获妖兽
	void fight(Monster& monster);

	//获取战斗力值--自定义算法
	int getPower()const;

private:
	string name;
	IMMORTAL_LEVEL level;
	string faction;
	vector<SpriteStone> stones;//灵石资产
	vector<Monster> monsters;//妖兽资产
	friend ostream& operator<<(ostream& os, const Immortal& immortal);

	bool hasMonster(const Monster& monster)const;//指定妖兽在三个public功能中都用到,故定义一个内部方法寻找指定妖兽
	void removeMonster(const Monster& monster);//并移除指定妖兽

	void dead();
};

ostream& operator<<(ostream& os, const Immortal& immortal);
ostream& operator<<(ostream& os, const IMMORTAL_LEVEL& level);//不需要访问数据成员,故不需定义为friend类
