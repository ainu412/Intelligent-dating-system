#include "Girl.h"
#include <sstream>
#include <iomanip>
#define FACESCORE_COEFFICIENT 100
#include "Boy.h"
Girl::Girl(string name, int age, int faceScore) :Single (name, age) {

	this->faceScore = faceScore;
}

bool Girl::satisfied(const Boy& boy)const
{
	if ( boy.getSalary() >= faceScore*FACESCORE_COEFFICIENT) return true;//因为有boy的方法,所以要包括boy的头文件
	return false;
}

bool Girl::operator>(Girl& girl)
{
	return faceScore > girl.faceScore;
}

void Girl::inputGirls(vector<Girl>& girls)
{
	int n = 1;
	while (1) {
		string name;
		int age;
		int faceScore;

		cout << "请输入第" << n << "位小姐姐的姓名(输入0结束):";
		cin >> name;//需要另外定义形参,最后一并通过vector名.push_back存入
		if (name == "0") break;
		cout << "年龄:";
		cin >> age;
		cout << "颜值:";
		cin >> faceScore;

		girls.push_back(Girl(name, age, faceScore));//可不通过类型调用带参构造函数

		n++;
	}
}
ostream& operator<<(ostream& os, const Girl& girl) {
	os  << "女 姓名:" << setw(9) << left << girl.name//left=setiosflags(ios::left)
		<< " 年龄:" << setw(4) << girl.age
		<< "颜值:" << girl.faceScore << endl;
	return os;
}