#include "SpriteStone.h"

SpriteStone::SpriteStone(int cnt, SPRITESTONE_LEVEL level) {
	this->cnt = cnt;
	this->level = level;
}

string SpriteStone::str()const
{
	stringstream ret;
	ret << cnt << "块";
	switch (level) {
	case SPRITESTONE_LEVEL::PRIMARY_LEVEL:
		ret << "初阶";
		break;
	case SPRITESTONE_LEVEL::INTERMIDIATE_LEVEL:
		ret << "中阶";
		break;
	case SPRITESTONE_LEVEL::ADVANCED_LEVEL:
		ret << "高阶";
		break;
	default:
		ret << "未知";
		break;
	}
	ret << "灵石";//暂未加回车符
	return ret.str();
}

//若返回的是引用灵石,则不可创建新量->返回自己即可(引用必须是已存在量)
SpriteStone& SpriteStone::operator+(const SpriteStone& otherStone)//返回的若是新建的灵石,则可创建新量
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
		cerr << "未知灵石交易" << endl;
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
		cerr << "未知灵石交易" << endl;
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
		cerr << "未知灵石交易" << endl;
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
		cerr << "未知灵石交易" << endl;
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
		cerr << "未知灵石交易" << endl;
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
		cerr << "未知灵石交易" << endl;
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
		cerr << "未知灵石交易" << endl;
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
		cerr << "未知灵石交易" << endl;
		break;
	}
	return cnt == sum;
}

ostream& operator<<(ostream& os, const SpriteStone& stone)
{
	os << stone.str();
	return os;
}
