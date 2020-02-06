#pragma once
#include "Boy.h"
#include "Girl.h"

/*
功能:
加载用户信息load()
实现自动配对automatch()
打印配对信息print()
数据:
男信息
女信息
*/

class Database
{
public:
	Database();

	void load(bool input) {
		loadBoys(input);
		loadGirls(input);
	}
	void print() const;//打印boys和girls中所有男女信息
	void allMatch() const;
	void inputMatch() const;
	void bestMatch() const;
private:
	vector<Boy> boys;//vector每次用之前需要初始化为0吗?
	vector<Girl> girls;
	vector<Boy> newBoys;
	vector<Girl> newGirls;

	void loadBoys(bool input);//将文件中加载至vector
	void loadGirls(bool input);

	void saveBoys(vector<Boy> boys);//将vector中存入文件
	void saveGirls(vector<Girl> girls);

	void automatchBoy(vector<Boy> boys, vector<Girl> girls) const;
	void automatchGirl(vector<Boy> boys, vector<Girl> girls) const;

	void bestMatchBoy(vector<Boy> boys, vector<Girl> girls) const;
	void bestMatchGirl(vector<Boy> boys, vector<Girl> girls) const;

};



