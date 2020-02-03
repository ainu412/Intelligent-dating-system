#include "Engine.h"

Engine::Engine()
{
}

Engine::Engine(string brand, string version)
{
	this->brand = brand;
	this->version = version;
}

string Engine::getBrand()
{
	return brand;
}

string Engine::getVersion()
{
	return version;
}
