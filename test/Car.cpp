#include "Car.h"

Car::Car()
{
	brand = "";
	version = "";
	price = 0;
	mileage = 0;
}

Car::Car(string brand, string version, int price, int mileage, string engineBrand, string engineVersion):engine(engineBrand,engineVersion)
{
	this->brand = brand;
	this->version = version;
	this->price = price;
	this->mileage = mileage;
}

Car::Car(const Car& src)
{
	this->brand = src.brand;
	this->version = src.version;
	this->price = src.price;
	this->mileage = src.mileage;
}

string Car::getBrand()
{
	return brand;
}

string Car::getVersion()
{
	return version;
}

int Car::getPrice()
{
	return price;
}

int Car::getMileage()
{
	return mileage;
}

string Car::description()
{
	stringstream ret;
	ret << "汽车品牌:" << brand << ",汽车型号:" << version << ",汽车价格:" << price << ",行车里程:" << mileage << endl
		<< "发动机品牌:" << engine.getBrand() << ",发动机型号:" << engine.getVersion() << endl;
	return ret.str();
}

Engine& Car::getEngine()
{
	return engine;
}

vector<Tire*> Car::getTires()
{
	return tires;
}

void Car::addTire(Tire& tire)
{
	tires.push_back(&tire);
}