#include "Car.h"
#include "Tire.h"

int main() {
	Car car("兰博基尼", "Roadster", 808, 0, "兰博基尼", "V12");//买车
	cout << car.description();//打印车的描述
	
	Tire tire1("米其林", 1, 340);//加轮胎
	car.addTire(tire1);
	Tire tire2("米其林2", 2, 342);
	car.addTire(tire2);
	vector<Tire*> tires = car.getTires();
	for (unsigned int i = 0; i < tires.size(); i++) {
		cout << tires[i]->description();
	}

}