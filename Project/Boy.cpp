#include "Boy.h"
#include <sstream>
#include <iomanip>
#include "Girl.h"
#define SALARY_COEFFICIENT 0.006
Boy::Boy() {
	salary = 0;
}
Boy::Boy(string name, int age, int salary) :Single(name, age){
	this->salary = salary;
}

bool Boy::satisfied(const Girl& girl)const
{	
	int satisfiedFaceScore = salary * SALARY_COEFFICIENT;
	if (salary * SALARY_COEFFICIENT > 100) satisfiedFaceScore = 100;
	if (girl.getFaceScore() >= satisfiedFaceScore) return true;
	return false;
}

string Boy::description()const
{
	stringstream ret;
	ret << "�� ����:" << setw(9) << left << name 
		<< " ����:" << setw(4) << age 
		<< "��н:" << salary;//����ret;cout<<xxx,Ϊ��xxx�������̨���
	return ret.str();
}

void Boy::inputBoys(vector<Boy>& boys)
{
	{int n = 1;
		while (1) {
			string name;
			int age;
			int salary;

			cout << "�������" << n << "λС��������(����0����):";
			cin >> name;//��Ҫ���ⶨ���β�,���һ��ͨ��vector��.push_back����,push_back��Ϊ�Ƶ������,ÿ�μ���Ķ�λ�����,���Ŷ�һ��
			if (name == "0") break;
			cout << "����:";
			cin >> age;
			cout << "��н:";
			cin >> salary;

			boys.push_back(Boy(name, age, salary));//�ɲ�ͨ�����͵��ô��ι��캯��

			n++;
		}
	}
}
