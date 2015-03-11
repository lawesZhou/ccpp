#ifndef MYPAINTERWIDGET_H
#define MYPAINTERWIDGET_H

#include <QWidget>
#include <QPoint>
#include <vector>

//线段
struct myLine{
	QPoint startPnt;
	QPoint endPnt;
};

class MyPainterWidget: public QWidget {
public:
	MyPainterWidget(QWidget* parent);
	~MyPainterWidget();

	//继承
	void paintEvent(QPaintEvent* p);
private:
	QPoint startPnt;   //起点
	QPoint endPnt;     //终点
	bool isPressed;    //鼠标是否按下

	std::vector<myLine*> lines; //存放所有的线段
};

#endif // MYPAINTERWIDGET_H
