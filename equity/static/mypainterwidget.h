#ifndef MYPAINTERWIDGET_H
#define MYPAINTERWIDGET_H

#include <QWidget>
#include <QPoint>
#include <vector>

class StaticData;

class MyPainterWidget: public QWidget {
public:
	MyPainterWidget();
	MyPainterWidget(StaticData *static_data);
	~MyPainterWidget();

	//继承
	void paintEvent(QPaintEvent* p);

	StaticData *data;

};

#endif // MYPAINTERWIDGET_H
