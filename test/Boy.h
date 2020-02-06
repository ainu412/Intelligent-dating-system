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
	
	//����ı�this���ڶ���ĺ���,ֻ����,��ö�����const��ֹ����۸�
	//�����ӹ�const,�����Ͳ��ü���,��Ϊ����const���������޸ĳ�Ա??���޸Ĵ�����������������?����!
	//���Ҳ����ı䴫���������������ֵ,��˶�����Ϊconst
	const Boy& operator>(const Boy& boy)const;
	
	friend const Boy& operator<(const Boy& boy1, const Boy& boy2);

	void operator==(const Boy& boy)const;

	//�򷵻�ֵ��ͬ���͹ʷֿ�д,ע���������Ҳ������ͬ,��Ȼ�ͻ�һ�Զ�(����ֵ)
	int operator[](KEY key);
	char* operator[](string name_key);

	ostream& operator>>(ostream& os)const;
	istream& operator<<(istream& is);
	friend ostream& operator<<(ostream& os, Boy& boy);
	friend istream& operator>>(istream& is, Boy& boy);
private:
	char* name;//�������볤��,���붯̬�ڴ�ռ�;ֻ��ָ���������,�ʶ���Ϊָ��
	int age;
	int id;
	static int total_id;
};