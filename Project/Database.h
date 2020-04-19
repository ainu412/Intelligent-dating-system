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

	void load(bool input = false) {
		loadBoys(input);
		loadGirls(input);
	}
	void print() const;//��ӡboys��allGirls��������Ů��Ϣ
	void allMatch() const;
	void inputMatch() const;
	void allBestMatch() const;
	void inputBestMatch() const;
private:
	vector<Boy> boys;//vectorÿ����֮ǰ��Ҫ��ʼ��Ϊ0��?
	vector<Girl>allGirls;
	vector<Boy> newBoys;
	vector<Girl> newGirls;

	void loadBoys(bool input);//���ļ��м�����vector
	void loadGirls(bool input);

	void saveBoys(const vector<Boy>& boys);//��vector�д����ļ�
	void saveGirls(const vector<Girl>&allGirls);

	void automatchBoy(const vector<Boy>& boys, const vector<Girl>&allGirls) const;
	void automatchGirl(const vector<Boy>& boys, const vector<Girl>&allGirls) const;

	void bestMatchBoy(const vector<Boy>& boys, const vector<Girl>&allGirls) const;
	void bestMatchGirl(const vector<Boy>& boys, const vector<Girl>&allGirls) const;

};



