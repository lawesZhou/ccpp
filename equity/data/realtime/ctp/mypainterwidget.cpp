#include <QApplication>
#include <QString>
#include <QMessageBox>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QLabel>

#include "mypainterwidget.h"
#include "mypainter.h"
#include "ctpclient.h"

extern CtpClient *ctpclient;

MyPainterWidget::MyPainterWidget(QWidget* parent) : QWidget(parent)
{
}

MyPainterWidget::~MyPainterWidget()
{
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

	painter->drawPoint(100, 50);
	update();
}
