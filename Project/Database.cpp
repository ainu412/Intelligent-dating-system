#include <fstream>
#include <string>
#include "Database.h"
#define BOY_FILE "boys.txt"
#define GIRL_FILE "girls.txt"
#define BOY_INPUT_INFO 3	//男士输入数据数目(姓名,年龄,月薪)
#define GIRL_INPUT_INFO 3	//女士输入数据数目(姓名,年龄,颜值)
string line(100, '-');

Database::Database()
{
}
void Database::allMatch() const {
	cout << line << endl;
	cout << "全部单身男女自动配对结果:" << endl;
	automatchBoy(boys, allGirls);
	cout << line << endl;
	automatchGirl(boys, allGirls);
	cout << line << endl;
}
void Database::inputMatch() const {
	cout << line << endl;
	cout << "输入单身男自动配对结果:" << endl;
	automatchBoy(newBoys, allGirls);
	cout << line << endl;
	cout << "输入单身女自动配对结果:" << endl;
	automatchGirl(boys, newGirls);
	cout << line << endl;
}
void Database::allBestMatch() const
{
	cout << line << endl;
	cout << "全部单身男女最佳配对结果:" << endl;
	bestMatchBoy(boys, allGirls);
	cout << line << endl;
	bestMatchGirl(boys, allGirls);
	cout << line << endl;
}

void Database::inputBestMatch() const
{
	cout << line << endl;
	if (newBoys.size())
	{
		cout << "输入单身男最佳配对结果:" << endl;
		bestMatchBoy(newBoys, allGirls);
		cout << line << endl;
	}

	if (newGirls.size())
	{
		cout << "输入单身女最佳配对结果:" << endl;
		bestMatchGirl(boys, newGirls);
		cout << line << endl;
	}	
}

void Database::bestMatchBoy(const vector<Boy>& boys, const vector<Girl>& allGirls) const {
	for (unsigned int b = 0; b < boys.size(); b++) {
		cout << boys[b] << " 的最佳配对女士为:" << endl;
		const Girl* bestGirl = NULL;
		for (unsigned int g = 0; g < allGirls.size(); g++) {
			if (boys[b].satisfied(allGirls[g]) == true &&
				allGirls[g].satisfied(boys[b]) == true) {//注意调用的是否是函数以及函数是否含参以及含参顺序
				//cout << boys[b].getName() << "<-->" << allGirls[g].getName() << endl;如果只打印姓名,可能有重名,无法确定实际是哪位
				//因为database与Boy和Girl类不存在继承关系,所以只能通过对象调用public方法
				if (!bestGirl) {
					bestGirl = &allGirls[g];
				}
				else if (allGirls[g] > *bestGirl) {
					bestGirl = &allGirls[g];
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
void Database::bestMatchGirl(const vector<Boy>& boys, const vector<Girl>& allGirls) const {
	for (unsigned int g = 0; g < allGirls.size(); g++) {
		cout << allGirls[g] << " 的最佳配对男士为:" << endl;
		const Boy* bestBoy = NULL;
		for (unsigned int b = 0; b < boys.size(); b++) {
			if (boys[b].satisfied(allGirls[g]) == true &&
				allGirls[g].satisfied(boys[b]) == true) {//注意调用的是否是函数以及函数是否含参以及含参顺序
				//cout << boys[b].getName() << "<-->" << allGirls[g].getName() << endl;如果只打印姓名,可能有重名,无法确定实际是哪位
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

void Database::automatchBoy(const vector<Boy>& boys, const vector<Girl>& allGirls)const
{
	//遍历两两配对
	for (unsigned int b = 0; b < boys.size(); b++) {
		cout << boys[b] << " 的配对女士有:" << endl;
		for (unsigned int g = 0; g < allGirls.size(); g++) {
			if (boys[b].satisfied(allGirls[g]) 
				&& allGirls[g].satisfied(boys[b]) ) {//注意调用的是否是函数以及函数是否含参以及含参顺序
				//cout << boys[b].getName() << "<-->" << allGirls[g].getName() << endl;如果只打印姓名,可能有重名,无法确定实际是哪位
				//因为database与Boy和Girl类不存在继承关系,所以只能通过对象调用public方法
				cout << allGirls[g] ;
			}
		}
		cout << endl;//一位男士的所有配对结束后空一行
	}
}
void Database::automatchGirl(const vector<Boy>& boys, const vector<Girl>& allGirls)const
{
	//遍历两两配对
	for (unsigned int g = 0; g < allGirls.size(); g++) {
		cout << allGirls[g] <<" 的配对男士有:"<< endl;
		for (unsigned int b = 0; b < boys.size(); b++) {
			if (boys[b].satisfied(allGirls[g]) 
				&& allGirls[g].satisfied(boys[b]) ) {//注意调用的是否是函数以及函数是否含参以及含参顺序
				//cout << boys[b].getName() << "<-->" << allGirls[g].getName() << endl;如果只打印姓名,可能有重名,无法确定实际是哪位
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
	for (unsigned int i = 0; i < allGirls.size(); i++) {
		cout << allGirls[i];
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

	// 还没有此文件,需要用户输入基础信息
	if ( !girlfile.is_open() ) {
		Girl::inputGirls(this->newGirls);
		//将输入的基础信息以description中的格式保存至文件尾部
		saveGirls(newGirls);
		girlfile.close();
		return;
	}
	// 用户希望输入新信息
	if (input) {
		Girl::inputGirls(this->newGirls);
		//将输入的基础信息以description中的格式保存至文件尾部
		saveGirls(newGirls);
	}

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
		allGirls.push_back(Girl(name, age, faceScore));//string存入时最后记得加\0结束符,因为读取的时候要用char型读取,可以不加,因为格式里面专门加了空格隔开

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

void Database::saveGirls(const vector<Girl>& allGirls)
{
	ofstream girlfile;
	girlfile.open(GIRL_FILE, ios::app);
	if (!girlfile.is_open()) {
		cerr << "写入:女士文件打开失败!" << endl;
		exit(-1);
	}

	for (unsigned int i = 0; i < allGirls.size(); i++) {
		girlfile << allGirls[i];
	}

	girlfile.close();
}
