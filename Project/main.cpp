#include "Boy.h"
#include "Girl.h"

int main() {
	vector<Boy> boys;
	Boy::inputBoys(boys);
	for (unsigned int i = 0; i < boys.size(); i++) {
		cout << boys[i].description() << endl;
	}

	vector<Girl> girls;
	Girl::inputGirls(girls);
	for (unsigned int i = 0; i < girls.size(); i++) {
		cout << girls[i].description() << endl;
	}
}