#include "Beef.h"


Beef::Beef()
{
	weight = 0;
}

Beef::Beef(int weight)
{
	this->weight = weight;
}

Pork Beef::operator+( Lamb& lamb)const
{
	int tmp = lamb.getWeight() * 3 + weight * 2;//用到其他类的private数据需要再定义public函数化
	return Pork(tmp);
}

Pork Beef::operator+(Beef& beef) const
{
	int tmp = (this->weight + beef.weight) * 2;
	return Pork(tmp);
}
