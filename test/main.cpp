#include "Boy.h"

int main() {
	Boy b1, b2;//没有默认构造函数就按带参构造函数的默认值初始化吗?
	Boy b3("Larry", 22);
	//b1(b2);调用运算符重载构造函数	Boy& operator()(const Boy& boy);
	b1.description();
	b2.description();
	b3.description();

	b1 = b2 = b3;

	b1.description();
	b2.description();
	b3.description();

	return 0;
}