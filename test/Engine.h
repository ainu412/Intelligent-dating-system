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
	string brand;//只有在自己类内函数定义时才能调取
	string version;
};

