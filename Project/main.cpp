#include "Boy.h"
#include "Girl.h"
#include "Database.h"
//inputGirls:控制台->vector
//saveGirls:vector->文件
bool input = false;
int main() {
	string in;
	cout << "是否输入新的用户信息[是/否]:";
	cin >> in;
	input = (in == "是" ? true : false);

	Database data;
	data.load(input);
	data.print();
	data.automatch();

	return 0;
}