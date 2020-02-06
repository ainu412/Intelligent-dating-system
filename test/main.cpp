#include "Boy.h"

const Boy& operator<(const Boy& boy1, const Boy& boy2) {
	if (boy1.age < boy2.age) {
		return boy1;
	}
	else {
		return boy2;//若相等,则打印另一人
	}
}

int main() {
	/*Boy b1, b2;//没有默认构造函数就按带参构造函数的默认值初始化吗?
			   //是滴,若默认参数在声明时写好
			   //没写好的话main中初始化对象:b1会出错的,b1()不会出错
	Boy b3("Larry", 22);
	//b1(b2);调用运算符重载构造函数	Boy& operator()(const Boy& boy);
	b1.description();
	b2.description();
	b3.description();

	b1 = b2 = b3;

	b1.description();
	b2.description();
	b3.description();
	*/

	Boy b1("Larry", 20);
	Boy b2("J", 20);

	Boy b;
	b = (b1 > b2);//相等打印自己(运算符前的)b1.(b2)
	b.description();

	b = (b1 < b2);//相等打印别人(运算符后的)(b1,b2)
	b.description();

	b1 == b2;

	return 0;
}