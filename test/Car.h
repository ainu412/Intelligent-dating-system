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

	void addTire(Tire& tire);//�ۺϵ�tire�Ѷ��������,�ʲ����ڹ��쳵��ͬʱ��ʼ��tire,ֻ���Ȳ���tire�ټ���car

private:
	string brand;
	string version;
	int price;//��λ:��
	int mileage;
	Engine engine;
	vector<Tire*> tires;//ֻ��ָ��
};

