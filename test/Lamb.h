#pragma once
#include "Pork.h"

class Lamb {
public:
	Lamb();
	Lamb(int weight);
	Pork operator+(const Lamb& lamb);

	int getWeight() {
		return weight;
	}
private:
	int weight;
};