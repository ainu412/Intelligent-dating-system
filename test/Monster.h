#pragma once
#include "SpriteStone.h"
#include "Immortal.h"
#define POWER_TO_MONSTER_LEVEL_RATIO 1000
#define POWER_TO_OWNED_MONSTER_LEVEL_RATIO 20
enum class MONSTER_LEVEL {
	ONE = 1,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	MONSTER_LEVEL_CNT = NINE
};
class Monster
{
public:
	Monster(MONSTER_LEVEL level = MONSTER_LEVEL::ONE, string category = "");
	
	SpriteStone getValue() const;
	bool operator==(const Monster& other)const;
	int getPower()const;

private:
	string category;
	MONSTER_LEVEL level;

	friend ostream& operator<<(ostream& os, const Monster monster);

};

ostream& operator<<(ostream& os, const Monster monster);