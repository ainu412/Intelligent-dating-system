#include "Boy.h"
#include "Girl.h"
#include "Database.h"

//inputGirls:控制台->vector
//saveGirls:vector->文件
bool input = true;

//打印所有用户信息和配对信息
void allMatches() {
	string in;
	cout << "是否输入新的用户信息[是/否]:";
	cin >> in;
	input = (in == "是" ? true : false);

	Database data;
	data.load(input);
	data.print();
	data.allMatch();
}

//仅显示输入用户的配对信息,并将输入用户的信息存入文件
void inputMatches() {//单身女配对:一个女和所有男试一遍,把和自己合适的全部印出,故上述automatch算法要交换g b位置
	Database data;
	data.load(input);
	data.inputMatch();
}

//打印所有用户的最佳配对信息
void allBestMatches() {
	Database data;
	data.load(false);
	data.allBestMatch();
}

//打印输入用户的最佳配对信息
void inputBestMatches() {
	Database data;
	data.load(true);
	data.inputBestMatch();
}

int main() {
	allBestMatches();
	return 0;
}