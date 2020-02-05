#include "Pork.h"

Pork::Pork()
{
	weight = 0;
}

Pork::Pork(int weight)
{
	this->weight = weight;
}

Pork Pork::operator+(const Pork& pork)
{
	int tmp = pork.weight + this->weight;
	return Pork(tmp);
}