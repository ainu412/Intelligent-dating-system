#include "Man.h"

Man::Man()
{
}

Man::Man(Boy& boy)
{
	//name = boy[NAME_KEY];//const对象调用的函数也必须为const,与内置运算符冲突??
	//内置运算符interger[pointer-to-object]冲突,因boy也可表示年龄整数,故name用直接赋值方式实现
	//直接赋值方式需要修改boy为char*型,故取消const
	//简单方法还是直接getName()

	//age = boy[AGE_KEY];也可
	age = boy;

	
	int len = strlen((char*)boy);
	name = (char*)malloc(len * sizeof(int) + 1);
	if (!name) {//确保name不为空
		*name = age;
	}
	strcpy_s(name, len * sizeof(int) + 1, (char*)boy);
}

ostream& operator<<(ostream& os, Man& man)
{
	os << "男人:" << man.name << man.age;
	return os;
}
