#include <fstream>
#include <string>
#include "Database.h"
#define BOY_FILE "boys.txt"
#define GIRL_FILE "girls.txt"
#define BOY_INPUT_INFO 3	//��ʿ����������Ŀ(����,����,��н)
#define GIRL_INPUT_INFO 3	//Ůʿ����������Ŀ(����,����,��ֵ)
string line(100, '-');

Database::Database()
{
}
void Database::allMatch() const {
	cout << line << endl;
	cout << "ȫ��������Ů�Զ���Խ��:" << endl;
	automatchBoy(boys, allGirls);
	cout << line << endl;
	automatchGirl(boys, allGirls);
	cout << line << endl;
}
void Database::inputMatch() const {
	cout << line << endl;
	cout << "���뵥�����Զ���Խ��:" << endl;
	automatchBoy(newBoys, allGirls);
	cout << line << endl;
	cout << "���뵥��Ů�Զ���Խ��:" << endl;
	automatchGirl(boys, newGirls);
	cout << line << endl;
}
void Database::allBestMatch() const
{
	cout << line << endl;
	cout << "ȫ��������Ů�����Խ��:" << endl;
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
		cout << "���뵥���������Խ��:" << endl;
		bestMatchBoy(newBoys, allGirls);
		cout << line << endl;
	}

	if (newGirls.size())
	{
		cout << "���뵥��Ů�����Խ��:" << endl;
		bestMatchGirl(boys, newGirls);
		cout << line << endl;
	}	
}

