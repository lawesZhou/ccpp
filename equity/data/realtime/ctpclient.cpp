#include <QApplication>

#include "ctpclient.h"

CtpClient *ctpclient = new CtpClient;

void CtpClient::getDepthMarketData(CThostFtdcDepthMarketDataField &md)
{
//	UpdateTime(char(9)) + UpdateMillisec
	if (time != 0) {
		time += 1;
		emit lastpriceCome(md.LastPrice);
	}
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

void 
CSimpleHandler::OnFrontConnected() 
{
	CThostFtdcReqUserLoginField reqUserLogin;
	// get BrokerID
	strcpy(g_chBrokerID, "7030");
	printf("BrokerID: %s\n", g_chBrokerID);
	//			scanf("%s", &g_chBrokerID);
	strcpy(reqUserLogin. BrokerID, g_chBrokerID);
	// get userid
	strcpy(g_chUserID, "00000098");
	printf("userid: %s\n", g_chUserID);
	//			scanf("%s", &g_chUserID);
	strcpy(reqUserLogin.UserID, g_chUserID);
	// get password
	strcpy(reqUserLogin.Password, "123456");
	printf("password:");
	//	scanf("%s", &reqUserLogin.Password);
	// 发出登陆请求
	m_pUserApi->ReqUserLogin(&reqUserLogin, 0);
}

void 
CSimpleHandler::OnFrontDisconnected(int nReason)
{
	// 当发生这个情况后,API会自动重新连接,客户端可不做处理
	printf("OnFrontDisconnected.\n");
}

void 
CSimpleHandler::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, 
		CThostFtdcRspInfoField *pRspInfo, 
		int nRequestID, bool bIsLast)
{
	printf("OnRspUserLogin:\n");
	printf("ErrorCode=[%d], ErrorMsg=[%s]\n", pRspInfo->ErrorID,
			pRspInfo->ErrorMsg);
	printf("RequestID=[%d], Chain=[%d]\n", nRequestID, bIsLast);
	if (pRspInfo->ErrorID != 0) {
		// 端登失败,客户端需进行错误处理
		printf("Failed to login, errorcode=%d errormsg=%s" 
		       "requestid=%d chain=%d", pRspInfo->ErrorID, 
		       pRspInfo->ErrorMsg, nRequestID, bIsLast);
		exit(-1);
	}
	// 端登成功
	// 订阅行情
	const char * Instrumnet[]={"IF1502","IF1503"};
	m_pUserApi->SubscribeMarketData ((char **)Instrumnet,2);
	//或退订行情
	//m_pUserApi->UnSubscribeMarketData (Instrumnet,2);
}
void 
CSimpleHandler::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *md)
{
	printf("%s %f\n", md->InstrumentID, md->LastPrice);
	ctpclient->getDepthMarketData(*md);
	// 输出报单录入结果
	//收到深度行情
};

// 针对用户请求的出错通知
void 
CSimpleHandler::OnRspError(CThostFtdcRspInfoField *pRspInfo, 
			   int nRequestID, bool bIsLast) 
{
	printf("OnRspError:\n");
	printf("ErrorCode=[%d], ErrorMsg=[%s]\n",
	       pRspInfo->ErrorID, pRspInfo->ErrorMsg);
	printf("RequestID=[%d], Chain=[%d]\n", 
	       nRequestID, bIsLast);
}
