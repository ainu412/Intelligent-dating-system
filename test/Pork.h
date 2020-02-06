#pragma once
#include <iostream>
using namespace std;
class Pork {
public:

	Pork(int weight);
	Pork operator+(const Pork& pork);

	void description() {
		cout << "ÖíÈâÖØÁ¿:" << weight << endl;
	}

private:
	int weight;

	friend Pork operator+(int n, const Pork& pork);
};