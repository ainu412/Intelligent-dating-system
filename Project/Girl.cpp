#include "Girl.h"
#include <sstream>
#define FACESCORE_COEFFICIENT 300
#include "Boy.h"
Girl::Girl(){
	name = "";
	age = 0;
	faceScore = 0;
}
Girl::Girl(string name, int age, int faceScore){
	this->name = name;
	this->age = age;
	this->faceScore = faceScore;
}
string Girl::getName()const{
	return name;
}
int Girl::getAge()const{
	return age;
}
int Girl::getFaceScore()const{
	return faceScore;
}

bool Girl::satisfied(const Boy& boy)const
{
	if ( boy.getSalary() > faceScore*FACESCORE_COEFFICIENT) return true;//因为有boy的方法,所以要包括boy的头文件
	return false;
}

string Girl::description()const
{
	stringstream ret;
	ret << "女:姓名(" << name << "),年龄(" << age << "),颜值(" << faceScore << ").";//流向ret;cout<<xxx,为将xxx流向控制台输出
	return ret.str();
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
