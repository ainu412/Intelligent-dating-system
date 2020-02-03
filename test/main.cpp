#include "Father.h"
#include "Son.h"

int main() {
	Father wjl("王健林", 68);//Father::Father带参
	Son wsc;//Father::Father不带参 Son::Son不带参
	cout << wjl.description();
	cout << wsc.description();

	//仅数据成员占用内存
	cout << sizeof(wjl) << endl;//32
	cout << sizeof(wsc) << endl;//60

	system("pause");
	return 0;
}