#include "Boy.h"

const Boy& operator<(const Boy& boy1, const Boy& boy2) {
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
/*������ȫ���boy������const
��Ա����ʵ�֣�boy2>>(boy1>>cout) ��ӡ��boy1��Ϣ	<=>cout<<boy1.description()<<bo2.description()
Boy& operator>>(ostream os)
os<<boy
��Ԫ����ʵ�֣�cout<<boy1<<boy2
*д��ͨ������̨д��ı�boy��Ϣ��������const
cin>>boy1>>boy2 boy1���� ���� boy2���� ����(�ǵ�����ո�ָ�)
��Ԫ����ʵ�֣�cin>>boy1;�޸�	��cout<<boy1������̨��ʾ
*/
int main() {
	/*Boy b1, b2;//û��Ĭ�Ϲ��캯���Ͱ����ι��캯����Ĭ��ֵ��ʼ����?
			   //�ǵ�,��Ĭ�ϲ���������ʱд��
			   //ûд�õĻ�main�г�ʼ������:b1������,b1()�������
	Boy b3("Larry", 22);
	//b1(b2);������������ع��캯��	Boy& operator()(const Boy& boy);
	b1.description();
	b2.description();
	b3.description();

	b1 = b2 = b3;

	b1.description();
	b2.description();
	b3.description();
	*/

	Boy b1("Larry", 22);
	Boy b2("J", 20);

/*	Boy b;
	b = (b1 > b2);//��ȴ�ӡ�Լ�(�����ǰ��)b1.(b2)
	b.description();

	b = (b1 < b2);//��ȴ�ӡ����(��������)(b1,b2)
	b.description();

	b1 == b2;

	cout << b1[NAME_KEY] << endl;
	cout << b1[AGE_KEY] << endl;
*/
	b2 >> (b1 >> cout);//��Ա����������ʶ
	cout << b1 << b2;//��Ԫ����

	b2 << (b1 << cin);//��Ա����:����ʶ
	cin >> b1 >> b2;//��Ԫ����
	cout << b1 << b2;

	return 0;
}