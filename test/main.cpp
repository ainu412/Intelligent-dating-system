#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void writeFile() {
	ofstream outFile;//ifstreamҲ��,�����<<������
	outFile.open("��ϰ.txt");//Ĭ����д,ֻ��app����β��

	while (1) {
		cout << "����������[Ctrl+Z����]:";
		string name;
		cin >> name;//��cin��Ϊ���ɿ���̨�����,ͨ������̨��ת,�����txt�ļ�

		//=cin.eof()
		if (cin.fail()) {
			break;
		}
		cout << "����������:";
		int age;
		cin >> age;

		stringstream ret;
		ret << "����:" << name << ",����:" << age << endl;
		outFile << ret.str();
	}
}

void readTextFile() {
	ifstream inFile;
	inFile.open("��ϰ.txt");

	while (1) {
		string name;
		inFile >> name;
		if (inFile.eof()) {//=inFile.eof()
			break;
		}
		cout << name << "\t";

		int age;
		inFile >> age;
		cout << age << endl;
	}

	inFile.close();
}
void writeBinaryFile() {
	ofstream outBinaryFile;
	//ActionScript Byte Code File �ļ�����õ��ļ�����
	outBinaryFile.open("�������ļ�.abc", ios::binary);//��.dat

	while (1) {
		string name;
		cout << "����������[Ctrl+Z�˳�]:";
		cin >> name;
		if (cin.fail()) {
			break;
		}
		outBinaryFile << name << '\t';
		cout << "����������:";
		int age;
		cin >> age;
		//outBinaryFile << age << endl;�Զ�תΪ�ı���ʽ
		outBinaryFile.write((char*)(&age), sizeof(int));//�Զ�����д��
	}

	outBinaryFile.close();
}

void readBinaryFile() {
	ifstream inBinaryFile;
	inBinaryFile.open("�������ļ�.abc", ios::binary);
	while (1) {
		if (inBinaryFile.fail()) {//������ڵ���һ���Ƿ�ʧ��,����һ�ζ�ȡage:��ĩ��һ��age�ɹ�����break,��ȡnameʧ�ܺ��ȡtmpʧ���ٶ�ȡageʧ��,��ӡ�����Ʊ���;ɵ�age
			break;
		}
		string name;//���ַ����ȶ�̬�洢
		inBinaryFile >> name;
		//if (inBinaryFile.fail()) {//���ȡ��ĩ�Ļس���Ϊname,Ȼ����Ϊû�����µ�����,�ʹ�ӡ�ɵ�����
			//break;
		//}
		char tmp;
		//inBinaryFile >> tmp;//�ı���ȡ�����س���,�����ƶ�ȡ������=>�Ե��Ļس����ǵ�ҲҪ�Զ����Ʒ�ʽ��,���ı���ʽ����
		inBinaryFile.read(&tmp, sizeof(tmp));
		int age;
		//inBinaryFile >> age;���ı����ܶ�ȡ����������
		inBinaryFile.read((char*)(&age), sizeof(age));//ǿ������ת�������ͼǵô�����
		cout << name << '\t' << age << endl;
	}
	inBinaryFile.close();
}
int main() {

	writeFile();

	return 0;
}