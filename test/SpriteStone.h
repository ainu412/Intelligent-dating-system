#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

enum class SPRITESTONE_LEVEL {
	PRIMARY_LEVEL,
	INTERMIDIATE_LEVEL,
	ADVANCED_LEVEL,
	SPRITE_STONE_LEVEL_CNT
};

class SpriteStone
{
public:
	SpriteStone(int cnt = 0, SPRITESTONE_LEVEL level = SPRITESTONE_LEVEL::PRIMARY_LEVEL);
	string str()const;

	SpriteStone& operator+(const SpriteStone& otherStone);
	bool operator>=(const SpriteStone& otherStone);
	SpriteStone& operator-(const SpriteStone& otherStone);
	bool operator==(const SpriteStone& otherStone);

private:
	int cnt;
	SPRITESTONE_LEVEL level;

	friend ostream& operator<<(ostream& os, const SpriteStone& stone);
};

ostream& operator<<(ostream& os, const SpriteStone& stone);