#pragma once
#include <iostream>
#include <sstream>
using namespace std;
class Service;

class Computer {
public:
	Computer(string cpu = "") {
		this->cpu = cpu;
	}


	string description();

private:
	string cpu;

	friend void upgrade(Computer* computer);//��Ԫ��������public��private,��Ϊ����д���ⲿ�����Ե���
	
	//Ҫ�������Զ��Լ����иı��������ĳ�Ա����
	//void Service::up(Computer* computer, string version);//�������������������д��ǰ��,����֪����Ҫ���������������

	friend Service;
};
//�ܽ�:����:service����ʵ����Ҫ����header�Ե�֪�ڲ���Ա,declare class����û�޸��ڲ���Ա;computer declare��Ҫ����header����friend�ĺ���;main��ֻдcomputer������Ϊ������
//�ⲿ����:		main�а���friend��header(���ûɶ�ر�,Ҫ�����϶�Ҫ������)