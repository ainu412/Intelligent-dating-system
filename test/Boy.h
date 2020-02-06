#pragma once
#include <iostream>
class Boy
{
public:
	Boy(const char* name = NULL, int age = 0);
	void description();
	Boy& operator=(const Boy& boy);
	~Boy();
private:
	char* name;//对于输入长度,申请动态内存空间;只有指针才能申请,故定义为指针
	int age;
	int id;
	static int total_id;
};