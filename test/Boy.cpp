#include "Boy.h"
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

const Boy& Boy::operator>(const Boy& boy)const//
{
	if (age > boy.age) {
		return boy;//����ֵ�������������һ��
	}
	else {
		return *this;//�����,Ҳ��ӡ�Լ�
	}
}

void Boy::operator==(const Boy& boy)const
{
	if (age == boy.age) {
		cout << "����������ͬ!" << endl;
	}
}
int Boy::operator[](KEY key)
{
	switch (key) {
	case(AGE_KEY):
		return age;
		break;
	case(ID_KEY):
		return id;
		break;
	default:
		return -1;
		break;
	}
}
char* Boy::operator[](string name_key)
{
	if (NAME_KEY == name_key) {
		return name;
	}
}

void Boy::description()
{
	cout << "����:" << name << " ����:" << age 
		<< " id:" << id << " ������:" << total_id << endl;
}
