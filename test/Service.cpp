#include "Service.h"
#include "Computer.h"//包含才能知道是它的朋友可以修改它
void Service::up(Computer* computer, string version)
{
	computer->cpu = version;
}