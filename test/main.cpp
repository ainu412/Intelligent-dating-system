#include "Father.h"
#include "Son.h"

int main() {
	Father wjl("������", 68);//Father::Father����
	Son wsc;//Father::Father������ Son::Son������
	cout << wjl.description();
	cout << wsc.description();

	//�����ݳ�Առ���ڴ�
	cout << sizeof(wjl) << endl;//32
	cout << sizeof(wsc) << endl;//60

	system("pause");
	return 0;
}