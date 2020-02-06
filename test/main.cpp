#include "Boy.h"

const Boy& operator<(const Boy& boy1, const Boy& boy2) {
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
/*读：安全起见boy类型用const
成员函数实现：boy2>>(boy1>>cout) 打印出boy1信息	<=>cout<<boy1.description()<<bo2.description()
Boy& operator>>(ostream os)
os<<boy
友元函数实现：cout<<boy1<<boy2
*写：通过控制台写入改变boy信息，不能用const
cin>>boy1>>boy2 boy1姓名 年龄 boy2姓名 年龄(记得输入空格分隔)
友元函数实现：cin>>boy1;修改	再cout<<boy1；控制台显示
*/
int main() {
	/*Boy b1, b2;//没有默认构造函数就按带参构造函数的默认值初始化吗?
			   //是滴,若默认参数在声明时写好
			   //没写好的话main中初始化对象:b1会出错的,b1()不会出错
	Boy b3("Larry", 22);
	//b1(b2);调用运算符重载构造函数	Boy& operator()(const Boy& boy);
	b1.description();
	b2.description();
	b3.description();

	b1 = b2 = b3;

	b1.description();
	b2.description();
	b3.description();
	*/

	Boy b1("Larry", 22);
	Boy b2("J", 20);

/*	Boy b;
	b = (b1 > b2);//相等打印自己(运算符前的)b1.(b2)
	b.description();

	b = (b1 < b2);//相等打印别人(运算符后的)(b1,b2)
	b.description();

	b1 == b2;

	cout << b1[NAME_KEY] << endl;
	cout << b1[AGE_KEY] << endl;
*/
	b2 >> (b1 >> cout);//成员函数：反常识
	cout << b1 << b2;//友元函数

	b2 << (b1 << cin);//成员函数:反常识
	cin >> b1 >> b2;//友元函数
	cout << b1 << b2;

	return 0;
}