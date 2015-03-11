#include <QApplication>

#include "ctpclient.h"

CtpClient *ctpclient = new CtpClient;

void CtpClient::getDepthMarketData(CThostFtdcDepthMarketDataField &md)
{
	emit lastpriceCome(md.LastPrice);
//	UpdateTime(char(9)) + UpdateMillisec
	time += 1;
}
/*
void CtpClient::drawprice(double)
{
	MyPainter *painter = new MyPainter(this);

	QPen pen;                      //创建一个画笔
	pen.setColor(Qt::darkCyan);
	pen.setWidth(2);
	painter->setPen(pen);
}
*/
