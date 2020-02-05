#include "Lamb.h"

Lamb::Lamb()
{
	weight = 0;
}

Lamb::Lamb(int weight)
{
	this->weight = weight;
}

Pork Lamb::operator+(const Lamb& lamb)
{
	int tmp = (this->weight + lamb.weight) * 3;
	return Pork(tmp);
}