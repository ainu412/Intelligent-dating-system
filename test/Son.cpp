#include "Son.h"

/*Son::Son():Father()
{
	game = "未知游戏";
	cout << __FUNCTION__ <<"不带参"<< endl;
}*/

Son::Son(string name, int age, string food, string game):Father(name,age),Mother(food)//因为完全继承,连名字和年龄也要通过这个初始化设定继承
{
	this->game = game;
	cout << __FUNCTION__ << endl;
}

Son::~Son()
{
	cout << __FUNCTION__ << endl;
}

string Son::getGame()
{
	return game;
}

/*string Son::description() {
	stringstream ret;
	ret << "姓名:" << name << ",年龄:" << getAge() //private(数据成员):仅自己类内
		<< ",游戏:" << game << endl;//public(成员函数):谁都可以(子类可直接访问父类的,类外函数可通过对象/类(静态))
	return ret.str();//protected(数据成员):子类可直接访问,类外不能访问
}*/