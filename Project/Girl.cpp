#include "Girl.h"
#include <sstream>
#include <iomanip>
#define FACESCORE_COEFFICIENT 100
#include "Boy.h"
Girl::Girl(string name, int age, int faceScore) :Single (name, age) {

	this->faceScore = faceScore;
}

bool Girl::satisfied(const Boy& boy)const
{
	if ( boy.getSalary() >= faceScore*FACESCORE_COEFFICIENT) return true;//��Ϊ��boy�ķ���,����Ҫ����boy��ͷ�ļ�
	return false;
}

bool Girl::operator>(Girl& girl)
{
	return faceScore > girl.faceScore;
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
ostream& operator<<(ostream& os, const Girl& girl) {
	os  << "Ů ����:" << setw(9) << left << girl.name//left=setiosflags(ios::left)
		<< " ����:" << setw(4) << girl.age
		<< "��ֵ:" << girl.faceScore << endl;
	return os;
}