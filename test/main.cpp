#include "SpriteStone.h"
#include "Monster.h"
#include "Immortal.h"

void testSpriteStone() {
	SpriteStone s(100, SPRITESTONE_LEVEL::ADVANCED_LEVEL);
	cout << s << endl;
}
void testMonster() {
	Monster m(MONSTER_LEVEL::FOUR, "肉肉妖");
	cout << m << endl;
}
void testImmortal() {
	Immortal zy("子怡", IMMORTAL_LEVEL::DU_JIE, "好人");
	cout << "初始时:" << zy << endl;
	for (int i = 0; i < 2000; i++) {
		zy.mining();
	}
	cout << "<<挖矿2000次后:" << zy << endl;
	Monster m1(MONSTER_LEVEL::ONE, "111");
	Monster m2(MONSTER_LEVEL::TWO, "222");
	Monster m3(MONSTER_LEVEL::ONE, "333");
	zy.fight(m1);
	zy.fight(m2);
	zy.fight(m3);
	cout << "战斗三只妖兽后:" << zy << endl;
	zy.trade(m1);
	cout << "在市场卖掉m1后:" << zy << endl;
	zy.trade();
	cout << "卖掉全部妖兽后:" << zy << endl;

	Immortal rr("肉肉", IMMORTAL_LEVEL::DA_CHENG, "坏人");
	Monster m4(MONSTER_LEVEL::ONE, "444");
	Monster m5(MONSTER_LEVEL::ONE, "555");
	rr.fight(m4);
	rr.fight(m5);
	cout << "战斗两只妖兽后:" << rr << endl;
	rr.trade(m4, zy);
	cout << "购买一只妖兽后:" << zy << endl;
	cout << "售出一只妖兽后:" << rr << endl;

	zy.trade(m4, rr, m5);
	cout << "交换妖兽后:" << zy << endl << rr;
}
int main() {

	testSpriteStone();
	testMonster();
	testImmortal();


	return 0;
}

//ostream<<记得把对象类const化,防止输出时对它修改
//operator+时也把参数const化,相加后结果返回this或 新建一个对象
//不改变所在对象的函数const化,方便const调用