//λͼ�㷨bitmap algorithm
#include <iostream>

#define MAX_NUMBER 4000000000//40��
#define BITS_PER_BYTE 8
#define REQUIREMENT(num) (num) % 3 == 0//Ҫ��洢������
typedef unsigned int positive_int32;//�洢����λ��
typedef int positive_int31;//�洢����λ��

void load(char* dataByteP) {
	//num_byte_p = dataByteP / 8;
	for (positive_int32 num = 0; num < MAX_NUMBER; num++) {
		//������Ҫ��������ڵĵ�ַ�������Ϊ1(1������������)
		if (REQUIREMENT(num)) {
			char* num_byte_p = dataByteP + num / BITS_PER_BYTE;//�����������ֽڵ��׵�ַ:&12=&0+12/8
			//ͨ��ָ��������ֽ�������,ʹ��Ҫ�������ĵ�ַ�������Ϊ1
			*num_byte_p = *num_byte_p | (1 << num % BITS_PER_BYTE);//�����ֽڵĵ�4λ:12%8=4;����һλ�����ּ�1����,����λ������0=>��1����4λ,�õ�0001_0000���(λ��)ԭ��(*num_byte_p)����ָ����ָ����:�ı���������,��������
		}
	}
}

bool exist(positive_int32 inputNum, char* dataByteP) {
	char* inputNum_byte_p = dataByteP + inputNum / BITS_PER_BYTE;//�������������ֽ�12/8=1,ȷ�������ֽ�λ��&12=&0+12/8
	//����������������ֽڵ�λ(12%8)�Ƿ�Ϊ1(���0001_0000,ֻҪ1��Ϊ1��Ϊ0,�ų�����λ���Ź�����λ����Ϊ0,����λΪ1���Զ�ԭ����λ�޸ı�)���鲻�������,�ı���ŵ�����
	if (0 != (*inputNum_byte_p | 1 << inputNum % BITS_PER_BYTE)) {
		return true;
	}
	else {
		return false;
	}
}

int main1() {
	//�����ܴ洢��������ַ��䶯̬�ڴ�(��0-MAX)
	positive_int32 max_bit = MAX_NUMBER;//(int 4�ֽ�*8=32λ)2��32�η�>40��,��λͼ�㷨��ÿһ������1���ֽ�1����ռ�洢,0-0,n-nλ
	positive_int31 max_byte = max_bit / BITS_PER_BYTE + 1;//(int 4�ֽ�*8=32λ,����ռ1λ)2��31�η�>(40��/8+1=5��+1):7/8+1=1
	char* data_byte_p = (char*)malloc(max_byte);//dataByteP = &init_num=&0;�ڴ��С��byte��
	memset(data_byte_p, 0, max_byte);//�ǵ�����!!

	//����������������ڴ�(��������ڴ���׵�ַdata_byte_p�Թ�����)
	printf("�������ڼ�����...\n");
	load(data_byte_p);

	//���Դ���
	//����
	printf("������Ҫ���Ե�����:");
	positive_int32 inputNum = -1;
	scanf_s("%ud", &inputNum, sizeof(positive_int32));//unsigned int��int�洢��λ��һ����(32)
	//���
	if (exist(inputNum, data_byte_p)) {
		printf("����!\n");
	}
	else {
		printf("������!\n");
	}

	return 0;
}
//ռ���ڴ��,���غ�ʱ25s,�����Լ���!