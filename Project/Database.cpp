#include <fstream>
#include <string>
#include "Database.h"
#define BOY_FILE "boys.txt"
#define GIRL_FILE "girls.txt"
#define BOY_INPUT_INFO 3	//男士输入数据数目(姓名,年龄,月薪)
#define GIRL_INPUT_INFO 3	//女士输入数据数目(姓名,年龄,颜值)

Database::Database()
{
}
void Database::allMatch() const {
	cout << "全部单身男女自动配对结果:" << endl;
	automatchBoy(boys, girls);
	automatchGirl(boys, girls);
}
void Database::inputMatch() const {
	string line(100, '-');
	cout << "输入单身男自动配对结果:" << endl;
	automatchBoy(newBoys, girls);
	cout << line << endl;
	cout << "输入单身女自动配对结果:" << endl;
	automatchGirl(boys, newGirls);
	cout << line << endl;
}
void Database::allBestMatch() const
{
	cout << "全部单身男女最佳配对结果:" << endl;
	bestMatchBoy(boys, girls);
	bestMatchGirl(boys, girls);
}

void Database::inputBestMatch() const
{
	cout << "输入单身男最佳配对结果:" << endl;
	bestMatchBoy(newBoys, girls);
	cout << "输入单身女最佳配对结果:" << endl;
	bestMatchGirl(boys, newGirls);
}

void Database::bestMatchBoy(const vector<Boy>& boys, const vector<Girl>& girls) const {
	for (unsigned int b = 0; b < boys.size(); b++) {
		cout << boys[b] << " 的最佳配对女士为:" << endl;
		const Girl* bestGirl = NULL;
		for (unsigned int g = 0; g < girls.size(); g++) {
			if (boys[b].satisfied(girls[g]) == true &&
				girls[g].satisfied(boys[b]) == true) {//注意调用的是否是函数以及函数是否含参以及含参顺序
				//cout << boys[b].getName() << "<-->" << girls[g].getName() << endl;如果只打印姓名,可能有重名,无法确定实际是哪位
				//因为database与Boy和Girl类不存在继承关系,所以只能通过对象调用public方法
				if (!bestGirl) {
					bestGirl = &girls[g];
				}
				else if (girls[g] > *bestGirl) {//TO DO <运算符重载
					bestGirl = &girls[g];
				}
			}
		}
		if (bestGirl) {
			cout << *bestGirl;
		}
		else {
			cout << "配对失败!" << endl;
		}
		cout << endl;//一位男士的所有配对结束后空一行
	}
}
void Database::bestMatchGirl(const vector<Boy>& boys, const vector<Girl>& girls) const {
	for (unsigned int g = 0; g < girls.size(); g++) {
		cout << girls[g] << " 的最佳配对男士为:" << endl;
		const Boy* bestBoy = NULL;
		for (unsigned int b = 0; b < boys.size(); b++) {
			if (boys[b].satisfied(girls[g]) == true &&
				girls[g].satisfied(boys[b]) == true) {//注意调用的是否是函数以及函数是否含参以及含参顺序
				//cout << boys[b].getName() << "<-->" << girls[g].getName() << endl;如果只打印姓名,可能有重名,无法确定实际是哪位
				//因为database与Boy和Girl类不存在继承关系,所以只能通过对象调用public方法
				if (!bestBoy) {
					bestBoy = &boys[b];
				}
				else if (boys[b] > * bestBoy) {//TO DO <运算符重载
					bestBoy = &boys[b];
				}
			}
		}
		if (bestBoy) {
			cout << *bestBoy;
		}
		else {
			cout << "配对失败!" << endl;
		}
		cout << endl;//一位女士的所有配对结束后空一行
	}
}

void Database::automatchBoy(const vector<Boy>& boys, const vector<Girl>& girls)const
{
	//遍历两两配对
	for (unsigned int b = 0; b < boys.size(); b++) {
		cout << boys[b] << " 的配对女士有:" << endl;
		for (unsigned int g = 0; g < girls.size(); g++) {
			if (boys[b].satisfied(girls[g]) == true && 
				girls[g].satisfied(boys[b]) == true) {//注意调用的是否是函数以及函数是否含参以及含参顺序
				//cout << boys[b].getName() << "<-->" << girls[g].getName() << endl;如果只打印姓名,可能有重名,无法确定实际是哪位
				//因为database与Boy和Girl类不存在继承关系,所以只能通过对象调用public方法
				cout << girls[g] ;
			}
		}
		cout << endl;//一位男士的所有配对结束后空一行
	}
}
void Database::automatchGirl(const vector<Boy>& boys, const vector<Girl>& girls)const
{
	//遍历两两配对
	for (unsigned int g = 0; g < girls.size(); g++) {
		cout << girls[g] <<" 的配对男士有:"<< endl;
		for (unsigned int b = 0; b < boys.size(); b++) {
			if (boys[b].satisfied(girls[g]) == true &&
				girls[g].satisfied(boys[b]) == true) {//注意调用的是否是函数以及函数是否含参以及含参顺序
				//cout << boys[b].getName() << "<-->" << girls[g].getName() << endl;如果只打印姓名,可能有重名,无法确定实际是哪位
				//因为database与Boy和Girl类不存在继承关系,所以只能通过对象调用public方法
				cout << boys[b];
			}
		}
		cout << endl;//一位成女士的所有配对结束后空一行
	}
}
void Database::print()const
{
	string line(100, '-');//记得在初始化时这样写

	cout << "男士信息:" << endl;
	for (unsigned int i = 0; i < boys.size(); i++) {
		cout << boys[i];
	}

	cout << "女士信息:" << endl;
	for (unsigned int i = 0; i < girls.size(); i++) {
		cout << girls[i];
	}

	cout << line << endl;
}

