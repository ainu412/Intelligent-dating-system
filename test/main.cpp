#include "Son.h"//Son里面必须带Father,故只写Son即可

int main() {
	Son s("肉肉", 21, "红烧肉", "galgame");

	//解决多重继承的二义性
	//①类外:类名限定	
	cout << s.Father::description() << endl;
	cout << s.Mother::description() << endl;

	//②儿子类内:同名方法类名限定,覆盖多选择
	cout << s.description() << endl;
	s.dance();

	return 0;
}
