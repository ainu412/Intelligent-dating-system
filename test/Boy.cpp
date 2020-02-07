#include "Boy.h"
int Boy::total_id = 0;//�ǵ�����������

Boy::Boy(const char* name,const int age)
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

Boy::Boy(int age)
{

	const char tmp[10] = "δ����";//Ϊ�˸����ַ���,Ҫ��name����Ҳ��Ϊconst
	this->name = new char[strlen(tmp) + 1];//�ǵð����ַ���ĩβ��'\0'
	strcpy_s(this->name, strlen(tmp) + 1, tmp);

	this->age = age;
	id = ++total_id;
}

Boy::Boy(const char* name)
{
	if (!name) {//������ָ����һ��Ҫ����ָ��Ϊ�����(����Ĭ�Ϻ��û�������ַ����)
		name = "δ����";//Ϊ�˸����ַ���,Ҫ��name����Ҳ��Ϊconst
	}

	//�������볤�����붯̬�ڴ�
	this->name = new char[strlen(name) + 1];//�ǵð����ַ���ĩβ��'\0'
	strcpy_s(this->name, strlen(name) + 1, name);

	this->age = 0;
	id = ++total_id;
}

Boy::Boy(const Boy& boy)
{
	//��ʼ��ʱ���ÿ������캯��
	//����û����,����ɾ���ڴ�
	name = new char[strlen(boy.name) + 1];
	strcpy_s(name, strlen(boy.name) + 1, boy.name);

	age = boy.age;
	id = ++total_id;
}

Boy::~Boy() {
	delete[] name;//������ʼ��ʱ������ڴ�
}

Boy& Boy::operator=(const Boy& boy) {//������Ϊָ��,����!!
	//���������
	//һ�㲻��Ҫ�ͷŸ�ֵboy���ڴ�,��Ϊ������ԭ�ڴ���Ϣ,������ֵ
	//delete[] boy.name;
	//���ͷŽ�����ֵboy��ԭ��name�ڴ�
	if (name) {
		delete[]name;
	}

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

//Boy& Boy::operator=(const Boy* boy) {//ǳ��ֵ:=ǳ����
//	name = boy->name;//��ַ����ֱ�Ӹ�ֵ,��ӵ��
//	age = boy->age;
//	id = boy->id;
//}
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

int Boy::operator[](KEY key)const
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
char* Boy::operator[](string name_key)const
{
	if (NAME_KEY == name_key) {
		return name;
	}
}

ostream& Boy::operator>>(ostream& os)const//�ǵ��ñ���,ֻ����const
{
	os  << "����:" << name << " ����:" << age
		<< " id:" << id << " ������:" << total_id << endl;
	return os;
}

istream& Boy::operator<<(istream& is) 
{
	//��Ϊname��char*,����ֱ���޸�,ͨ��string��ת
	string tmp;
	is >> tmp >> age;

	//ԭ�����ö�̬�ڴ�洢,�������
	if (name) {//����Ϊ��ָ��
		delete[] name;
	}

	//��������tmp���ַ����ȷ��䶯̬�ڴ�
	//������c���Է�ʽ����
	//��������������deleteҲ�������malloc�����
	//boy.name = (char*)malloc(tmp.length() + 1);
	name = new char[tmp.length() + 1];
	strcpy_s(name, tmp.length() + 1, tmp.c_str());//�ǵý�string���͵�tmpתΪc_str��cpy

	return is;
}

Boy::operator int()const
{
	return age;
}

Boy::operator char* ()
{
	return name;
}

void Boy::description()
{
	cout << "����:" << name << " ����:" << age 
		<< " id:" << id << " ������:" << total_id << endl;
}

/*������ȫ���boy������const
��Ա����ʵ�֣�boy2>>(boy1>>cout) ��ӡ��boy1��Ϣ	<=>cout<<boy1.description()<<bo2.description()
Boy& operator>>(ostream os)
os<<boy
��Ԫ����ʵ�֣�cout<<boy1<<boy2
*д��ͨ������̨д��ı�boy��Ϣ��������const
cin>>boy1>>boy2 boy1���� ���� boy2���� ����(�ǵ�����ո�ָ�)
��Ԫ����ʵ�֣�cin>>boy1;�޸�	��cout<<boy1������̨��ʾ
*/
const Boy& operator<(const Boy& boy1, const Boy& boy2) {//�ǵ�ȫ�ֺ���Ҫ��.h������
	if (boy1.age < boy2.age) {
		return boy1;
	}
	else {
		return boy2;//�����,���ӡ��һ��
	}
}
ostream& operator<<(ostream& os, Boy& boy)
{
	os << "����:" << boy.name << " ����:" << boy.age
		<< " id:" << boy.id << " ������:" << boy.total_id << endl;
	return os;
}
istream& operator>>(istream& is, Boy& boy)
{
	//��Ϊname��char*,����ֱ���޸�,ͨ��string��ת
	string tmp;
	is >> tmp >> boy.age;

	//ԭ�����ö�̬�ڴ�洢,�������
	if (boy.name) {//����Ϊ��ָ��
		delete[] boy.name;
	}

	//��������tmp���ַ����ȷ��䶯̬�ڴ�
	//������c���Է�ʽ����
	//��������������deleteҲ�������malloc�����
	//boy.name = (char*)malloc(tmp.length() + 1);
	boy.name = new char[tmp.length() + 1];
	strcpy_s(boy.name, tmp.length() + 1, tmp.c_str());//�ǵý�string���͵�tmpתΪc_str��cpy

	return is;
}
