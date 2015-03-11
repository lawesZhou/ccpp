// tradeapitest.h :
// 一个简单的例子,介绍CThostFtdcMdApi和CThostFtdcMdSpi接口的使用。
// 本例将演示一个报单录入操作的过程
#ifndef CTPCLIENT_H
#define CTPCLIENT_H

#include <QApplication>

#include "ThostFtdcMdApi.h"

class CtpClient : public QObject {
	Q_OBJECT

public:
	CtpClient() {time = 0;}
public slots:
	void getDepthMarketData(CThostFtdcDepthMarketDataField &md);
//	void drawprice(double);
signals:
	void lastpriceCome(double);
private:
	double time;
};

#endif
