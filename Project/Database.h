#pragma once
#include "Boy.h"
#include "Girl.h"

/*
����:
�����û���Ϣload()
ʵ���Զ����automatch()
��ӡ�����Ϣprint()
����:
����Ϣ
Ů��Ϣ
*/

class Database
{
public:
	Database();

	void load() {
		loadBoys();
		loadGirls();
	}
	void automatch() const;
	void print() const;//��ӡvector����Ů��Ϣ

private:
	vector<Boy> boys;
	vector<Girl> girls;

	void loadBoys();//���ļ��м�����vector
	void loadGirls();

	void saveBoys();//��vector�д����ļ�
	void saveGirls();
};



