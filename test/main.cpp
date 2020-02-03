#include <iostream>
using namespace std;

class A {
public:
	void eat(){
		cout << "爸比在吃饭!" << endl;
	}

};
class B :public A{
public:
	void eat() {
		cout << "儿子在吃饭!" << endl;
	}

};
void army(A a) {
	cout << "参军!" << endl;
}
void party(A *a1, A *a2) {//指针传对象效率更高
	a1->eat();
	a2->eat();
}
int main() {
	A a;
	B b;
	a.eat();
	b.eat();
	//1.使用父类的任何地方都可以使用公有子类
	army(b);//替父从军

	//2.任何公有子类代替父类的地方实际调用的都是父类,子类只是形式
	party(&a, &b);//只能爸比吃饭

	//3.子类可以赋值给父类,赋值后调用的还是父类
	B b1, b2, b3;
	A *a1, &a2=b2, a3;//②引用对象必须初始化
	a1 = &b1;//①
	a3 = b3;//③
	party(a1, &a2);//只能爸比去开派对

	return 0;
}