#include <QApplication>

#include "mypainterwidget.h"
#include "textdata.h"
#include "msdata.h"

using namespace std;

int
main(int argc, char **argv)
{
	QApplication app(argc, argv);

	StaticData *file_fut = new TextData;
	//StaticData *sql_fut = new MsData;
	MyPainterWidget w(file_fut);
	w.show();

//	file_fut->print();

	return app.exec();
}