void Database::loadBoys(bool input)
{
	//打开读文件
	ifstream boyfile;
	boyfile.open(BOY_FILE);
	if (!boyfile.is_open()) {
		//还没有此文件名的文件,需要用户输入,作为基础信息,存入vector->vector.vector中已有,不需要再从文件中读取
		Boy::inputBoys(this->newBoys);

		//将vector中的基础信息以description中的格式写入新建的文件,并结束加载
		saveBoys(newBoys);
		boyfile.close();
		return;
	}
	if (input) {
		Boy::inputBoys(this->newBoys);
		saveBoys(newBoys);
	}
	while (1) {

		//将读文件信息解析??为啥要解析嘞??已经存好了的啊,,是为了显示出来吗,要显示出来可以直接按存入的vector显示吗?不能
		//因为vector掉电即失,需写入文件中转
		//sscanf读取字符串会自动跳过回车符
		//根据写的格式读取文件
		/*ret << "男 姓名:" << setw(9) << left << name
			<< " 年龄:" << setw(4) << age
			<< "月薪:" << salary << endl;*/
		string line;
		getline(boyfile, line);
		if (boyfile.eof()) {
			break;
		}

		char name[32]="";
		int age, salary;
		int ret = sscanf_s(line.c_str(), "男 姓名:%s 年龄:%d 月薪:%d", name, sizeof(name), &age, &salary);
		if (ret < BOY_INPUT_INFO) {
			cerr << "男士信息写入有误!" << endl;
			exit(1);//视项目需求:break/exit
		}

		//并加载至vector以供后续配对
		boys.push_back(Boy(name, age, salary));//string存入时最后记得加\0结束符,因为读取的时候要用char型读取,可以不加,因为格式里面专门加了空格隔开

	}
	boyfile.close();

}
//inputGirls:控制台->vector
//saveGirls:vector->文件
void Database::loadGirls(bool input)
{

	ifstream girlfile;
	girlfile.open(GIRL_FILE);
	if (!girlfile.is_open()) {
		//还没有此文件,需要用户输入基础信息
		Girl::inputGirls(this->newGirls);
		//将输入的基础信息以description中的格式保存至文件尾部
		saveGirls(newGirls);
		girlfile.close();
		return;
	}
	if (input) {
		//还没有此文件,需要用户输入基础信息
		Girl::inputGirls(this->newGirls);
		//将输入的基础信息以description中的格式保存至文件尾部
		saveGirls(newGirls);
	}
	/*if (input == true) {
		Girl::inputGirls(this->girls);//vector只有新读进来的
		saveGirls();//只在文件尾部追加新读进来的
		girlfile.close();
	}*/

	while (1) {

		//将读文件信息解析??为啥要解析嘞??已经存好了的啊,,是为了显示出来吗,要显示出来可以直接按存入的vector显示吗?不能
		//因为vector掉电即失,需写入文件中转
		//sscanf读取字符串会自动跳过回车符
		//根据写的格式读取文件
		/*	ret << "女 姓名:" << setw(9) << left << name
				<< " 年龄:" << setw(4) << age
				<< "颜值:" << faceScore << endl;*/
		string line;
		getline(girlfile, line);
		if (girlfile.eof()) {
			break;
		}

		char name[32]="";
		int age, faceScore;
		int ret = sscanf_s(line.c_str(), "女 姓名:%s 年龄:%d 颜值:%d", name, sizeof(name), &age, &faceScore);
		if (ret < GIRL_INPUT_INFO) {
			cerr << "女士信息写入有误!" << endl;
			exit(1);//视项目需求:break/exit
		}

		//并加载至vector以供后续配对
		girls.push_back(Girl(name, age, faceScore));//string存入时最后记得加\0结束符,因为读取的时候要用char型读取,可以不加,因为格式里面专门加了空格隔开

	}
	girlfile.close();

}

void Database::saveBoys(const vector<Boy>& boys)
{
	ofstream boyfile;
	boyfile.open(BOY_FILE, ios::app);//尾部附加
	if (!boyfile.is_open()) {
		cerr << "写入:男士文件打开失败!" << endl;
		exit(1);//exit还是break按项目需求
	}

	for (unsigned int i = 0; i < boys.size(); i++) {
		boyfile << boys[i];
	}

	boyfile.close();
}

void Database::saveGirls(const vector<Girl>& girls)
{
	ofstream girlfile;
	girlfile.open(GIRL_FILE, ios::app);
	if (!girlfile.is_open()) {
		cerr << "写入:女士文件打开失败!" << endl;
		exit(1);
	}

	for (unsigned int i = 0; i < girls.size(); i++) {
		girlfile << girls[i];
	}

	girlfile.close();
}
