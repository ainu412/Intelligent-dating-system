#include "Boy.h"

int main() {
	Boy b1, b2;//û��Ĭ�Ϲ��캯���Ͱ����ι��캯����Ĭ��ֵ��ʼ����?
	Boy b3("Larry", 22);
	//b1(b2);������������ع��캯��	Boy& operator()(const Boy& boy);
	b1.description();
	b2.description();
	b3.description();

	b1 = b2 = b3;

	b1.description();
	b2.description();
	b3.description();

	return 0;
}