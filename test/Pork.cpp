#include "Pork.h"

Pork::Pork(int weight=0)
{
	this->weight = weight;
}

Pork Pork::operator+(const Pork& pork)
{
	int tmp = pork.weight + this->weight;
	return Pork(tmp);
}