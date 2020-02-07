#include "Monster.h"

Monster::Monster(MONSTER_LEVEL level, string category)
{
	this->level = level;
	this->category = category;
}

SpriteStone Monster::getValue()const//�����µ���ʯ����/ָ���ں������ڶ������ʯ
{
	if (int(level) > int(MONSTER_LEVEL::MONSTER_LEVEL_CNT)) {
		cerr << "���޼��𳬹��趨��" << int(MONSTER_LEVEL::MONSTER_LEVEL_CNT) << "��!" << endl;
		exit(1);
	}
	//��ͬ�����ֵ������ʯ��-�ɶ����ֵ��ʯ���൱��ս����
	int stoneCnt[int(MONSTER_LEVEL::MONSTER_LEVEL_CNT)] = { 100, 200, 500, 1000,2000,5000,10000,20000,100000 };

	return SpriteStone(stoneCnt[int(level)-1]);//ע���Ƿ񳬹�int��
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
	os << int(monster.level) << "����" << monster.category;
	return os;
}
