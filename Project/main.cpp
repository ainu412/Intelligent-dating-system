#include "Boy.h"
#include "Girl.h"
#include <vector>

int main() {
	vector<Boy> boys;
	Boy boy1("小王", 25, 40000);
	Boy boy2("小林", 28, 50000);
	boys.push_back(boy1);
	boys.push_back(boy2);
	for (unsigned int i = 0; i < boys.size(); i++) {
		cout << boys[i].description() << endl;
	}
}