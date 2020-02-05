#include "Computer.h"

string Computer::description()
{
	stringstream ret;
	ret << "cpu:" << cpu << endl;
	return ret.str();
}

void upgrade(Computer* computer)
{
	computer->cpu = "i9";
}