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
	int tmp = lamb.getWeight() * 3 + weight * 2;//�õ��������private������Ҫ�ٶ���public������
	return Pork(tmp);
}

Pork Beef::operator+(Beef& beef) const
{
	int tmp = (this->weight + beef.weight) * 2;
	return Pork(tmp);
}
