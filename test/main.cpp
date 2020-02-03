#include <iostream>
using namespace std;

//电话
//虚基类
class Tel {
public:
	int getNum() {
		return num;
	}
protected:
	int num = 0;
};
//座机
class FixedLine :virtual public Tel {//虚继承仅同步

};
//手机
class MobilePhone :virtual public Tel {//虚继承仅同步

};
//无线座机
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