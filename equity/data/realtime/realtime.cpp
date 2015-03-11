#include <QApplication>
#include <QString>
#include <QMessageBox>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QLabel>

#include "mypainterwidget.h"
#include "ctpclient.h"

extern CtpClient *ctpclient;

MyPainterWidget::MyPainterWidget(QWidget* parent) : QWidget(parent)
{
}

MyPainterWidget::~MyPainterWidget()
{
}

MyPainter::MyPainter(QWidget *parent) : QPainter(parent)
{
	pointCount = 0;
	minprice = 2350.0, maxprice = 2370.0;
}

void MyPainter::drawPrice(double lastprice)
{
//	QSize qsize = this->size();
	int width = (pointCount - 1) / 3000;	
	int height = (int)((lastprice - maxprice)  /
			(minprice - maxprice));
//		printf("%lf %d %d\n", lastprice, width, height);
	drawPoint(width, height);
	++pointCount;
}

void MyPainterWidget::paintEvent(QPaintEvent *p)
{
	MyPainter *painter = new MyPainter(this);

	QPen pen;                      //创建一个画笔
	pen.setColor(Qt::darkCyan);
	pen.setWidth(2);
	painter->setPen(pen);

	QObject::connect(ctpclient, SIGNAL(lastpriceCome(double)), 
			 painter, SLOT(drawPrice(double)));

	update();
}
