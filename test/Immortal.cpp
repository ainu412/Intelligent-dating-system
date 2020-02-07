#include "Immortal.h"

Immortal::Immortal(string name, IMMORTAL_LEVEL level, string faction)
{
	this->name = name;
	this->level = level;
	this->faction = faction;
	alive = true;
}

void Immortal::mining()
{
	stones.push_back(SpriteStone(100));
}

bool Immortal::trade()
{
	if (!alive) { 
		cerr << "修仙者已死!交易失败!" << endl;
		return false; 
	}
	else {
		SpriteStone stone;
		for (unsigned int i = 0; i < monsters.size(); i++) {
			stone = stone + monsters[i].getValue();//stone＋运算符重载
		}

		stones.push_back(stone);
		//记得这是双向过程!获得灵石的同时,妖兽资产清空
		//monsters.erase(monsters.begin(), monsters.end());也可
		monsters.clear();

		return true;
	}
}

bool Immortal::trade(const Monster& monster)
{
	if (!hasMonster(monster)) {
		cerr << "没有指定妖兽!" << endl;
		return false;
	}
	else {
		stones.push_back(monster.getValue());
		removeMonster(monster);
		return true;
	}
}

bool Immortal::trade(Monster& monster, Immortal& other)
{
	if (!alive || !other.alive) {
		cerr << "交易方死亡!" << endl;
		return false;
	}
	else if (!hasMonster(monster)) {
		cerr << "您没有" << monster << endl;
		return false;
	}

	//计算折合后灵石量
	SpriteStone stone;
	for (unsigned int i = 0; i < other.stones.size(); i++) {
		stone = stone + other.stones[i];
	}
	if (stone >= monster.getValue()) {
		other.monsters.push_back(monster);

		stone = stone - monster.getValue();
		other.stones.clear();
		other.stones.push_back(stone);

		removeMonster(monster);
		stones.push_back(monster.getValue());

		return true;
	}
	else {
		cerr << "灵石不足!" << endl;
		return false;
	}
	cerr << "向" << other.name << "购买" << monster << "失败!" << endl;
	return false;
}

bool Immortal::trade(Immortal& other, Monster& monster)
{
	if (!alive || !other.alive) {
		cerr << "交易方死亡!" << endl;
		return false;
	}
	else if (!other.hasMonster(monster)) {
		cerr << "卖家" << other.name << "没有" << monster << endl;
		return false;
	}

	//计算折合后灵石量
	SpriteStone stone;
	for (unsigned int i = 0; i < stones.size(); i++) {
		stone = stone + stones[i];
	}
	if (stone >= monster.getValue()) {
		monsters.push_back(monster);

		stone = stone - monster.getValue();
		stones.clear();
		stones.push_back(stone);

		other.removeMonster(monster);
		other.stones.push_back(monster.getValue());

		return true;
	}
	else {
		cerr << "灵石不足!" << endl;
		return false;
	}
	cerr << "向" << other.name << "售卖" << monster << "失败!" << endl;
	return false;
}

bool Immortal::trade(Monster& monster, Immortal& other, Monster& aMonster)
{
	if (!alive || !other.alive) {
		cerr << "交易方已死!" << endl;
		return false;
	}
	else if (!hasMonster(monster)) {
		cerr << "您没有" << monster << "可供交换!" << endl;
		return false;
	}
	else if (!other.hasMonster(aMonster)) {
		cerr << other.name << "没有" << aMonster << "可供交换!" << endl;
		return false;
	}
	else if (monster == aMonster) {
		cerr << "不能交换完全相同的妖兽!" << endl;
		return false;
	}
	else if (monster.getValue() == aMonster.getValue()) {
		removeMonster(monster);
		other.removeMonster(aMonster);

		monsters.push_back(aMonster);
		other.monsters.push_back(monster);
		return true;
	}
	else {
		cerr << "不能交换等级不同的妖兽!" << endl;
		return false;
	}
	cerr << "交换失败!" << endl;
	return false;
}

void Immortal::fight(Monster& monster)
{
	if (getPower() >= monster.getPower()) {
		monsters.push_back(monster);
	}
	else {
		dead();
	}
}

int Immortal::getPower()const
{
	int power = 0;
	//加捕获妖兽的战斗力
	for (unsigned int i = 0; i < monsters.size(); i++) {
		power += monsters[i].getPower() / POWER_TO_MONSTER_LEVEL_RATIO * POWER_TO_OWNED_MONSTER_LEVEL_RATIO;
	}

	//加自己的战斗力
	power += (int(level) + 1) * POWER_TO_IMMORTAL_LEVEL_RATIO;//时刻注意自己的级别int(level)数字小1,以后为防止忘记,可以写=1

	return power;
}

bool Immortal::hasMonster(const Monster& exMonster)const//寻找有没有某一类的妖兽,不能用地址,因为只要是那一类就可以
{
	//vector<Monster>::iterator it = monsters.begin();
	//for (auto it = monsters.begin(); it != monsters.end;) {
		//if (*it == &exMonster) {//这里不行了,因为行的时候it存为vector<Human>* friends存的是指针,指针解引就是地址
								//故存的应改为指针,指向拥有的妖兽(聚合关系)
	for (unsigned int i=0;i<monsters.size();i++){
		if(exMonster == monsters[i]){
			return true;
		}
	}

	//若遍历后都没有
	return false;
}

void Immortal::removeMonster(const Monster& monster)//要找到存有的那一种妖兽!
{
	vector<Monster>::iterator it = monsters.begin();
	for (; it != monsters.end();) {
		if (monster == *it) {//没用到==运算符重载
			it = monsters.erase(it);
		}
		else {
			it++;
		}
	}
}

void Immortal::dead()
{
	stones.clear();
	monsters.clear();
	alive = false;
}

ostream& operator<<(ostream& os, const Immortal& immortal)
{
	SpriteStone stone;
	for (unsigned int i = 0; i < immortal.stones.size(); i++) {
		stone = stone + immortal.stones[i];
	}

	os << "[修仙者]" << immortal.name << endl
		<< (immortal.alive == true ? "[在修] " : "[已死] ")//(1?2:3)记得带括号!
		<< immortal.level
		<< " 门派:" << immortal.faction
		<< " 灵石:折合" << stone
		<< " 妖兽:";
	if (!immortal.monsters.size()) {
		os << "无";
	}
	else {
		for (unsigned int i = 0; i < immortal.monsters.size(); i++) {
			os << immortal.monsters[i] << " ";
		}
	}

	return os;
}

ostream& operator<<(ostream& os, const IMMORTAL_LEVEL& level)
{
	os << "级别:" << int(level) << " ";
	switch (level)
	{
	case IMMORTAL_LEVEL::LIAN_QI:
		os << "练气期";
		break;
	case IMMORTAL_LEVEL::DA_CHENG:
		os << "大成期";
		break;
	case IMMORTAL_LEVEL::DU_JIE:
		os << "渡劫期";
		break;
	case IMMORTAL_LEVEL::HE_TI:
		os << "合体期";
		break;
	case IMMORTAL_LEVEL::HUA_SHEN:
		os << "化神期";
		break;
	case IMMORTAL_LEVEL::JIE_DAN:
		os << "结丹期";
		break;
	case IMMORTAL_LEVEL::LIAN_XV:
		os << "炼虚期";
		break;
	case IMMORTAL_LEVEL::YUAN_YING:
		os << "元婴期";
		break;
	case IMMORTAL_LEVEL::ZHU_JI:
		os << "筑基期";
		break;
	default:
		os << "时期未知!";
		break;
	}
	return os;
}
