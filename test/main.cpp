#include <iostream>
using namespace std;

class M {
public:
	M() {
		cout << __FUNCTION__ << endl;
	}
	~M() {
		cout << __FUNCTION__ << endl;
	}
};

class N {
public:
	N() {
		cout << __FUNCTION__ << endl;
	}
	~N() {
		cout << __FUNCTION__ << endl;
	}
};

class A {
public:
	A() {
		cout << __FUNCTION__ << endl;
	}
	~A() {
		cout << __FUNCTION__ << endl;
	}
};

class B :public A{//��ʽ����
public:
	B() {
		cout << __FUNCTION__ << endl;
	}
	~B() {
		cout << __FUNCTION__ << endl;
	}
private:
	M m1;
	M m2;
	static N n_s;
};

N n_s;//��̬���ݳ�Ա

int main() {
	{B b1; }
	
	cout << "-------" << endl;
	B b2;//��̬���ݳ�Ա������һ��

	return 0;
}