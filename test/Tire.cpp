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
	ret << "ÂÖÌ¥Æ·ÅÆ:" << brand << ",ÂÖÌ¥³ß´ç:" << size << ",ÂÖÌ¥ÆøÑ¹:" << pressure << endl;
	return ret.str();
}
