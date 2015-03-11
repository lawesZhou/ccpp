#include <QApplication>  
#include "mypainterwidget.h"  
#include "ThostFtdcMdApi.h"
#include "ctpclient.h"
      
int main(int argc,char** argv)  
{  
	// 产生一个CThostFtdcMdApi实例
	CThostFtdcMdApi *pUserApi = CThostFtdcMdApi::CreateFtdcMdApi();
	// 产生一个事件处理的实例
	CSimpleHandler sh(pUserApi);
	// 注册一事件处理的实例
	pUserApi->RegisterSpi(&sh);
	// 设置交易托管系统服务的地址,可以注册多个地址备用
	pUserApi->RegisterFront((char *)"tcp://sh-front2.168qh.com:41213");
	// 使客户端开始与后台服务建立连接
	pUserApi->Init();

	QApplication app(argc,argv);  
     
  	MyPainterWidget w(0);  
        w.show();  

        return app.exec();  
}  
