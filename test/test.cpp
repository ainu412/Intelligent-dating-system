#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

enum class Gender {
	// ˽�й��챣ֵ֤��ķ����
	MALE,
	FEMALE
};//Genderypedefָ�����Ͷ������,������

class Character {
public:
	Character();
	Character(string name, Gender gender, int age);
	Character(const Character& character);

	string getBio()const;
	string getName()const;
	int getAge()const;
	Gender getGender()const;
	Character* getSpouse()const;
	vector<Character*> getFriends()const;

	void marry(Character& spouse);
	void divorce();
	void addFriend(Character& newFriend);
	void delFriend(Character& exFriend);

private:
	string name;
	int age;
	Gender gender;
	Character* spouse = NULL;//�����Ժ��Լ����൫���Ժ�ָ������,C11�������ڳ�ʼ��
	vector<Character*> friends;//vector��Ϊ��ͬ���ĸ�ӡ.��ӦдΪvector��ָ����ͬ�����ѵ�������Ϣ,ҲΪ��ʡ�ռ�ֻ�ǵ�ַ,����������.ÿ�����Ѷ�ֻ��ָ��
	//vector<T>* a;����a��һ��ָ�룬ָ�����vector<T>���ͣ�vector<T>������Ԫ������ΪT��˳������.vector<T*> a, ��vectorԪ������ΪT* ����ÿ��λ�ô洢����ָ��.
};

Character::Character()
{
	name = "";
	age = 0;
	gender = Gender::MALE;
	spouse = NULL;
	//friends = NULL;
}
Character::Character(string name, Gender gender, int age)
{
	this->name = name;
	this->gender = gender;
	this->age = age;
}
Character::Character(const Character& character)
{
	this->name = character.name;
	this->age = character.age;
	this->gender = character.gender;
	this->spouse = character.spouse;
	this->friends = character.friends;
}

string Character::getBio() const
{
	stringstream ret;
	ret << "�ǳ�:" << name  << ",�Ա�:" << (gender == Gender::MALE ? "��" : "Ů") << ",����:" << age;//�ǵü����ű������ȼ�
	return ret.str();//ת����C++�е��ַ���
}

string Character::getName() const
{
	return name;
}

int Character::getAge() const
{
	return age;
}

Gender Character::getGender() const
{
	return gender;
}

Character* Character::getSpouse() const
{
	return spouse;
}

vector<Character*> Character::getFriends() const
{
	return friends;
}

void Character::marry(Character& spouse)//�����˫���!
{
	if (gender == spouse.gender) return;//ͬ�Բ��ܽ��
	this->spouse = &spouse;//����!!
	this->spouse->spouse = this;
}

void Character::divorce()//�����˫���!
{
	if (spouse != NULL) {//��ֹ��ָ��-δ�黹���
		spouse->spouse = NULL;//���Լ�����ż���ǰ��ȡ�Է���Ϣ;spouse = NULL;spouse->spouse = NULL;��-��ʱspouse��ַΪ��,�޷��ҵ�NULL->spouse
		spouse = NULL;
	}
}

void Character::addFriend(Character& newFriend)//�����ǵ����!
{
	friends.push_back(&newFriend);
}

void Character::delFriend(Character& exFriend)//����!!//�Ͻ�Ҳ�ǵ����!
{//auto i=100;=int i=100
	//auto j=3.14;=double j=3.14.
	//auto�Զ�ʶ������
	//friends.begin()���ص���һ�����ָ��,ָ���һ����Ա�ĵ�����
	//friends.end()���ص���һ�����ָ��,ָ�����һ����Ա����һλ�õ�����
	for (auto it = friends.begin(); it != friends.end();) {
		if (*it == &exFriend) {
			it = friends.erase(it);//����ɾ����Ա����һ����Ч��Ա��"������";ɾ������Ч��Առλ�ò�Ϊ1,��ɾ���벻ɾ������������ܶ���it��һ
		}
		else {
			it++;//��Ч��Առλ��Ϊ1
		}
	}
	//�Ѿ�������
	/*	for (auto i = friends.begin(); i != friends.end();) {
			if (*i == &exFriend) {
				i = friends.erase(i);//����ɾ����Ա����һ����Ч��Ա��"������";ɾ������Ч��Առλ�ò�Ϊ1
			}
		}
	*/
}

//���Դ���
int main() {
	Character ols("ŷ����", Gender::MALE, 21);
	Character gzy("������", Gender::FEMALE, 20);
	Character wsy("������", Gender::FEMALE, 20);
	Character zhx("�ܺ���", Gender::MALE, 23);

	cout << "���:" << endl;
	ols.marry(gzy);
	cout << "ŷ��������ż���Ϊ:" << ols.getSpouse()->getBio() << endl;
	cout << "����������ż����Ϊ:" << gzy.getSpouse()->getName() << endl;
	cout << "���:" << endl;
	ols.divorce();
	if (ols.getSpouse() != NULL) {
		cout << "���ʧ��!" << endl;
	}
	else {
		cout << "���ɹ�!" << endl;
	}

	cout << "����:" << endl;
	gzy.addFriend(wsy);
	gzy.addFriend(zhx);
	auto fs = gzy.getFriends();//�ٶ���һ��friends��vector���������ӡ����
	cout << "��������������:";
	for (unsigned int i = 0; i < fs.size(); i++) {
		cout << fs[i]->getName()<<" ";
	} cout << endl;
	cout << "����:" << endl;
	gzy.delFriend(zhx);
	auto fs1 = gzy.getFriends();
	cout << "��������������:";
	for (unsigned int i = 0; i < fs1.size(); i++) {
		cout << fs1[i]->getName() << " ";
	} cout << endl;
	return 0;
}