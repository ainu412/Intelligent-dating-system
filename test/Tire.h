#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Tire
{public:
	Tire();
	Tire(string brand, int size, int pressure);
	
	string description();

private:
	string brand;
	int size;
	int pressure;//µ¥Î»:Éý
};