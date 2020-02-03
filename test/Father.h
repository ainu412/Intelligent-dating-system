#pragma once
#include <iostream>
#include <sstream>
using namespace std;

class Father
{public:
	//Father();
	Father(string name = "Î´ÖªĞÕÃû", int age = 0);
	~Father();

	string getName();
	int getAge();
	string description();

	void ball() {
		cout << "°Ö°ÖÏ²»¶´òÇò" << endl;
	}
	void dance() {
		cout << "°Ö°ÖÒ²Ï²»¶ÌøÎè" << endl;
	}
protected:
	string name;
private:
	int age;
};

