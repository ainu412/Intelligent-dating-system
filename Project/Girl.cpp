#include "Girl.h"
#include <sstream>
#define FACESCORE_COEFFICIENT 300
#include "Boy.h"
Girl::Girl(){
	name = "";
	age = 0;
	faceScore = 0;
}
Girl::Girl(string name, int age, int faceScore){
	this->name = name;
	this->age = age;
	this->faceScore = faceScore;
}
string Girl::getName()const{
	return name;
}

int Girl::getAge()const{
	return age;
}

int Girl::getFaceScore()const{
	return faceScore;
}

bool Girl::satisfied(const Boy& boy)const
{
	if ( boy.getSalary() > faceScore*FACESCORE_COEFFICIENT) return true;//��Ϊ��boy�ķ���,����Ҫ����boy��ͷ�ļ�
	return false;
}

string Girl::description()const
{
	stringstream ret;
	ret << "Ů:����(" << name << "),����(" << age << "),��ֵ(" << faceScore << ").";//����ret;cout<<xxx,Ϊ��xxx�������̨���
	return ret.str();
}