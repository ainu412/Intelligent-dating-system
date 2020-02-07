#include "Boy.h"
#include "Man.h"
int main() {
	Boy b1(1), b2(2);//没有默认构造函数就按带参构造函数的默认值初始化吗?
			   //是滴,若默认参数在声明时写好
			   //没写好的话main中初始化对象:b1会出错的,b1()不会出错
	Boy b3("Larry", 22);
	//b1(b2);调用运算符重载构造函数	Boy& operator()(const Boy& boy);
	b1.description();
	b2.description();
	b3.description();

	b2 = b3;

	b1.description();
	b2.description();//boy深拷贝也触发断点??
	//b3.description();
	/*

	Boy b1("Larry", 22);
	Boy b2("J", 20);

	Boy b= (b1 > b2);//相等打印自己(运算符前的)b1.(b2)
	b.description();

	b = (b1 < b2);//相等打印别人(运算符后的)(b1,b2)
	b.description();

	b1 == b2;

	//cout << b1[NAME_KEY] << endl;
	cout << b1[AGE_KEY] << endl;

	b2 >> (b1 >> cout);//成员函数：反常识
	cout << b1 << b2;//友元函数

	b2 << (b1 << cin);//成员函数:反常识
	cin >> b1 >> b2;//友元函数
	cout << b1 << b2;

	//函数创建后还可以通过构造函数改变数据吗?
	//如Boy b2;b2("肉肉", 18);不可以,只能通过operator()
	//故构造函数中可直接写上各数据初始值,如age=0若没有输入age值

	Boy b10 = 10, ba = "a";//普通类型 => 类类型:利用带参构造函数
	b10.description();
	ba.description();

	int age = b1;
	int len = strlen((char*)b1);
	char* name = (char*)malloc(len * sizeof(int) + 1);
	if (!name) {//确保name不为空
		*name = age;
	}
	strcpy_s(name, len * sizeof(int) + 1, (char*)b1);//类类型 => 普通类型:
	cout << name << endl << age;

	Man m1 = b1;//类A => 类B
	cout << m1;
	*/
	return 0;
}