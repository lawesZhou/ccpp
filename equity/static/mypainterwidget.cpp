#include <QApplication>
#include <QString>
#include <QMessageBox>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QLabel>

#include <pthread.h>
#include <unistd.h>

#include "mypainterwidget.h"
#include "static_data.h"

extern std::vector<struct point> pointSet;

static void *thread_init(void *args)
{
	MyPainterWidget *pw = (MyPainterWidget *)args;
	StaticData *data = pw->data;
	sleep(1);
	data->print(pw);
	pause();
	return NULL;
}

MyPainterWidget::MyPainterWidget()
{
}

MyPainterWidget::MyPainterWidget(StaticData *static_data) : data(static_data)
{
	pthread_t pth;
        pthread_create(&pth, NULL, thread_init, this);
}

MyPainterWidget::~MyPainterWidget()
{
}

void MyPainterWidget::paintEvent(QPaintEvent *p)
{
	QPainter painter(this);
	QPen pen;                      //创建一个画笔
	pen.setColor(Qt::darkCyan);
	pen.setWidth(2);
	painter.setPen(pen);

	printf("pointSet.size() = %lu\n", pointSet.size());

	for (size_t i = 0; i < pointSet.size(); ++i) {
		painter.drawPoint(pointSet[i].x % 200, (pointSet[i].y - 2200) / 300 * 500);
	}

	printf("end\n");
}
