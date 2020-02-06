#include "Boy.h"
using namespace std;
int Boy::total_id = 0;//�ǵ�����������

Boy::Boy(const char* name, int age)
{
	if (!name) {//������ָ����һ��Ҫ����ָ��Ϊ�����(����Ĭ�Ϻ��û�������ַ����)
		name = "δ����";//Ϊ�˸����ַ���,Ҫ��name����Ҳ��Ϊconst
	}

	//�������볤�����붯̬�ڴ�
	this->name = new char[strlen(name)+1];//�ǵð����ַ���ĩβ��'\0'
	strcpy_s(this->name, strlen(name) + 1, name);

	this->age = age;
	id = ++total_id;
}

Boy::~Boy() {
	delete[] name;//������ʼ��ʱ������ڴ�
}

Boy& Boy::operator=(const Boy& boy) {
	//���������
	//һ�㲻��Ҫ�ͷŸ�ֵboy���ڴ�,��Ϊ������ԭ�ڴ���Ϣ,������ֵ
	//delete[] boy.name;
	//���ͷŽ�����ֵboy��ԭ��name�ڴ�
	delete[]name;

	if (!boy.name) {
		cout << "��ֵ��������ָ��Ϊ��!" << endl;
		exit(1);
	}

	//Ϊ�µı���ֵ�����ַ����µ��ڴ�ռ�
	name = new char[strlen(boy.name) + 1];
	strcpy_s(name, strlen(boy.name) + 1, boy.name);

	age = boy.age;

	//id = boy.id;//id�Ƿ���,���������
	//��ֵ���캯���Ѿ���ʼ����,�Ѿ�ʹ������+1,�˴������ټ�
	//������ԭ��,������-1
	//total_id--;

	//Ϊ������ʽ����b1=b2=b3,��Ҫ������ֵ�Լ�(������void��b1=void��)(=Ϊ��������ֵ)
	return *this;
}

void Boy::description()
{
	cout << "����:" << name << " ����:" << age 
		<< " id:" << id << " ������:" << total_id << endl;
}
