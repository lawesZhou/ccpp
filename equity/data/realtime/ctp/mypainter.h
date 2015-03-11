#ifndef MYPAINTER_H 
#define MYPAINTER_H

#include <QApplication>
#include <QPainter>
#include <QWidget>

class MyPainter : public QObject, public QPainter{
	Q_OBJECT	
public:
	MyPainter(QWidget *parent);
public slots:
	void drawPrice(double lastprice);
private:
	double lastprice;
	double minprice, maxprice;
	int pointCount;
};

#endif
