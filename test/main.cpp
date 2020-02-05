#include "Beef.h"
Pork operator+(Beef& beef, Lamb& lamb){//因牛肉的重量没有public函数可获得,故定义此函数为牛的友元函数,以访问其私有重量
	int tmp = beef.weight * 2 + lamb.getWeight() * 3;
	return Pork(tmp);
}
Pork operator+(Beef& beef1, Beef& beef2) {//因牛肉的重量没有public函数可获得,故定义此函数为牛的友元函数,以访问其私有重量
	int tmp = beef1.weight * 2 + beef2.weight * 2;
	return Pork(tmp);
}
int main() {
	Beef b1(1),b100(100);
	Lamb l2(2),l200(200);
	Pork p3(3), p300(300),p1,p2;

	p1 = b1 + l2;//8
	p1.description();

	p1 = b1 + b100;//202
	p1.description();

	//p1 = l2 + b1;×
	//1)l2.operator+(b1)=>Lamb中添加Pork operator+(Beef& beef)函数
	//2)operator+(l2,b1)=>外部添加Pork operator+(Lamb& lamb,Beef& beef)函数


	//p1 = l2 + l200;
	//p1.description();

	//p2 = p3 + p300;
	//p2.description();

}