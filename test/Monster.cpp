#include "Monster.h"

Monster::Monster(MONSTER_LEVEL level, string category)
{
	this->level = level;
	this->category = category;
}

SpriteStone Monster::getValue()const//创建新的灵石对象/指向在函数体内定义的灵石
{
	if (int(level) > int(MONSTER_LEVEL::MONSTER_LEVEL_CNT)) {
		cerr << "妖兽级别超过设定的" << int(MONSTER_LEVEL::MONSTER_LEVEL_CNT) << "级!" << endl;
		exit(1);
	}
	//不同级别价值初级灵石数-可定义价值灵石数相当于战斗力
	int stoneCnt[int(MONSTER_LEVEL::MONSTER_LEVEL_CNT)] = { 100, 200, 500, 1000,2000,5000,10000,20000,100000 };

	return SpriteStone(stoneCnt[int(level)-1]);//注意是否超过int型
}

bool Monster::operator==(const Monster& other) const
{
	if (level == other.level && category == other.category) {
		return true;
	}
	else {
		return false;
	}
}

int Monster::getPower()const
{
	return int(level)*POWER_TO_MONSTER_LEVEL_RATIO;
}

ostream& operator<<(ostream& os, const Monster monster)
{
	os << int(monster.level) << "级的" << monster.category;
	return os;
}
