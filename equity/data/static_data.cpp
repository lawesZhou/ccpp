#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>

#include <mysql.h>
#include "static_data.h"
using namespace std;

static_data::static_data() : x(0)
{
}

static_data::~static_data()
{
}

file_data::file_data()
{
	filename = "000001.lastprice";
	fp = fopen(filename.c_str(), "r");

	if (fp == NULL) {
		perror("failed to open this file");
		exit(-1);
	}
	cout << "open file success" << endl;
} 

file_data::file_data(string filename): filename(filename)
{
	fp = fopen(filename.c_str(), "r");

	if (fp == NULL) {
		perror("failed to open this file");
		exit(-1);
	}
}

file_data::~file_data()
{
	if (fp)	
		fclose(fp);
}

bool file_data::getnextdata()
{
	cout << "read begin" << endl;
	if (fscanf(fp, "%lf", &lastprice) != 1) {
		cout << "read failed" << endl;
		return false;
	}

	cout << "read ok" << endl;
	++x;
	return true;
}

mysql_data::mysql_data()
{
	mysql_init(mysql);
       	if (!mysql_real_connect(mysql, "localhost", "laosi", "123456", 
			        "Futures", 0, NULL, 0)) {
		perror("failed to open database ");
		exit(-1);
	}

	const char *query = "select * from test";
	if(mysql_query(mysql, query)) {
		cerr << "the query statement execute failed "
		       << query << endl;
		exit(-1);
	}

	query_res = mysql_store_result(mysql);
}

mysql_data::~mysql_data()
{
	//check the database connection
	if (!mysql_ping(mysql)) {
		mysql_close(mysql);
	}
}

bool mysql_data::getnextdata()
{
	MYSQL_ROW row;
	if ((row = mysql_fetch_row(query_res))) {
		//unsigned long *length = mysql_fetch_lengths(query_res);
		lastprice = strtod(row[0], NULL);
		++x;
		return true;
	}
	return false;
}
