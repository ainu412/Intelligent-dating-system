#include "SpriteStone.h"

SpriteStone::SpriteStone(int cnt, SPRITESTONE_LEVEL level) {
	this->cnt = cnt;
	this->level = level;
}

string SpriteStone::str()const
{
	stringstream ret;
	ret << cnt << "��";
	switch (level) {
	case SPRITESTONE_LEVEL::PRIMARY_LEVEL:
		ret << "����";
		break;
	case SPRITESTONE_LEVEL::INTERMIDIATE_LEVEL:
		ret << "�н�";
		break;
	case SPRITESTONE_LEVEL::ADVANCED_LEVEL:
		ret << "�߽�";
		break;
	default:
		ret << "δ֪";
		break;
	}
	ret << "��ʯ";//��δ�ӻس���
	return ret.str();
}

//�����ص���������ʯ,�򲻿ɴ�������->�����Լ�����(���ñ������Ѵ�����)
SpriteStone& SpriteStone::operator+(const SpriteStone& otherStone)//���ص������½�����ʯ,��ɴ�������
{
	switch (level) {
	case SPRITESTONE_LEVEL::PRIMARY_LEVEL:
		break;
	case SPRITESTONE_LEVEL::INTERMIDIATE_LEVEL:
		cnt *= 10;
		break;
	case SPRITESTONE_LEVEL::ADVANCED_LEVEL:
		cnt *= 100;
		break;
	default:
		cerr << "δ֪��ʯ����" << endl;
		break;
	}
	level = SPRITESTONE_LEVEL::PRIMARY_LEVEL;
	switch (otherStone.level) {
	case SPRITESTONE_LEVEL::PRIMARY_LEVEL:
		cnt += otherStone.cnt;
		break;
	case SPRITESTONE_LEVEL::INTERMIDIATE_LEVEL:
		cnt += otherStone.cnt * 10;
		break;
	case SPRITESTONE_LEVEL::ADVANCED_LEVEL:
		cnt += otherStone.cnt * 100;
		break;
	default:
		cerr << "δ֪��ʯ����" << endl;
		break;
	}

	return *this;
}
bool SpriteStone::operator>=(const SpriteStone& otherStone)
{
	switch (level) {
	case SPRITESTONE_LEVEL::PRIMARY_LEVEL:
		break;
	case SPRITESTONE_LEVEL::INTERMIDIATE_LEVEL:
		cnt *= 10;
		break;
	case SPRITESTONE_LEVEL::ADVANCED_LEVEL:
		cnt *= 100;
		break;
	default:
		cerr << "δ֪��ʯ����" << endl;
		break;
	}
	int sum = 0;
	switch (otherStone.level) {
	case SPRITESTONE_LEVEL::PRIMARY_LEVEL:
		sum += otherStone.cnt;
		break;
	case SPRITESTONE_LEVEL::INTERMIDIATE_LEVEL:
		sum += otherStone.cnt * 10;
		break;
	case SPRITESTONE_LEVEL::ADVANCED_LEVEL:
		sum += otherStone.cnt * 100;
		break;
	default:
		cerr << "δ֪��ʯ����" << endl;
		break;
	}
	return cnt >= sum;
}
SpriteStone& SpriteStone::operator-(const SpriteStone& otherStone)
{
	switch (level) {
	case SPRITESTONE_LEVEL::PRIMARY_LEVEL:
		break;
	case SPRITESTONE_LEVEL::INTERMIDIATE_LEVEL:
		cnt *= 10;
		break;
	case SPRITESTONE_LEVEL::ADVANCED_LEVEL:
		cnt *= 100;
		break;
	default:
		cerr << "δ֪��ʯ����" << endl;
		break;
	}
	level = SPRITESTONE_LEVEL::PRIMARY_LEVEL;
	switch (otherStone.level) {
	case SPRITESTONE_LEVEL::PRIMARY_LEVEL:
		cnt -= otherStone.cnt;
		break;
	case SPRITESTONE_LEVEL::INTERMIDIATE_LEVEL:
		cnt -= otherStone.cnt * 10;
		break;
	case SPRITESTONE_LEVEL::ADVANCED_LEVEL:
		cnt -= otherStone.cnt * 100;
		break;
	default:
		cerr << "δ֪��ʯ����" << endl;
		break;
	}

	return *this;
}

bool SpriteStone::operator==(const SpriteStone& otherStone)
{
	switch (level) {
	case SPRITESTONE_LEVEL::PRIMARY_LEVEL:
		break;
	case SPRITESTONE_LEVEL::INTERMIDIATE_LEVEL:
		cnt *= 10;
		break;
	case SPRITESTONE_LEVEL::ADVANCED_LEVEL:
		cnt *= 100;
		break;
	default:
		cerr << "δ֪��ʯ����" << endl;
		break;
	}
	int sum = 0;
	switch (otherStone.level) {
	case SPRITESTONE_LEVEL::PRIMARY_LEVEL:
		sum += otherStone.cnt;
		break;
	case SPRITESTONE_LEVEL::INTERMIDIATE_LEVEL:
		sum += otherStone.cnt * 10;
		break;
	case SPRITESTONE_LEVEL::ADVANCED_LEVEL:
		sum += otherStone.cnt * 100;
		break;
	default:
		cerr << "δ֪��ʯ����" << endl;
		break;
	}
	return cnt == sum;
}

ostream& operator<<(ostream& os, const SpriteStone& stone)
{
	os << stone.str();
	return os;
}
