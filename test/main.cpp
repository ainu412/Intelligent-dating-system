#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void writeTextFile() {
	ofstream outFile;//ifstreamҲ��,�����<<������
	outFile.open("��ϰ.txt");//Ĭ����д,ֻ��app����β��
	if (1 != outFile.is_open()) {
		cerr << "�ļ���ʧ��!" << endl;
		exit(1);
	}

	while (1) {
		cout << "����������[Ctrl+Z����]:";
		string name;
		cin >> name;//��cin��Ϊ���ɿ���̨�����,ͨ������̨��ת,�����txt�ļ�

		//=cin.fail()�����ж���ԭ��,������������
		if (cin.eof()) {
			break;
		}
		cout << "����������:";
		int age;
		cin >> age;

		stringstream ret;
		ret << "����:" << name << " ����:" << age << "." << endl;//ע��д��ʱ���ַ���ĩβ��Ϊ���з��������ж�ȡ
		outFile << ret.str();
	}
}

void readTextFile() {
	ifstream inFile;
	inFile.open("��ϰ.txt");
	if (1 != inFile.is_open()) {
		cerr << "�ļ���ʧ��!" << endl;
		exit(1);
	}

	while (1) {
		string line;
		getline(inFile, line);
		if (inFile.eof()) {
			break;
		}
		char name[32];//name = (char*)name;������string��char*�ĺ��ʺ���,��ֻ�ܶ���nameΪchar
		int age;
		sscanf_s(line.c_str(), "����:%s ����:%d.", name, sizeof(name), &age);
		//sscanf_s(line.c_str(), "����:%s,����:%d", name, sizeof(name), &age);��-�ո��뻻�з���־�ַ�������,�����ж�ȡ�ַ���ʱע��ĩβҪ�ǿո���з�
		stringstream ret;
		ret << "����:" << name << " ����:" << age << endl;
		cout << ret.str();
	}

	inFile.close();
}
void writeBinaryFile() {
	ofstream outBinaryFile;
	//ActionScript Byte Code File �ļ�����õ��ļ�����
	outBinaryFile.open("�������ļ�.abc", ios::binary);//��.dat
	if (1 != outBinaryFile.is_open()) {
		cerr << "�ļ���ʧ��!" << endl;
		exit(1);
	}

	while (1) {
		string name;
		cout << "����������[Ctrl+Z�˳�]:";
		cin >> name;
		if (cin.eof()) {
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
	if (1 != inBinaryFile.is_open()) {
		cerr << "�ļ���ʧ��!" << endl;
		exit(1);
	}

	while (1) {
		/*if (inBinaryFile.eof()) {//������ڵ���һ���Ƿ�ʧ��,����һ�ζ�ȡage:��ĩ��һ��age�ɹ�����break,��ȡnameʧ�ܺ��ȡtmpʧ���ٶ�ȡageʧ��,��ӡ�����Ʊ���;ɵ�age
			break;
		}*/
		string name;//���ַ����ȶ�̬�洢
		inBinaryFile >> name;
		if (inBinaryFile.eof()) {//���ȡ��ĩ�Ļس���Ϊname,Ȼ����Ϊû�����µ�����,�ʹ�ӡ�ɵ�����
			//break;
		}
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
	writeTextFile();
	readTextFile();

	//����ͬʱ����,��Ҳ��֪��Ϊɶ??
	//writeBinaryFile();
	//readBinaryFile();
	
	//test();
	return 0;
}