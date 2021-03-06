// tradeapitest.h :
// 一个简单的例子,介绍CThostFtdcMdApi和CThostFtdcMdSpi接口的使用。
// 本例将演示一个报单录入操作的过程
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "ThostFtdcMdApi.h"
#include "mypainterwidget.h"

class CtpClient : public QObject {
	Q_OBJECT

public:
	CtpClient() {time = 0;}
public slots:
	void getDepthMarketData(CThostFtdcDepthMarketDataField &md);
	void drawprice(double);
signals:
	void lastpriceCome(double);
private:
	double time;
};

// 会员代码
TThostFtdcBrokerIDType g_chBrokerID;
// 交易用户代码
TThostFtdcUserIDType g_chUserID;

class CSimpleHandler : public CThostFtdcMdSpi
{
	public:
		// 构造函数,需要一个有效的指向CThostFtdcMdApi实例的指针
		CSimpleHandler(CThostFtdcMdApi *pUserApi) : m_pUserApi(pUserApi) {}
		~CSimpleHandler() {}
		// 当客户端与交易托管系统建立起通信连接,客户端需要进行登录
		virtual void OnFrontConnected();
		// 当客户端与交易托管系统通信连接断开时,该方法被调用
		virtual void OnFrontDisconnected(int nReason);
		// 当客户端发出登录请求之后,该方法会被调用,通知客户端登录是否成功
		virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

		// 行情应答
		virtual void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *md);
		// 针对用户请求的出错通知
		virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, 
				        int nRequestID, bool bIsLast);
		// 客户端需进行错误处理
		//	{客户端的错误处理}

	private:
		// 指向CThostFtdcMdApi实例的指针
		CThostFtdcMdApi *m_pUserApi;
};

