#pragma once
#include <iostream>
using namespace std;

class Pork {
public:
	Pork();
	Pork(int weight);
	Pork operator+(const Pork& pork);

	void description() {
		cout << "ÖíÈâÖØÁ¿:" << weight << endl;
	}
	int getWeight() {
		return weight;
	}
private:
	int weight;
};