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
	char* name;//�������볤��,���붯̬�ڴ�ռ�;ֻ��ָ���������,�ʶ���Ϊָ��
	int age;
	int id;
	static int total_id;
};