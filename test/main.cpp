#include "Boy.h"

const Boy& operator<(const Boy& boy1, const Boy& boy2) {
	if (boy1.age < boy2.age) {
		return boy1;
	}
	else {
		return boy2;//�����,���ӡ��һ��
	}
}

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

	Boy b1("Larry", 20);
	Boy b2("J", 20);

	Boy b;
	b = (b1 > b2);//��ȴ�ӡ�Լ�(�����ǰ��)b1.(b2)
	b.description();

	b = (b1 < b2);//��ȴ�ӡ����(��������)(b1,b2)
	b.description();

	b1 == b2;

	return 0;
}