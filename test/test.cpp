#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

enum class Gender {
	// 私有构造保证值域的封闭性
	MALE,
	FEMALE
};//Genderypedef指被类型定义过的,类型名

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
	Character* spouse = NULL;//不可以含自己的类但可以含指针或别名,C11可以类内初始化
	vector<Character*> friends;//vector型为不同步的复印.故应写为vector型指针以同步朋友的最新信息,也为节省空间只记地址,不整个拷贝.每个朋友都只记指针
	//vector<T>* a;这里a是一个指针，指向的是vector<T>类型，vector<T>类型是元素类型为T的顺序容器.vector<T*> a, 则vector元素类型为T* ，即每个位置存储的是指针.
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
	ret << "昵称:" << name  << ",性别:" << (gender == Gender::MALE ? "男" : "女") << ",年龄:" << age;//记得加括号表明优先级
	return ret.str();//转化回C++中的字符串
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

void Character::marry(Character& spouse)//结婚是双向的!
{
	if (gender == spouse.gender) return;//同性不能结婚
	this->spouse = &spouse;//厉害!!
	this->spouse->spouse = this;
}

void Character::divorce()//离婚是双向的!
{
	if (spouse != NULL) {//防止空指针-未婚还离婚
		spouse->spouse = NULL;//在自己的配偶清空前调取对方信息;spouse = NULL;spouse->spouse = NULL;×-此时spouse地址为空,无法找到NULL->spouse
		spouse = NULL;
	}
}

void Character::addFriend(Character& newFriend)//交友是单向的!
{
	friends.push_back(&newFriend);
}

void Character::delFriend(Character& exFriend)//厉害!!//断交也是单向的!
{//auto i=100;=int i=100
	//auto j=3.14;=double j=3.14.
	//auto自动识别类型
	//friends.begin()返回的是一特殊的指针,指向第一个成员的迭代器
	//friends.end()返回的是一特殊的指针,指向最后一个成员的下一位置迭代器
	for (auto it = friends.begin(); it != friends.end();) {
		if (*it == &exFriend) {
			it = friends.erase(it);//返回删除成员的下一个有效成员的"迭代器";删除的无效成员占位置不为1,故删除与不删除两种情况不能都对it加一
		}
		else {
			it++;//有效成员占位置为1
		}
	}
	//已经被销毁
	/*	for (auto i = friends.begin(); i != friends.end();) {
			if (*i == &exFriend) {
				i = friends.erase(i);//返回删除成员的下一个有效成员的"迭代器";删除的无效成员占位置不为1
			}
		}
	*/
}

//测试代码
int main() {
	Character ols("欧龙燊", Gender::MALE, 21);
	Character gzy("郭子怡", Gender::FEMALE, 20);
	Character wsy("万舒悦", Gender::FEMALE, 20);
	Character zhx("周浩鑫", Gender::MALE, 23);

	cout << "结婚:" << endl;
	ols.marry(gzy);
	cout << "欧龙燊的配偶简介为:" << ols.getSpouse()->getBio() << endl;
	cout << "郭子怡的配偶姓名为:" << gzy.getSpouse()->getName() << endl;
	cout << "离婚:" << endl;
	ols.divorce();
	if (ols.getSpouse() != NULL) {
		cout << "离婚失败!" << endl;
	}
	else {
		cout << "离婚成功!" << endl;
	}

	cout << "交友:" << endl;
	gzy.addFriend(wsy);
	gzy.addFriend(zhx);
	auto fs = gzy.getFriends();//再定义一个friends的vector方便后续打印操作
	cout << "郭子怡的朋友有:";
	for (unsigned int i = 0; i < fs.size(); i++) {
		cout << fs[i]->getName()<<" ";
	} cout << endl;
	cout << "绝交:" << endl;
	gzy.delFriend(zhx);
	auto fs1 = gzy.getFriends();
	cout << "郭子怡的朋友有:";
	for (unsigned int i = 0; i < fs1.size(); i++) {
		cout << fs1[i]->getName() << " ";
	} cout << endl;
	return 0;
}