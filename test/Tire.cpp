#include "Tire.h"

Tire::Tire()
{
}

Tire::Tire(string brand, int size, int pressure)
{
	this->brand = brand;
	this->size = size;
	this->pressure = pressure;
}

string Tire::description()
{
	stringstream ret;
	ret << "��̥Ʒ��:" << brand << ",��̥�ߴ�:" << size << ",��̥��ѹ:" << pressure << endl;
	return ret.str();
}
