#pragma once
using namespace std;
#include <string>
class Computer;

class Service {
public:
	Service() {

	}
	void up(Computer* computer, string version);//友元函数不分public和private,因为无论写哪外部都可以调用

};