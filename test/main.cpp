#include "Son.h"//Son��������Father,��ֻдSon����

int main() {
	Son s("����", 21, "������", "galgame");

	//������ؼ̳еĶ�����
	//������:�����޶�	
	cout << s.Father::description() << endl;
	cout << s.Mother::description() << endl;

	//�ڶ�������:ͬ�����������޶�,���Ƕ�ѡ��
	cout << s.description() << endl;
	s.dance();

	return 0;
}
