#include <iostream>
#include <sstream>
using namespace std;
class Service {
public:
	Service() {

	}
	void up(Computer* computer, string version);//友元函数不分public和private,因为无论写哪外部都可以调用

};
class Computer {
public:
	Computer(string cpu = "") {
		this->cpu = cpu;
	}


	string description() {
		stringstream ret;
		ret << "cpu:" << cpu << endl;
		return ret.str();
	}

private:
	string cpu;

	friend void upgrade(Computer* computer) {//友元函数不分public和private,因为无论写哪外部都可以调用
		computer->cpu = "i9";//service要在computer之前定义,不然不知道定义的是哪个函数
	}
	//要声明可以对自己进行改变的其他类的成员函数
	friend void Service::up(Computer* computer, string version);
};



void Service::up(Computer* computer, string version)
{
	computer->cpu = version;
}

int main() {
	Computer computer("i7");
	cout << computer.description();
	upgrade(&computer);
	cout << computer.description();

	Service service;
	service.up(&computer, "i8");
	cout << computer.description();
}
