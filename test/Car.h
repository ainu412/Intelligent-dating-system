#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "Engine.h"
class Tire;
using namespace std;
class Car
{public:
	Car();
	Car(string brand, string version, int price, int mileage, string engineBrand, string engineVersion);
	Car(const Car& src);

	string getBrand();
	string getVersion();
	int getPrice();
	int getMileage();
	string description();
	Engine& getEngine();
	vector<Tire*> getTires();

	void addTire(Tire& tire);//聚合的tire已定义产生了,故不能在构造车的同时初始化tire,只能先产生tire再加入car

private:
	string brand;
	string version;
	int price;//单位:万
	int mileage;
	Engine engine;
	vector<Tire*> tires;//只含指针
};

