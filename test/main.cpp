#include "Computer.h"
#include "Service.h"

int main() {
	Computer computer("i7");
	cout << computer.description();
	upgrade(&computer);
	cout << computer.description();

	Service service;
	service.up(&computer, "i8");
	cout << computer.description();
}
