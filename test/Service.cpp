#include "Service.h"
#include "Computer.h"//��������֪�����������ѿ����޸���
void Service::up(Computer* computer, string version)
{
	computer->cpu = version;
}