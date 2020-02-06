#include "Boy.h"
int Boy::total_id = 0;//记得声明所属类

Boy::Boy(const char* name, int age)
{
	if (!name) {//参数有指针则一定要考虑指针为空情况(包括默认和用户输入空字符情况)
		name = "未命名";//为了赋常字符串,要把name类型也改为const
	}

	//依据输入长度申请动态内存
	this->name = new char[strlen(name)+1];//记得包括字符串末尾的'\0'
	strcpy_s(this->name, strlen(name) + 1, name);

	this->age = age;
	id = ++total_id;
}

Boy::~Boy() {
	delete[] name;//除掉初始化时申请的内存
}

Boy& Boy::operator=(const Boy& boy) {
	//视需求而定
	//一般不需要释放赋值boy的内存,因为不覆盖原内存信息,仅被赋值
	//delete[] boy.name;
	//需释放将被赋值boy的原有name内存
	delete[]name;

	if (!boy.name) {
		cout << "赋值男生姓名指针为空!" << endl;
		exit(1);
	}

	//为新的被赋值的名字分配新的内存空间
	name = new char[strlen(boy.name) + 1];
	strcpy_s(name, strlen(boy.name) + 1, boy.name);

	age = boy.age;

	//id = boy.id;//id是否复制,视需求而定
	//因赋值构造函数已经初始化过,已经使得总数+1,此处不必再加
	//若覆盖原有,则总数-1
	//total_id--;

	//为方便链式调用b1=b2=b3,需要返回新值自己(若返回void则b1=void×)(=为从右向左赋值)
	return *this;
}

const Boy& Boy::operator>(const Boy& boy)const//
{
	if (age > boy.age) {
		return boy;//返回值类型与参数保持一致
	}
	else {
		return *this;//若相等,也打印自己
	}
}

void Boy::operator==(const Boy& boy)const
{
	if (age == boy.age) {
		cout << "二者年龄相同!" << endl;
	}
}
int Boy::operator[](KEY key)
{
	switch (key) {
	case(AGE_KEY):
		return age;
		break;
	case(ID_KEY):
		return id;
		break;
	default:
		return -1;
		break;
	}
}
char* Boy::operator[](string name_key)
{
	if (NAME_KEY == name_key) {
		return name;
	}
}

ostream& Boy::operator>>(ostream& os)const//记得用别名,只读加const
{
	os  << "姓名:" << name << " 年龄:" << age
		<< " id:" << id << " 总人数:" << total_id << endl;
	return os;
}

istream& Boy::operator<<(istream& is) 
{
	//因为name是char*,不能直接修改,通过string中转
	string tmp;
	is >> tmp >> age;

	//原先是用动态内存存储,故先清掉
	if (name) {//若不为空指针
		delete[] name;
	}

	//根据输入tmp的字符长度分配动态内存
	//可以以c语言方式分配
	//反正析构函数的delete也可以清除malloc分配的
	//boy.name = (char*)malloc(tmp.length() + 1);
	name = new char[tmp.length() + 1];
	strcpy_s(name, tmp.length() + 1, tmp.c_str());//记得将string类型的tmp转为c_str再cpy

	return is;
}

void Boy::description()
{
	cout << "姓名:" << name << " 年龄:" << age 
		<< " id:" << id << " 总人数:" << total_id << endl;
}
