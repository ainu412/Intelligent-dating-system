#include <iostream>
using namespace std;

//�绰
//�����
class Tel {
public:
	int getNum() {
		return num;
	}
protected:
	int num = 0;
};
//����
class FixedLine :virtual public Tel {//��̳н�ͬ��

};
//�ֻ�
class MobilePhone :virtual public Tel {//��̳н�ͬ��

};
//��������
class WirelessTel :public FixedLine, public MobilePhone {
public:
	int getNum(){
		return num;
	}
	void setNum(int num) {
		this->num = num;
	}
};

int main() {
	WirelessTel w;

	w.setNum(123);
	cout << w.getNum() << endl;//123

	return 0;
}