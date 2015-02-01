#include <mysql.h>
#include <iostream>

using namespace std;

	int
main()
{
	MYSQL mysql;
	mysql_init(&mysql);
       	if (mysql_real_connect(&mysql, "localhost", "laosi", "123456", 
			       "Futures", 0, NULL, 0)) {
		const char *query = "select * from test";
		MYSQL_ROW row;
		if (!mysql_query(&mysql, query)) {
			MYSQL_RES *res = mysql_store_result(&mysql);
			int n = mysql_num_rows(res);
			int num_fields = mysql_num_fields(res);
			while ((row = mysql_fetch_row(res))) {
				
				unsigned long *length = mysql_fetch_lengths(res);
				for (int i = 0; i < num_fields; ++i) {
					cout << length[i] << '\t' 
						<< row[i] << '\n';
				}
			}
			cout << "mysql :" << n << endl;
			MYSQL_FIELD *fd;
			for (int i = 0; fd = mysql_fetch_field(res); ++i) {
				cout << fd->name << '\t' 
				     << IS_NUM(fd->type) << endl; 
			}
		}
	}
	return 0;
}
