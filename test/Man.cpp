#include "Man.h"

Man::Man()
{
}

Man::Man(Boy& boy)
{
	//name = boy[NAME_KEY];//const������õĺ���Ҳ����Ϊconst,�������������ͻ??
	//���������interger[pointer-to-object]��ͻ,��boyҲ�ɱ�ʾ��������,��name��ֱ�Ӹ�ֵ��ʽʵ��
	//ֱ�Ӹ�ֵ��ʽ��Ҫ�޸�boyΪchar*��,��ȡ��const
	//�򵥷�������ֱ��getName()

	//age = boy[AGE_KEY];Ҳ��
	age = boy;

	
	int len = strlen((char*)boy);
	name = (char*)malloc(len * sizeof(int) + 1);
	if (!name) {//ȷ��name��Ϊ��
		*name = age;
	}
	strcpy_s(name, len * sizeof(int) + 1, (char*)boy);
}

ostream& operator<<(ostream& os, Man& man)
{
	os << "����:" << man.name << man.age;
	return os;
}
