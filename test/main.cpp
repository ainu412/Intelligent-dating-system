#include "Boy.h"
#include "Man.h"
int main() {
	Boy b1(1), b2(2);//û��Ĭ�Ϲ��캯���Ͱ����ι��캯����Ĭ��ֵ��ʼ����?
			   //�ǵ�,��Ĭ�ϲ���������ʱд��
			   //ûд�õĻ�main�г�ʼ������:b1������,b1()�������
	Boy b3("Larry", 22);
	//b1(b2);������������ع��캯��	Boy& operator()(const Boy& boy);
	b1.description();
	b2.description();
	b3.description();

	b2 = b3;

	b1.description();
	b2.description();//boy���Ҳ�����ϵ�??
	//b3.description();
	/*

	Boy b1("Larry", 22);
	Boy b2("J", 20);

	Boy b= (b1 > b2);//��ȴ�ӡ�Լ�(�����ǰ��)b1.(b2)
	b.description();

	b = (b1 < b2);//��ȴ�ӡ����(��������)(b1,b2)
	b.description();

	b1 == b2;

	//cout << b1[NAME_KEY] << endl;
	cout << b1[AGE_KEY] << endl;

	b2 >> (b1 >> cout);//��Ա����������ʶ
	cout << b1 << b2;//��Ԫ����

	b2 << (b1 << cin);//��Ա����:����ʶ
	cin >> b1 >> b2;//��Ԫ����
	cout << b1 << b2;

	//���������󻹿���ͨ�����캯���ı�������?
	//��Boy b2;b2("����", 18);������,ֻ��ͨ��operator()
	//�ʹ��캯���п�ֱ��д�ϸ����ݳ�ʼֵ,��age=0��û������ageֵ

	Boy b10 = 10, ba = "a";//��ͨ���� => ������:���ô��ι��캯��
	b10.description();
	ba.description();

	int age = b1;
	int len = strlen((char*)b1);
	char* name = (char*)malloc(len * sizeof(int) + 1);
	if (!name) {//ȷ��name��Ϊ��
		*name = age;
	}
	strcpy_s(name, len * sizeof(int) + 1, (char*)b1);//������ => ��ͨ����:
	cout << name << endl << age;

	Man m1 = b1;//��A => ��B
	cout << m1;
	*/
	return 0;
}