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

	void load(bool input) {
		loadBoys(input);
		loadGirls(input);
	}
	void print() const;//��ӡboys��girls��������Ů��Ϣ
	void allMatch() const;
	void inputMatch() const;
	void bestMatch() const;
private:
	vector<Boy> boys;//vectorÿ����֮ǰ��Ҫ��ʼ��Ϊ0��?
	vector<Girl> girls;
	vector<Boy> newBoys;
	vector<Girl> newGirls;

	void loadBoys(bool input);//���ļ��м�����vector
	void loadGirls(bool input);

	void saveBoys(vector<Boy> boys);//��vector�д����ļ�
	void saveGirls(vector<Girl> girls);

	void automatchBoy(vector<Boy> boys, vector<Girl> girls) const;
	void automatchGirl(vector<Boy> boys, vector<Girl> girls) const;

	void bestMatchBoy(vector<Boy> boys, vector<Girl> girls) const;
	void bestMatchGirl(vector<Boy> boys, vector<Girl> girls) const;

};



