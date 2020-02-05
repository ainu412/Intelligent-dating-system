#pragma once
#include "Lamb.h"
#include "Pork.h"

class Beef {
public:
	Beef();
	Beef(int weight);
	Pork operator+(Lamb& lamb)const;
	Pork operator+(Beef& beef)const;
private:
	int weight;
};