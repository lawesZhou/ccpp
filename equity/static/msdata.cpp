#include <cstdlib>
#include <cstdio>
#include <iostream>

#include "msdata.h"

using namespace std;

MsData::MsData()
{
	mysql_init(&mysql);
       	if (!mysql_real_connect(&mysql, "localhost", "laosi", "123456", 
			        "Futures", 0, NULL, 0)) {
		perror("failed to open database ");
		exit(-1);
	}

	const char *query = "select * from test";
	if(mysql_query(&mysql, query)) {
		cerr << "the query statement execute failed "
		       << query << endl;
		exit(-1);
	}

	query_res = mysql_store_result(&mysql);
}

MsData::~MsData()
{
	//check the database connection
	if (!mysql_ping(&mysql)) {
		mysql_close(&mysql);
	}
}

bool MsData::getnextdata()
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
