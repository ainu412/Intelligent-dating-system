#include <iostream>
using namespace std;

//电话
class Tel {
public:
	int getNum() {
		return num;
	}
protected:
	int num = 0;
};
//座机
class FixedLine :public Tel {

};
//手机
class MobilePhone :public Tel {

};
//无线座机
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

	w.setNum(123);//号码设定给座机,而号码获得给手机
	cout << w.getNum() << endl;//0

	return 0;
}