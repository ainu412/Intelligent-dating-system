#include <iostream>
using namespace std;

//�绰
class Tel {
public:
	int getNum() {
		return num;
	}
protected:
	int num = 0;
};
//����
class FixedLine :public Tel {

};
//�ֻ�
class MobilePhone :public Tel {

};
//��������
class WirelessTel :public FixedLine, public MobilePhone {
public:
	int getNum(){
		return FixedLine::num;
	}
	void setNum(int num) {
		this->MobilePhone::num = num;
	}
};

int main() {
	WirelessTel w;

	w.setNum(123);//�����趨������,�������ø��ֻ�
	cout << w.getNum() << endl;//0

	return 0;
}