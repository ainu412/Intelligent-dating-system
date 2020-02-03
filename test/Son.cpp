#include "Son.h"

/*Son::Son():Father()
{
	game = "未知游戏";
	cout << __FUNCTION__ <<"不带参"<< endl;
}*/

Son::Son(string name, int age, string food, string game):Father(name, age), Mother(food, name, age)//因为完全继承,连名字和年龄也要通过这个初始化设定继承
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

string Son::description()
{
	return 	Mother::description();
}

void Son::dance()
{
	Father::dance();
	Mother::dance();
}

