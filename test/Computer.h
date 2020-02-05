#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Service;

class Computer {
public:
	Computer(string cpu = "") {
		this->cpu = cpu;
	}


	string description();

private:
	string cpu;

	friend void upgrade(Computer* computer);//友元函数不分public和private,因为无论写哪外部都可以调用
	
	//要声明可以对自己进行改变的其他类的成员函数
	//void Service::up(Computer* computer, string version);//对这个函数的声明必须写在前面,才能知道是要把这个函数当朋友

	friend Service;
};
//总结:他类:service具体实现需要包括header以得知内部成员,declare class就行没修改内部成员;computer declare需要包括header看清friend的函数;main中只写computer就行因为都含了
//外部函数:		main中包括friend的header(这点没啥特别,要用它肯定要包含它)