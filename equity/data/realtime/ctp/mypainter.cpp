#include <stdio.h>
#include "mypainter.h"

MyPainter::MyPainter(QWidget *parent) : QPainter(parent)
{
	pointCount = 0;
	minprice = 40000.0, maxprice = 43000.0;
}

void MyPainter::drawPrice(double lastprice)
{
//	QSize qsize = this->size();
	int width = (pointCount + 1) * 10000 / 3000;	
	int height = (int)((lastprice - maxprice) * 5000 /
			(minprice - maxprice));
	printf("%d %lf %d %d\n", pointCount, lastprice, width, height);
//	drawPoint(width, height);
	drawPoint(50, 200);

	++pointCount;
}



