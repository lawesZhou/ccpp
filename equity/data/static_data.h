#ifndef STATIC_DATA_H
#define STATIC_DATA_H

#include <string>
#include <cstdio>
#include <iostream>

#include <mysql.h>

struct point {
	double x;
	int y;
};

enum SEC_TYPE {
	EQUITY, FUTURES
};

class dataframe {
public:
	dataframe();
};

class edataframe : public dataframe {
};

class fdataframe : public dataframe{
};

class static_data {
public:
	static_data();
	~static_data();

	virtual bool getnextdata() = 0;
	point getpoint() {return this->pnt;}
	void print() {
		std::cout << lastprice << '\t' << x << std::endl;
	}
protected:
	double lastprice;
	int x;
	SEC_TYPE sec_type;

	std::string type;
	std::string format;
	struct point pnt;

};

class file_data: public static_data {
public:
	file_data();
	file_data(std::string filename);
	virtual ~file_data();

	virtual bool getnextdata();
private:
	std::string src_dir;
	std::string filename;
	FILE *fp;
};

class mysql_data : public static_data {
public:
	mysql_data();
	virtual ~mysql_data();
	virtual bool getnextdata();
private:
	MYSQL mysql;
	MYSQL_RES *query_res;
};

#endif
