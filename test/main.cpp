#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//读取文件的最后50个字符
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

//读取文件所占空间大小
void Tellg(string filename) {
	ifstream infile;
	infile.open(filename);
	if (!infile.is_open()) exit(1);

	infile.seekg(0, infile.end);
	int len = infile.tellg();
	cout << len << endl;

	infile.close();
}

//先向新文件写入：“123456789”(1处于第0个字符位置)
//然后再在第4个字符位置覆盖写入“ABC”
void Seekp() {
	ofstream outfile;
	outfile.open("新.txt");
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
