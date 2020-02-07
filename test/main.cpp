#include "SpriteStone.h"
#include "Monster.h"
#include "Immortal.h"

void testSpriteStone() {
	SpriteStone s(100, SPRITESTONE_LEVEL::ADVANCED_LEVEL);
	cout << s << endl;
}
void testMonster() {
	Monster m(MONSTER_LEVEL::FOUR, "������");
	cout << m << endl;
}
void testImmortal() {
	Immortal zy("����", IMMORTAL_LEVEL::DU_JIE, "����");
	cout << "��ʼʱ:" << zy << endl;
	for (int i = 0; i < 2000; i++) {
		zy.mining();
	}
	cout << "<<�ڿ�2000�κ�:" << zy << endl;
	Monster m1(MONSTER_LEVEL::ONE, "111");
	Monster m2(MONSTER_LEVEL::TWO, "222");
	Monster m3(MONSTER_LEVEL::ONE, "333");
	zy.fight(m1);
	zy.fight(m2);
	zy.fight(m3);
	cout << "ս����ֻ���޺�:" << zy << endl;
	zy.trade(m1);
	cout << "���г�����m1��:" << zy << endl;
	zy.trade();
	cout << "����ȫ�����޺�:" << zy << endl;

	Immortal rr("����", IMMORTAL_LEVEL::DA_CHENG, "����");
	Monster m4(MONSTER_LEVEL::ONE, "444");
	Monster m5(MONSTER_LEVEL::ONE, "555");
	rr.fight(m4);
	rr.fight(m5);
	cout << "ս����ֻ���޺�:" << rr << endl;
	rr.trade(m4, zy);
	cout << "����һֻ���޺�:" << zy << endl;
	cout << "�۳�һֻ���޺�:" << rr << endl;

	zy.trade(m4, rr, m5);
	cout << "�������޺�:" << zy << endl << rr;
}
int main() {

	testSpriteStone();
	testMonster();
	testImmortal();


	return 0;
}

//ostream<<�ǵðѶ�����const��,��ֹ���ʱ�����޸�
//operator+ʱҲ�Ѳ���const��,��Ӻ�������this�� �½�һ������
//���ı����ڶ���ĺ���const��,����const����