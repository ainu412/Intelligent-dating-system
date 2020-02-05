#include "Beef.h"

int main() {
	Beef b1(1),b100(100);
	Lamb l2(2),l200(200);
	Pork p3(3), p300(300),p1,p2;

	p1 = b1 + l2;
	p1.description();

	p1 = b1 + b100;
	p1.description();

	p1 = l2 + l200;
	p1.description();

	p2 = p3 + p300;
	p2.description();

}