#pragma once
#include <iostream>
using namespace std;
typedef enum {
	AGE_KEY,
	ID_KEY
}KEY;
#define NAME_KEY "name"

class Boy
{
public:
	Boy(const char* name = NULL, int age = 0);
	~Boy();

	void description();

	Boy& operator=(const Boy& boy);
	
	//不会改变this所在对象的函数,只读的,最好都加上const防止恶意篡改
	//函数加过const,参数就不用加了,因为函数const包含不能修改成员??能修改传进来的其他对象吗?可以!
	//如果也不会改变传进来的其他对象的值,则此对象设为const
	const Boy& operator>(const Boy& boy)const;
	
	friend const Boy& operator<(const Boy& boy1, const Boy& boy2);

	void operator==(const Boy& boy)const;

	//因返回值不同类型故分开写,注意参数类型也不能相同,不然就会一对多(返回值)
	int operator[](KEY key);
	char* operator[](string name_key);

	ostream& operator>>(ostream& os)const;
	istream& operator<<(istream& is);
	friend ostream& operator<<(ostream& os, Boy& boy);
	friend istream& operator>>(istream& is, Boy& boy);
private:
	char* name;//对于输入长度,申请动态内存空间;只有指针才能申请,故定义为指针
	int age;
	int id;
	static int total_id;
};