void Database::bestMatchBoy(const vector<Boy>& boys, const vector<Girl>& allGirls) const {
	for (unsigned int b = 0; b < boys.size(); b++) {
		cout << boys[b] << " ��������ŮʿΪ:" << endl;
		const Girl* bestGirl = NULL;
		for (unsigned int g = 0; g < allGirls.size(); g++) {
			if (boys[b].satisfied(allGirls[g]) == true &&
				allGirls[g].satisfied(boys[b]) == true) {//ע����õ��Ƿ��Ǻ����Լ������Ƿ񺬲��Լ�����˳��
				//cout << boys[b].getName() << "<-->" << allGirls[g].getName() << endl;���ֻ��ӡ����,����������,�޷�ȷ��ʵ������λ
				//��Ϊdatabase��Boy��Girl�಻���ڼ̳й�ϵ,����ֻ��ͨ���������public����
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
			cout << "���ʧ��!" << endl;
		}
		cout << endl;//һλ��ʿ��������Խ������һ��
	}
}
void Database::bestMatchGirl(const vector<Boy>& boys, const vector<Girl>& allGirls) const {
	for (unsigned int g = 0; g < allGirls.size(); g++) {
		cout << allGirls[g] << " ����������ʿΪ:" << endl;
		const Boy* bestBoy = NULL;
		for (unsigned int b = 0; b < boys.size(); b++) {
			if (boys[b].satisfied(allGirls[g]) == true &&
				allGirls[g].satisfied(boys[b]) == true) {//ע����õ��Ƿ��Ǻ����Լ������Ƿ񺬲��Լ�����˳��
				//cout << boys[b].getName() << "<-->" << allGirls[g].getName() << endl;���ֻ��ӡ����,����������,�޷�ȷ��ʵ������λ
				//��Ϊdatabase��Boy��Girl�಻���ڼ̳й�ϵ,����ֻ��ͨ���������public����
				if (!bestBoy) {
					bestBoy = &boys[b];
				}
				else if (boys[b] > * bestBoy) {//TO DO <���������
					bestBoy = &boys[b];
				}
			}
		}
		if (bestBoy) {
			cout << *bestBoy;
		}
		else {
			cout << "���ʧ��!" << endl;
		}
		cout << endl;//һλŮʿ��������Խ������һ��
	}
}

void Database::automatchBoy(const vector<Boy>& boys, const vector<Girl>& allGirls)const
{
	//�����������
	for (unsigned int b = 0; b < boys.size(); b++) {
		cout << boys[b] << " �����Ůʿ��:" << endl;
		for (unsigned int g = 0; g < allGirls.size(); g++) {
			if (boys[b].satisfied(allGirls[g]) 
				&& allGirls[g].satisfied(boys[b]) ) {//ע����õ��Ƿ��Ǻ����Լ������Ƿ񺬲��Լ�����˳��
				//cout << boys[b].getName() << "<-->" << allGirls[g].getName() << endl;���ֻ��ӡ����,����������,�޷�ȷ��ʵ������λ
				//��Ϊdatabase��Boy��Girl�಻���ڼ̳й�ϵ,����ֻ��ͨ���������public����
				cout << allGirls[g] ;
			}
		}
		cout << endl;//һλ��ʿ��������Խ������һ��
	}
}
void Database::automatchGirl(const vector<Boy>& boys, const vector<Girl>& allGirls)const
{
	//�����������
	for (unsigned int g = 0; g < allGirls.size(); g++) {
		cout << allGirls[g] <<" �������ʿ��:"<< endl;
		for (unsigned int b = 0; b < boys.size(); b++) {
			if (boys[b].satisfied(allGirls[g]) 
				&& allGirls[g].satisfied(boys[b]) ) {//ע����õ��Ƿ��Ǻ����Լ������Ƿ񺬲��Լ�����˳��
				//cout << boys[b].getName() << "<-->" << allGirls[g].getName() << endl;���ֻ��ӡ����,����������,�޷�ȷ��ʵ������λ
				//��Ϊdatabase��Boy��Girl�಻���ڼ̳й�ϵ,����ֻ��ͨ���������public����
				cout << boys[b];
			}
		}
		cout << endl;//һλ��Ůʿ��������Խ������һ��
	}
}
void Database::print()const
{
	string line(100, '-');//�ǵ��ڳ�ʼ��ʱ����д

	cout << "��ʿ��Ϣ:" << endl;
	for (unsigned int i = 0; i < boys.size(); i++) {
		cout << boys[i];
	}

	cout << "Ůʿ��Ϣ:" << endl;
	for (unsigned int i = 0; i < allGirls.size(); i++) {
		cout << allGirls[i];
	}

	cout << line << endl;
}

void Database::loadBoys(bool input)
{
	//�򿪶��ļ�
	ifstream boyfile;
	boyfile.open(BOY_FILE);
	if (!boyfile.is_open()) {
		//��û�д��ļ������ļ�,��Ҫ�û�����,��Ϊ������Ϣ,����vector->vector.vector������,����Ҫ�ٴ��ļ��ж�ȡ
		Boy::inputBoys(this->newBoys);

		//��vector�еĻ�����Ϣ��description�еĸ�ʽд���½����ļ�,����������
		saveBoys(newBoys);
		boyfile.close();
		return;
	}
	if (input) {
		Boy::inputBoys(this->newBoys);
		saveBoys(newBoys);
	}
	while (1) {

		//�����ļ���Ϣ����??ΪɶҪ������??�Ѿ�����˵İ�,,��Ϊ����ʾ������,Ҫ��ʾ��������ֱ�Ӱ������vector��ʾ��?����
		//��Ϊvector���缴ʧ,��д���ļ���ת
		//sscanf��ȡ�ַ������Զ������س���
		//����д�ĸ�ʽ��ȡ�ļ�
		/*ret << "�� ����:" << setw(9) << left << name
			<< " ����:" << setw(4) << age
			<< "��н:" << salary << endl;*/
		string line;
		getline(boyfile, line);
		if (boyfile.eof()) {
			break;
		}

		char name[32]="";
		int age, salary;
		int ret = sscanf_s(line.c_str(), "�� ����:%s ����:%d ��н:%d", name, sizeof(name), &age, &salary);
		if (ret < BOY_INPUT_INFO) {
			cerr << "��ʿ��Ϣд������!" << endl;
			exit(1);//����Ŀ����:break/exit
		}

		//��������vector�Թ��������
		boys.push_back(Boy(name, age, salary));//string����ʱ���ǵü�\0������,��Ϊ��ȡ��ʱ��Ҫ��char�Ͷ�ȡ,���Բ���,��Ϊ��ʽ����ר�ż��˿ո����

	}
	boyfile.close();

}
//inputGirls:����̨->vector
//saveGirls:vector->�ļ�
void Database::loadGirls(bool input)
{
	ifstream girlfile;
	girlfile.open(GIRL_FILE);

	// ��û�д��ļ�,��Ҫ�û����������Ϣ
	if ( !girlfile.is_open() ) {
		Girl::inputGirls(this->newGirls);
		//������Ļ�����Ϣ��description�еĸ�ʽ�������ļ�β��
		saveGirls(newGirls);
		girlfile.close();
		return;
	}
	// �û�ϣ����������Ϣ
	if (input) {
		Girl::inputGirls(this->newGirls);
		//������Ļ�����Ϣ��description�еĸ�ʽ�������ļ�β��
		saveGirls(newGirls);
	}

	while (1) {

		//�����ļ���Ϣ����??ΪɶҪ������??�Ѿ�����˵İ�,,��Ϊ����ʾ������,Ҫ��ʾ��������ֱ�Ӱ������vector��ʾ��?����
		//��Ϊvector���缴ʧ,��д���ļ���ת
		//sscanf��ȡ�ַ������Զ������س���
		//����д�ĸ�ʽ��ȡ�ļ�
		/*	ret << "Ů ����:" << setw(9) << left << name
				<< " ����:" << setw(4) << age
				<< "��ֵ:" << faceScore << endl;*/
		string line;
		getline(girlfile, line);
		if (girlfile.eof()) {
			break;
		}

		char name[32]="";
		int age, faceScore;
		int ret = sscanf_s(line.c_str(), "Ů ����:%s ����:%d ��ֵ:%d", name, sizeof(name), &age, &faceScore);
		if (ret < GIRL_INPUT_INFO) {
			cerr << "Ůʿ��Ϣд������!" << endl;
			exit(1);//����Ŀ����:break/exit
		}

		//��������vector�Թ��������
		allGirls.push_back(Girl(name, age, faceScore));//string����ʱ���ǵü�\0������,��Ϊ��ȡ��ʱ��Ҫ��char�Ͷ�ȡ,���Բ���,��Ϊ��ʽ����ר�ż��˿ո����

	}
	girlfile.close();

}

void Database::saveBoys(const vector<Boy>& boys)
{
	ofstream boyfile;
	boyfile.open(BOY_FILE, ios::app);//β������
	if (!boyfile.is_open()) {
		cerr << "д��:��ʿ�ļ���ʧ��!" << endl;
		exit(1);//exit����break����Ŀ����
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
		cerr << "д��:Ůʿ�ļ���ʧ��!" << endl;
		exit(-1);
	}

	for (unsigned int i = 0; i < allGirls.size(); i++) {
		girlfile << allGirls[i];
	}

	girlfile.close();
}
