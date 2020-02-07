#include "Boy.h"
int Boy::total_id = 0;//记得声明所属类

Boy::Boy(const char* name,const int age)
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

Boy::Boy(int age)
{

	const char tmp[10] = "未命名";//为了赋常字符串,要把name类型也改为const
	this->name = new char[strlen(tmp) + 1];//记得包括字符串末尾的'\0'
	strcpy_s(this->name, strlen(tmp) + 1, tmp);

	this->age = age;
	id = ++total_id;
}

Boy::Boy(const char* name)
{
	if (!name) {//参数有指针则一定要考虑指针为空情况(包括默认和用户输入空字符情况)
		name = "未命名";//为了赋常字符串,要把name类型也改为const
	}

	//依据输入长度申请动态内存
	this->name = new char[strlen(name) + 1];//记得包括字符串末尾的'\0'
	strcpy_s(this->name, strlen(name) + 1, name);

	this->age = 0;
	id = ++total_id;
}

Boy::Boy(const Boy& boy)
{
	//初始化时调用拷贝构造函数
	//对象还没生成,不用删除内存
	name = new char[strlen(boy.name) + 1];
	strcpy_s(name, strlen(boy.name) + 1, boy.name);

	age = boy.age;
	id = ++total_id;
}

Boy::~Boy() {
	delete[] name;//除掉初始化时申请的内存
}

Boy& Boy::operator=(const Boy& boy) {//参数若为指针,不认!!
	//视需求而定
	//一般不需要释放赋值boy的内存,因为不覆盖原内存信息,仅被赋值
	//delete[] boy.name;
	//需释放将被赋值boy的原有name内存
	if (name) {
		delete[]name;
	}

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

//Boy& Boy::operator=(const Boy* boy) {//浅赋值:=浅拷贝
//	name = boy->name;//地址不能直接赋值,会拥堵
//	age = boy->age;
//	id = boy->id;
//}
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

int Boy::operator[](KEY key)const
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
char* Boy::operator[](string name_key)const
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

Boy::operator int()const
{
	return age;
}

Boy::operator char* ()
{
	return name;
}

void Boy::description()
{
	cout << "姓名:" << name << " 年龄:" << age 
		<< " id:" << id << " 总人数:" << total_id << endl;
}

/*读：安全起见boy类型用const
成员函数实现：boy2>>(boy1>>cout) 打印出boy1信息	<=>cout<<boy1.description()<<bo2.description()
Boy& operator>>(ostream os)
os<<boy
友元函数实现：cout<<boy1<<boy2
*写：通过控制台写入改变boy信息，不能用const
cin>>boy1>>boy2 boy1姓名 年龄 boy2姓名 年龄(记得输入空格分隔)
友元函数实现：cin>>boy1;修改	再cout<<boy1；控制台显示
*/
const Boy& operator<(const Boy& boy1, const Boy& boy2) {//记得全局函数要在.h中声明
	if (boy1.age < boy2.age) {
		return boy1;
	}
	else {
		return boy2;//若相等,则打印另一人
	}
}
ostream& operator<<(ostream& os, Boy& boy)
{
	os << "姓名:" << boy.name << " 年龄:" << boy.age
		<< " id:" << boy.id << " 总人数:" << boy.total_id << endl;
	return os;
}
istream& operator>>(istream& is, Boy& boy)
{
	//因为name是char*,不能直接修改,通过string中转
	string tmp;
	is >> tmp >> boy.age;

	//原先是用动态内存存储,故先清掉
	if (boy.name) {//若不为空指针
		delete[] boy.name;
	}

	//根据输入tmp的字符长度分配动态内存
	//可以以c语言方式分配
	//反正析构函数的delete也可以清除malloc分配的
	//boy.name = (char*)malloc(tmp.length() + 1);
	boy.name = new char[tmp.length() + 1];
	strcpy_s(boy.name, tmp.length() + 1, tmp.c_str());//记得将string类型的tmp转为c_str再cpy

	return is;
}
