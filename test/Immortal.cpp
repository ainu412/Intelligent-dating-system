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
		cerr << "����������!����ʧ��!" << endl;
		return false; 
	}
	else {
		SpriteStone stone;
		for (unsigned int i = 0; i < monsters.size(); i++) {
			stone = stone + monsters[i].getValue();//stone�����������
		}

		stones.push_back(stone);
		//�ǵ�����˫�����!�����ʯ��ͬʱ,�����ʲ����
		//monsters.erase(monsters.begin(), monsters.end());Ҳ��
		monsters.clear();

		return true;
	}
}

bool Immortal::trade(const Monster& monster)
{
	if (!hasMonster(monster)) {
		cerr << "û��ָ������!" << endl;
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
		cerr << "���׷�����!" << endl;
		return false;
	}
	else if (!hasMonster(monster)) {
		cerr << "��û��" << monster << endl;
		return false;
	}

	//�����ۺϺ���ʯ��
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
		cerr << "��ʯ����!" << endl;
		return false;
	}
	cerr << "��" << other.name << "����" << monster << "ʧ��!" << endl;
	return false;
}

bool Immortal::trade(Immortal& other, Monster& monster)
{
	if (!alive || !other.alive) {
		cerr << "���׷�����!" << endl;
		return false;
	}
	else if (!other.hasMonster(monster)) {
		cerr << "����" << other.name << "û��" << monster << endl;
		return false;
	}

	//�����ۺϺ���ʯ��
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
		cerr << "��ʯ����!" << endl;
		return false;
	}
	cerr << "��" << other.name << "����" << monster << "ʧ��!" << endl;
	return false;
}

bool Immortal::trade(Monster& monster, Immortal& other, Monster& aMonster)
{
	if (!alive || !other.alive) {
		cerr << "���׷�����!" << endl;
		return false;
	}
	else if (!hasMonster(monster)) {
		cerr << "��û��" << monster << "�ɹ�����!" << endl;
		return false;
	}
	else if (!other.hasMonster(aMonster)) {
		cerr << other.name << "û��" << aMonster << "�ɹ�����!" << endl;
		return false;
	}
	else if (monster == aMonster) {
		cerr << "���ܽ�����ȫ��ͬ������!" << endl;
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
		cerr << "���ܽ����ȼ���ͬ������!" << endl;
		return false;
	}
	cerr << "����ʧ��!" << endl;
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
	//�Ӳ������޵�ս����
	for (unsigned int i = 0; i < monsters.size(); i++) {
		power += monsters[i].getPower() / POWER_TO_MONSTER_LEVEL_RATIO * POWER_TO_OWNED_MONSTER_LEVEL_RATIO;
	}

	//���Լ���ս����
	power += (int(level) + 1) * POWER_TO_IMMORTAL_LEVEL_RATIO;//ʱ��ע���Լ��ļ���int(level)����С1,�Ժ�Ϊ��ֹ����,����д=1

	return power;
}

bool Immortal::hasMonster(const Monster& exMonster)const//Ѱ����û��ĳһ�������,�����õ�ַ,��ΪֻҪ����һ��Ϳ���
{
	//vector<Monster>::iterator it = monsters.begin();
	//for (auto it = monsters.begin(); it != monsters.end;) {
		//if (*it == &exMonster) {//���ﲻ����,��Ϊ�е�ʱ��it��Ϊvector<Human>* friends�����ָ��,ָ��������ǵ�ַ
								//�ʴ��Ӧ��Ϊָ��,ָ��ӵ�е�����(�ۺϹ�ϵ)
	for (unsigned int i=0;i<monsters.size();i++){
		if(exMonster == monsters[i]){
			return true;
		}
	}

	//��������û��
	return false;
}

void Immortal::removeMonster(const Monster& monster)//Ҫ�ҵ����е���һ������!
{
	vector<Monster>::iterator it = monsters.begin();
	for (; it != monsters.end();) {
		if (monster == *it) {//û�õ�==���������
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

	os << "[������]" << immortal.name << endl
		<< (immortal.alive == true ? "[����] " : "[����] ")//(1?2:3)�ǵô�����!
		<< immortal.level
		<< " ����:" << immortal.faction
		<< " ��ʯ:�ۺ�" << stone
		<< " ����:";
	if (!immortal.monsters.size()) {
		os << "��";
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
	os << "����:" << int(level) << " ";
	switch (level)
	{
	case IMMORTAL_LEVEL::LIAN_QI:
		os << "������";
		break;
	case IMMORTAL_LEVEL::DA_CHENG:
		os << "�����";
		break;
	case IMMORTAL_LEVEL::DU_JIE:
		os << "�ɽ���";
		break;
	case IMMORTAL_LEVEL::HE_TI:
		os << "������";
		break;
	case IMMORTAL_LEVEL::HUA_SHEN:
		os << "������";
		break;
	case IMMORTAL_LEVEL::JIE_DAN:
		os << "�ᵤ��";
		break;
	case IMMORTAL_LEVEL::LIAN_XV:
		os << "������";
		break;
	case IMMORTAL_LEVEL::YUAN_YING:
		os << "ԪӤ��";
		break;
	case IMMORTAL_LEVEL::ZHU_JI:
		os << "������";
		break;
	default:
		os << "ʱ��δ֪!";
		break;
	}
	return os;
}
