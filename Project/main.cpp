#include "Boy.h"
#include "Girl.h"

void automatch(vector<Boy> &boys, vector<Girl> &girls) {
	//遍历两两配对
	for (unsigned int b = 0; b < boys.size(); b++) {
		for (unsigned int g = 0; g < girls.size(); g++) {
			if (boys[b].satisfied(girls[g]) == true && girls[g].satisfied(boys[b]) == true) {//注意调用的是否是函数以及函数是否含参以及含参顺序
				cout << boys[b].getName() << "<-->" << girls[g].getName() << endl;
			}
		}
	}
}

int main() {
	vector<Boy> boys;
	vector<Girl> girls;
	Boy::inputBoys(boys);
	Girl::inputGirls(girls);
	automatch(boys, girls);
}