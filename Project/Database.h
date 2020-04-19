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

	void load(bool input = false) {
		loadBoys(input);
		loadGirls(input);
	}
	void print() const;//打印boys和allGirls中所有男女信息
	void allMatch() const;
	void inputMatch() const;
	void allBestMatch() const;
	void inputBestMatch() const;
private:
	vector<Boy> boys;//vector每次用之前需要初始化为0吗?
	vector<Girl>allGirls;
	vector<Boy> newBoys;
	vector<Girl> newGirls;

	void loadBoys(bool input);//将文件中加载至vector
	void loadGirls(bool input);

	void saveBoys(const vector<Boy>& boys);//将vector中存入文件
	void saveGirls(const vector<Girl>&allGirls);

	void automatchBoy(const vector<Boy>& boys, const vector<Girl>&allGirls) const;
	void automatchGirl(const vector<Boy>& boys, const vector<Girl>&allGirls) const;

	void bestMatchBoy(const vector<Boy>& boys, const vector<Girl>&allGirls) const;
	void bestMatchGirl(const vector<Boy>& boys, const vector<Girl>&allGirls) const;

};



