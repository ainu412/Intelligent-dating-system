#include "Son.h"

/*Son::Son():Father()
{
	game = "δ֪��Ϸ";
	cout << __FUNCTION__ <<"������"<< endl;
}*/

Son::Son(string name, int age, string game):Father(name,age)//��Ϊ��ȫ�̳�,�����ֺ�����ҲҪͨ�������ʼ���趨�̳�
{
	this->game = game;
	cout << __FUNCTION__ << endl;
}

Son::~Son()
{
	cout << __FUNCTION__ << endl;
}

string Son::getGame()
{
	return game;
}

string Son::description() {
	stringstream ret;
	ret << "����:" << name << ",����:" << getAge() //private(���ݳ�Ա):���Լ�����
		<< ",��Ϸ:" << game << endl;//public(��Ա����):˭������(�����ֱ�ӷ��ʸ����,���⺯����ͨ������/��(��̬))
	return ret.str();//protected(���ݳ�Ա):�����ֱ�ӷ���,���ⲻ�ܷ���
}