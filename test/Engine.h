#pragma once
#include <iostream>
using namespace std;
class Engine
{public:
	Engine();
	Engine(string engineBrand, string engineVersion);
	string getBrand();
	string getVersion();

private:
	string brand;//ֻ�����Լ����ں�������ʱ���ܵ�ȡ
	string version;
};

