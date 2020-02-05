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

	void load() {
		loadBoys();
		loadGirls();
	}
	void automatch() const;
	void print() const;//打印vector中男女信息

private:
	vector<Boy> boys;
	vector<Girl> girls;

	void loadBoys();//将文件中加载至vector
	void loadGirls();

	void saveBoys();//将vector中存入文件
	void saveGirls();
};



