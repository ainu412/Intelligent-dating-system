#include <iostream>
using namespace std;

class A {
public:
	void eat(){
		cout << "�ֱ��ڳԷ�!" << endl;
	}

};
class B :public A{
public:
	void eat() {
		cout << "�����ڳԷ�!" << endl;
	}

};
void army(A a) {
	cout << "�ξ�!" << endl;
}
void party(A *a1, A *a2) {//ָ�봫����Ч�ʸ���
	a1->eat();
	a2->eat();
}
int main() {
	A a;
	B b;
	a.eat();
	b.eat();
	//1.ʹ�ø�����κεط�������ʹ�ù�������
	army(b);//�游�Ӿ�

	//2.�κι���������游��ĵط�ʵ�ʵ��õĶ��Ǹ���,����ֻ����ʽ
	party(&a, &b);//ֻ�ֱܰȳԷ�

	//3.������Ը�ֵ������,��ֵ����õĻ��Ǹ���
	B b1, b2, b3;
	A *a1, &a2=b2, a3;//�����ö�������ʼ��
	a1 = &b1;//��
	a3 = b3;//��
	party(a1, &a2);//ֻ�ֱܰ�ȥ���ɶ�

	return 0;
}