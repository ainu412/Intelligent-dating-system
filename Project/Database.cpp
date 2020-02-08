#include <fstream>
#include <string>
#include "Database.h"
#define BOY_FILE "boys.txt"
#define GIRL_FILE "girls.txt"
#define BOY_INPUT_INFO 3	//��ʿ����������Ŀ(����,����,��н)
#define GIRL_INPUT_INFO 3	//Ůʿ����������Ŀ(����,����,��ֵ)

Database::Database()
{
}
void Database::allMatch() const {
	cout << "ȫ��������Ů�Զ���Խ��:" << endl;
	automatchBoy(boys, girls);
	automatchGirl(boys, girls);
}
void Database::inputMatch() const {
	string line(100, '-');
	cout << "���뵥�����Զ���Խ��:" << endl;
	automatchBoy(newBoys, girls);
	cout << line << endl;
	cout << "���뵥��Ů�Զ���Խ��:" << endl;
	automatchGirl(boys, newGirls);
	cout << line << endl;
}
void Database::allBestMatch() const
{
	cout << "ȫ��������Ů�����Խ��:" << endl;
	bestMatchBoy(boys, girls);
	bestMatchGirl(boys, girls);
}

void Database::inputBestMatch() const
{
	cout << "���뵥���������Խ��:" << endl;
	bestMatchBoy(newBoys, girls);
	cout << "���뵥��Ů�����Խ��:" << endl;
	bestMatchGirl(boys, newGirls);
}

void Database::bestMatchBoy(const vector<Boy>& boys, const vector<Girl>& girls) const {
	for (unsigned int b = 0; b < boys.size(); b++) {
		cout << boys[b] << " ��������ŮʿΪ:" << endl;
		const Girl* bestGirl = NULL;
		for (unsigned int g = 0; g < girls.size(); g++) {
			if (boys[b].satisfied(girls[g]) == true &&
				girls[g].satisfied(boys[b]) == true) {//ע����õ��Ƿ��Ǻ����Լ������Ƿ񺬲��Լ�����˳��
				//cout << boys[b].getName() << "<-->" << girls[g].getName() << endl;���ֻ��ӡ����,����������,�޷�ȷ��ʵ������λ
				//��Ϊdatabase��Boy��Girl�಻���ڼ̳й�ϵ,����ֻ��ͨ���������public����
				if (!bestGirl) {
					bestGirl = &girls[g];
				}
				else if (girls[g] > *bestGirl) {//TO DO <���������
					bestGirl = &girls[g];
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
void Database::bestMatchGirl(const vector<Boy>& boys, const vector<Girl>& girls) const {
	for (unsigned int g = 0; g < girls.size(); g++) {
		cout << girls[g] << " ����������ʿΪ:" << endl;
		const Boy* bestBoy = NULL;
		for (unsigned int b = 0; b < boys.size(); b++) {
			if (boys[b].satisfied(girls[g]) == true &&
				girls[g].satisfied(boys[b]) == true) {//ע����õ��Ƿ��Ǻ����Լ������Ƿ񺬲��Լ�����˳��
				//cout << boys[b].getName() << "<-->" << girls[g].getName() << endl;���ֻ��ӡ����,����������,�޷�ȷ��ʵ������λ
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

void Database::automatchBoy(const vector<Boy>& boys, const vector<Girl>& girls)const
{
	//�����������
	for (unsigned int b = 0; b < boys.size(); b++) {
		cout << boys[b] << " �����Ůʿ��:" << endl;
		for (unsigned int g = 0; g < girls.size(); g++) {
			if (boys[b].satisfied(girls[g]) == true && 
				girls[g].satisfied(boys[b]) == true) {//ע����õ��Ƿ��Ǻ����Լ������Ƿ񺬲��Լ�����˳��
				//cout << boys[b].getName() << "<-->" << girls[g].getName() << endl;���ֻ��ӡ����,����������,�޷�ȷ��ʵ������λ
				//��Ϊdatabase��Boy��Girl�಻���ڼ̳й�ϵ,����ֻ��ͨ���������public����
				cout << girls[g] ;
			}
		}
		cout << endl;//һλ��ʿ��������Խ������һ��
	}
}
void Database::automatchGirl(const vector<Boy>& boys, const vector<Girl>& girls)const
{
	//�����������
	for (unsigned int g = 0; g < girls.size(); g++) {
		cout << girls[g] <<" �������ʿ��:"<< endl;
		for (unsigned int b = 0; b < boys.size(); b++) {
			if (boys[b].satisfied(girls[g]) == true &&
				girls[g].satisfied(boys[b]) == true) {//ע����õ��Ƿ��Ǻ����Լ������Ƿ񺬲��Լ�����˳��
				//cout << boys[b].getName() << "<-->" << girls[g].getName() << endl;���ֻ��ӡ����,����������,�޷�ȷ��ʵ������λ
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
	for (unsigned int i = 0; i < girls.size(); i++) {
		cout << girls[i];
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
	if (!girlfile.is_open()) {
		//��û�д��ļ�,��Ҫ�û����������Ϣ
		Girl::inputGirls(this->newGirls);
		//������Ļ�����Ϣ��description�еĸ�ʽ�������ļ�β��
		saveGirls(newGirls);
		girlfile.close();
		return;
	}
	if (input) {
		//��û�д��ļ�,��Ҫ�û����������Ϣ
		Girl::inputGirls(this->newGirls);
		//������Ļ�����Ϣ��description�еĸ�ʽ�������ļ�β��
		saveGirls(newGirls);
	}
	/*if (input == true) {
		Girl::inputGirls(this->girls);//vectorֻ���¶�������
		saveGirls();//ֻ���ļ�β��׷���¶�������
		girlfile.close();
	}*/

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
		girls.push_back(Girl(name, age, faceScore));//string����ʱ���ǵü�\0������,��Ϊ��ȡ��ʱ��Ҫ��char�Ͷ�ȡ,���Բ���,��Ϊ��ʽ����ר�ż��˿ո����

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

void Database::saveGirls(const vector<Girl>& girls)
{
	ofstream girlfile;
	girlfile.open(GIRL_FILE, ios::app);
	if (!girlfile.is_open()) {
		cerr << "д��:Ůʿ�ļ���ʧ��!" << endl;
		exit(1);
	}

	for (unsigned int i = 0; i < girls.size(); i++) {
		girlfile << girls[i];
	}

	girlfile.close();
}
