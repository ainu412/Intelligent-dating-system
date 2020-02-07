#pragma once
#include "Boy.h"
class Man
{
public:
	Man();

	Man(Boy& boy);

	friend ostream& operator<<(ostream& os, Man& man);
private:
	int age;
	char* name;
};

