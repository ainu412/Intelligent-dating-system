#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

void writeTextFile() {
	ofstream outFile;//ifstream也可,因后面<<是输入
	outFile.open("练习.txt");//默认重写,只有app可以尾附
	if (1 != outFile.is_open()) {
		cerr << "文件打开失败!" << endl;
		exit(1);
	}

	while (1) {
		cout << "请输入姓名[Ctrl+Z结束]:";
		string name;
		cin >> name;//用cin因为是由控制台输入的,通过控制台中转,输出至txt文件

		//=cin.fail()可能有多种原因,不是正常结束
		if (cin.eof()) {
			break;
		}
		cout << "请输入年龄:";
		int age;
		cin >> age;

		stringstream ret;
		ret << "姓名:" << name << " 年龄:" << age << "." << endl;//注意写的时候字符串末尾改为换行符方便整行读取
		outFile << ret.str();
	}
}

void readTextFile() {
	ifstream inFile;
	inFile.open("练习.txt");
	if (1 != inFile.is_open()) {
		cerr << "文件打开失败!" << endl;
		exit(1);
	}

	while (1) {
		string line;
		getline(inFile, line);
		if (inFile.eof()) {
			break;
		}
		char name[32];//name = (char*)name;不存在string到char*的合适函数,故只能定义name为char
		int age;
		sscanf_s(line.c_str(), "姓名:%s 年龄:%d.", name, sizeof(name), &age);
		//sscanf_s(line.c_str(), "姓名:%s,年龄:%d", name, sizeof(name), &age);×-空格与换行符标志字符串结束,故整行读取字符串时注意末尾要是空格或换行符
		stringstream ret;
		ret << "姓名:" << name << " 年龄:" << age << endl;
		cout << ret.str();
	}

	inFile.close();
}
void writeBinaryFile() {
	ofstream outBinaryFile;
	//ActionScript Byte Code File 文件是最常用的文件类型
	outBinaryFile.open("二进制文件.abc", ios::binary);//或.dat
	if (1 != outBinaryFile.is_open()) {
		cerr << "文件打开失败!" << endl;
		exit(1);
	}

	while (1) {
		string name;
		cout << "请输入姓名[Ctrl+Z退出]:";
		cin >> name;
		if (cin.eof()) {
			break;
		}
		outBinaryFile << name << '\t';
		cout << "请输入年龄:";
		int age;
		cin >> age;
		//outBinaryFile << age << endl;自动转为文本方式
		outBinaryFile.write((char*)(&age), sizeof(int));//以二进制写入
	}

	outBinaryFile.close();
}

void readBinaryFile() {
	ifstream inBinaryFile;
	inBinaryFile.open("二进制文件.abc", ios::binary);
	if (1 != inBinaryFile.is_open()) {
		cerr << "文件打开失败!" << endl;
		exit(1);
	}

	while (1) {
		/*if (inBinaryFile.eof()) {//会检测紧邻的上一次是否失败,即上一次读取age:文末上一次age成功不会break,读取name失败后读取tmp失败再读取age失败,打印出来制表符和旧的age
			break;
		}*/
		string name;//按字符长度动态存储
		inBinaryFile >> name;
		if (inBinaryFile.eof()) {//会读取文末的回车符为name,然后因为没读到新的年龄,就打印旧的年龄
			//break;
		}
		char tmp;
		//inBinaryFile >> tmp;//文本读取可跳回车符,二进制读取不能跳=>吃掉的回车符记得也要以二进制方式吃,因文本方式会跳
		inBinaryFile.read(&tmp, sizeof(tmp));
		int age;
		//inBinaryFile >> age;按文本不能读取二进制数字
		inBinaryFile.read((char*)(&age), sizeof(age));//强制类型转换的类型记得带括号
		cout << name << '\t' << age << endl;
	}

	inBinaryFile.close();
}
int main() {
	writeTextFile();
	readTextFile();

	//不能同时运行,我也不知道为啥??
	//writeBinaryFile();
	//readBinaryFile();
	
	//test();
	return 0;
}