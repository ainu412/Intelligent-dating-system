#include "Car.h"
#include "Tire.h"

int main() {
	Car car("��������", "Roadster", 808, 0, "��������", "V12");//��
	cout << car.description();//��ӡ��������
	
	Tire tire1("������", 1, 340);//����̥
	car.addTire(tire1);
	Tire tire2("������2", 2, 342);
	car.addTire(tire2);
	vector<Tire*> tires = car.getTires();
	for (unsigned int i = 0; i < tires.size(); i++) {
		cout << tires[i]->description();
	}

}