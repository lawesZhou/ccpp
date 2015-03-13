#ifndef MSDATA_H
#define MSDATA_H

#include <mysql.h>
#include "static_data.h"

class MsData : public StaticData {
public:
	MsData();
	virtual ~MsData();
	virtual bool getnextdata();
private:
	MYSQL mysql;
	MYSQL_RES *query_res;
};

#endif
