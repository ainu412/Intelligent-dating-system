//位图算法bitmap algorithm
#include <iostream>

#define MAX_NUMBER 4000000000//40亿
#define BITS_PER_BYTE 8
#define REQUIREMENT(num) (num) % 3 == 0//要求存储的数字
typedef unsigned int positive_int32;//存储正数位数
typedef int positive_int31;//存储正数位数

void load(char* dataByteP) {
	//num_byte_p = dataByteP / 8;
	for (positive_int32 num = 0; num < MAX_NUMBER; num++) {
		//将符合要求的数所在的地址存的数存为1(1代表存有这个数)
		if (REQUIREMENT(num)) {
			char* num_byte_p = dataByteP + num / BITS_PER_BYTE;//求数字所在字节的首地址:&12=&0+12/8
			//通过指针对所在字节数操作,使得要求的数存的地址存的数字为1
			*num_byte_p = *num_byte_p | (1 << num % BITS_PER_BYTE);//所在字节的第4位:12%8=4;将这一位的数字加1存入,其他位不动加0=>将1左移4位,得到0001_0000相加(位或)原数(*num_byte_p)更新指针所指内容:改变存入的自我,不变其他
		}
	}
}

bool exist(positive_int32 inputNum, char* dataByteP) {
	char* inputNum_byte_p = dataByteP + inputNum / BITS_PER_BYTE;//测试数字所在字节12/8=1,确定所在字节位置&12=&0+12/8
	//检验测试数字所在字节的位(12%8)是否为1(相乘0001_0000,只要1个为1则不为0,排除其他位干扰故其他位必须为0,测验位为1测试对原测验位无改变)检验不变的自我,改变干扰的其他
	if (0 != (*inputNum_byte_p | 1 << inputNum % BITS_PER_BYTE)) {
		return true;
	}
	else {
		return false;
	}
}

int main1() {
	//根据能存储的最大数字分配动态内存(存0-MAX)
	positive_int32 max_bit = MAX_NUMBER;//(int 4字节*8=32位)2的32次方>40亿,因位图算法把每一个数按1个字节1个数占存储,0-0,n-n位
	positive_int31 max_byte = max_bit / BITS_PER_BYTE + 1;//(int 4字节*8=32位,符号占1位)2的31次方>(40亿/8+1=5亿+1):7/8+1=1
	char* data_byte_p = (char*)malloc(max_byte);//dataByteP = &init_num=&0;内存大小以byte计
	memset(data_byte_p, 0, max_byte);//记得清零!!

	//加载数据至分配的内存(传分配的内存的首地址data_byte_p以供加载)
	printf("数据正在加载中...\n");
	load(data_byte_p);

	//测试代码
	//输入
	printf("请输入要测试的数字:");
	positive_int32 inputNum = -1;
	scanf_s("%ud", &inputNum, sizeof(positive_int32));//unsigned int和int存储的位数一样多(32)
	//输出
	if (exist(inputNum, data_byte_p)) {
		printf("存在!\n");
	}
	else {
		printf("不存在!\n");
	}

	return 0;
}
//占用内存大,加载耗时25s,但测试极快!