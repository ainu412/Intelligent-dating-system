#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//��ȡ�ļ������50���ַ�
void Seekg(string filename) {
	ifstream inFile;
	inFile.open(filename);
	if (!inFile.is_open())exit(1);

	inFile.seekg(-50, inFile.end);
	while (!inFile.eof()) {
		string line;
		getline(inFile, line);
		cout << line << endl;
	}

	inFile.close();
}

//��ȡ�ļ���ռ�ռ��С
void Tellg(string filename) {
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open()) exit(1);

	infile.seekg(0, infile.end);
	int len = infile.tellg();
	cout << len << endl;

	infile.close();
}

//�������ļ�д�룺��123456789��(1���ڵ�0���ַ�λ��)
//Ȼ�����ڵ�4���ַ�λ�ø���д�롰ABC��
void Seekp() {
	ofstream outfile;
	outfile.open("��.txt");
	if (!outfile.is_open()) exit(1);

	outfile << "123456789";
	outfile.seekp(4, outfile.beg);
	outfile << "ABC";

	outfile.close();
}

int main() {
	Seekg("main.cpp");
	Tellg("main.cpp");
	Seekp();
	return 0;
}
