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

void Database::automatch()const
{
	string line(100, '-');
	cout << "�Զ���Խ��:" << endl;
	//�����������
	for (unsigned int b = 0; b < boys.size(); b++) {
		for (unsigned int g = 0; g < girls.size(); g++) {
			if (boys[b].satisfied(girls[g]) == true && 
				girls[g].satisfied(boys[b]) == true) {//ע����õ��Ƿ��Ǻ����Լ������Ƿ񺬲��Լ�����˳��
				//cout << boys[b].getName() << "<-->" << girls[g].getName() << endl;���ֻ��ӡ����,����������,�޷�ȷ��ʵ������λ
				//��Ϊdatabase��Boy��Girl�಻���ڼ̳й�ϵ,����ֻ��ͨ���������public����
				cout << boys[b].description() << "<==>" 
					<< girls[g].description() << endl;
			}
		}
		cout << endl;//һλ��ʿ��������Խ������һ��
	}
	cout << line << endl;
}

void Database::print()const
{
	string line(100, '-');//�ǵ��ڳ�ʼ��ʱ����д

	cout << "��ʿ��Ϣ:" << endl;
	for (unsigned int i = 0; i < boys.size(); i++) {
		cout << boys[i].description() << endl;
	}

	cout << "Ůʿ��Ϣ:" << endl;
	for (unsigned int i = 0; i < girls.size(); i++) {
		cout << girls[i].description() << endl;
	}

	cout << line << endl;
}

void Database::loadBoys()
{
	//�򿪶��ļ�
	ifstream boyfile;
	boyfile.open(BOY_FILE);
	if (!boyfile.is_open()) {
		//��û�д��ļ������ļ�,��Ҫ�û�����,��Ϊ������Ϣ,����vector->vector.vector������,����Ҫ�ٴ��ļ��ж�ȡ
		Boy::inputBoys(this->boys);

		//��vector�еĻ�����Ϣ��description�еĸ�ʽд���½����ļ�,����������
		saveBoys();
		boyfile.close();
		return;
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

void Database::loadGirls()
{

	ifstream girlfile;
	girlfile.open(GIRL_FILE);
	if (!girlfile.is_open()) {
		//��û�д��ļ�,��Ҫ�û����������Ϣ
		Girl::inputGirls(this->girls);
		//������Ļ�����Ϣ��description�еĸ�ʽ�������ļ�
		saveGirls();
		girlfile.close();
		return;
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
		girls.push_back(Girl(name, age, faceScore));//string����ʱ���ǵü�\0������,��Ϊ��ȡ��ʱ��Ҫ��char�Ͷ�ȡ,���Բ���,��Ϊ��ʽ����ר�ż��˿ո����

	}

	girlfile.close();
}

void Database::saveBoys()
{
	ofstream boyfile;
	boyfile.open(BOY_FILE, ios::app);//β������
	if (!boyfile.is_open()) {
		cerr << "д��:��ʿ�ļ���ʧ��!" << endl;
		exit(1);//exit����break����Ŀ����
	}

	for (unsigned int i = 0; i < boys.size(); i++) {
		boyfile << boys[i].description() << endl;
	}

	boyfile.close();
}

void Database::saveGirls()
{
	ofstream girlfile;
	girlfile.open(GIRL_FILE, ios::app);
	if (!girlfile.is_open()) {
		cerr << "д��:Ůʿ�ļ���ʧ��!" << endl;
		exit(1);
	}

	for (unsigned int i = 0; i < girls.size(); i++) {
		girlfile << girls[i].description() << endl;
	}

	girlfile.close();
}
