#include "static_data.h"

using namespace std;

bool getdata(static_data *data)
{
	while (data->getnextdata()) {
		cout << "ddddddd" << endl;
		data->print();
	}
}

int
main()
{
	static_data *file_fut = new file_data;
	static_data *sql_fut = new mysql_data;

	getdata(file_fut);

	return 0;
}
