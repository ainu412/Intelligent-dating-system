#include <iostream>
#include <sstream>
using namespace std;
class Service {
public:
	Service() {

	}
	void up(Computer* computer, string version);//��Ԫ��������public��private,��Ϊ����д���ⲿ�����Ե���

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

	friend void upgrade(Computer* computer) {//��Ԫ��������public��private,��Ϊ����д���ⲿ�����Ե���
		computer->cpu = "i9";//serviceҪ��computer֮ǰ����,��Ȼ��֪����������ĸ�����
	}
	//Ҫ�������Զ��Լ����иı��������ĳ�Ա����
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
