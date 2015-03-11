#include "mypainterwidget.h"
#include <QString>
#include <QMessageBox>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QLabel>


MyPainterWidget::MyPainterWidget(QWidget* parent) : QWidget(parent)
{
}

MyPainterWidget::~MyPainterWidget()
{
}

void MyPainterWidget::paintEvent(QPaintEvent*p){
	QPainter painter(this);
	QPen pen;                                 //创建一个画笔
	pen.setColor(Qt::darkCyan);
	pen.setWidth(2);
	painter.setPen(pen);

	FILE *fp = fopen("000001.lastprice", "r");
	if (fp == NULL) {
		perror("failed to open file");
		return;
	}

	QLabel *label = new QLabel(this);
	label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
	label->setText("first line\nsecond line");
	label->setAlignment(Qt::AlignBottom | Qt::AlignRight);

	double lastprice;
	int n = 1;
	QSize qsize = this->size();
	double minprice = 2350.0, maxprice = 2370.0;

	while (fscanf(fp, "%lf", &lastprice) == 1) {
		int width = (n - 1) * qsize.width() / 3000;	
		int height = (int)((lastprice - maxprice) * qsize.height() /
				(minprice - maxprice));
//		printf("%lf %d %d\n", lastprice, width, height);
		painter.drawPoint(width, height);
		++n;
	}
	update();
	fclose(fp);
}
