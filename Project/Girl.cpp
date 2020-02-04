#include "Girl.h"
#include <sstream>
#define FACESCORE_COEFFICIENT 100
#include "Boy.h"
Girl::Girl(){
	faceScore = 0;
}
Girl::Girl(string name, int age, int faceScore) :Single (name, age) {

	this->faceScore = faceScore;
}

int Girl::getFaceScore()const{
	return faceScore;
}

bool Girl::satisfied(const Boy& boy)const
{
	if ( boy.getSalary() >= faceScore*FACESCORE_COEFFICIENT) return true;//��Ϊ��boy�ķ���,����Ҫ����boy��ͷ�ļ�
	return false;
}

string Girl::description()const
{
	stringstream ret;
	ret << "Ů:����(" << getName() << "),����(" << getAge() << "),��ֵ(" << faceScore << ").";//����ret;cout<<xxx,Ϊ��xxx�������̨���
	return ret.str();
}

void Girl::inputGirls(vector<Girl>& girls)
{
	int n = 1;
	while (1) {
		string name;
		int age;
		int faceScore;

		cout << "�������" << n << "λС��������(����0����):";
		cin >> name;//��Ҫ���ⶨ���β�,���һ��ͨ��vector��.push_back����
		if (name == "0") break;
		cout << "����:";
		cin >> age;
		cout << "��ֵ:";
		cin >> faceScore;

		girls.push_back(Girl(name, age, faceScore));//�ɲ�ͨ�����͵��ô��ι��캯��

		n++;
	}
}