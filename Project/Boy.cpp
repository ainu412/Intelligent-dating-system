#include "Boy.h"
#include <sstream>
#include <iomanip>
#include "Girl.h"
#define SALARY_COEFFICIENT 0.006

Boy::Boy(string name = "", int age = 0, int salary = 0) 
	:Single(name, age),salary(salary) {}//若二者合一,则定义新变量时是否需要带括号??必须带括号,因为不存在默认构造函数!


bool Boy::satisfied(const Girl& girl)const
{	
	int satisfiedFaceScore = salary * SALARY_COEFFICIENT;
	if (salary * SALARY_COEFFICIENT > 100) satisfiedFaceScore = 100;
	if (girl.trait() >= satisfiedFaceScore) return true;
	return false;
}

//string Boy::description()const
//{
//	stringstream ret;
//	ret << "男 姓名:" << setw(9) << left << name 
//		<< " 年龄:" << setw(4) << age 
//		<< "月薪:" << salary;//流向ret;cout<<xxx,为将xxx流向控制台输出
//	return ret.str();
//}

bool Boy::operator>(const Boy& boy)const
{
	return salary > boy.salary;
}

void Boy::inputBoys(vector<Boy>& boys)
{
	{int n = 1;
		while (1) {
			string name;
			int age;
			int salary;

			cout << "请输入第" << n << "位小哥哥的姓名(输入0结束):";
			cin >> name;//需要另外定义形参,最后一并通过vector名.push_back存入,push_back意为推到最后面,每次加入的都位于最后,像排队一样
			if (name == "0") break;
			cout << "年龄:";
			cin >> age;
			cout << "月薪:";
			cin >> salary;

			boys.push_back(Boy(name, age, salary));//可不通过类型调用带参构造函数

			n++;
		}
	}
}
//cout << 重载和比较 < 重载
ostream& operator<<(ostream& os, const Boy& boy) {//直接打印,无需返回stringstream.str()的函数中转
	os << "男 姓名:" << setw(9) << left << boy.name
		<< " 年龄:" << setw(4) << boy.age
		<< "月薪:" << boy.salary << endl;
	return os;
}
