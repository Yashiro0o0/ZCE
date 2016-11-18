#include <iostream>
#include <string>
#include "CallBack.h"
#include "FieldID.h"

//全局变量
extern long long MaxOrderLocalId;   //用来存储本地最大定单号
extern int MarketStatus;            //市场状态
extern double SR503_LimitUpPrice;   //SR503的涨停价
extern double SR503_LimitDownPrice; //SR503的跌停价

//将任意一个API数据包按照一定的格式保存到文件中,direction数据流方向(0是发送,1是接收,其它为不记录此标志)
void APIpkgTofile(MsgPackageHandle pkg, int direction);

//登录的回调函数
int OnAPILogin(void * CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg)
{
	//判断是否登录成功
	if (API_FieldIsNull(pkg, FID_ErrorCode))
	{
		std::cout << "登录成功！" << std::endl;
	}
	else
	{
		std::cout << "登录失败";
		char errorCode[20];
		API_GFString(pkg, FID_ErrorCode, errorCode,10);
		std::cout << "错误码为：" << errorCode << std::endl;
	}

	//设置本地最大委托编号
	if (API_GFInt(pkg, FID_DataFlowFlag, 5) == 0)
	{
		long long DefaultOrderLocalId;
		API_DateTime Dt;
		API_Now(&Dt);
		DefaultOrderLocalId = Dt.year * 1000000000000 + Dt.month * 10000000000 + Dt.day * 100000000;

		char S_MaxOrderLocalId[24] = "";
		API_GFString(pkg, FID_MaxOrderLocalId, S_MaxOrderLocalId, 24);

		char BeforeEight[10] = "";
		char AfterEight[10] = "";
		for (int i = 0; i < 8; i++)
		{
			BeforeEight[i] = S_MaxOrderLocalId[i];
			AfterEight[i] = S_MaxOrderLocalId[i + 8];
		}
		MaxOrderLocalId = (long long)(atol(BeforeEight)) * 100000000 + atol(AfterEight);
		if (MaxOrderLocalId < DefaultOrderLocalId)
		{
			MaxOrderLocalId = DefaultOrderLocalId;
		}

		MarketStatus = API_GFInt(pkg, FID_MarketStatusId);
	}

	return 0;
}

//退出的回调函数
int OnAPILogOut(void *CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg)
{
	if (API_FieldIsNull(pkg, FID_ErrorCode))
	{
		std::cout << "Logout Successfully !" << std::endl;
	}
	else
	{
		std::cout << "Failed in Logout!" << std::endl;
	}
	return 0;
}

//链路连接的回调函数
void OnAPIOpen(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text)
{
    if (error_code == 0)
    {
        std::cout << error_text << std::endl;
    }
    else
    {
        std::cout << "错误代码:" << error_code << "    " << "错误正文:" << error_text << std::endl;
    }
}

//链路断开的回调函数
void OnAPIClose(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text)
{
    if (error_code == 0)
    {
        std::cout << error_text << std::endl;
    }
    else
    {
        std::cout << "错误代码:" << error_code << "    " << "错误正文:" << error_text << std::endl;
    }
}

//收到数据包的回调函数
int OnRec(void * CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg)
{

    if (API_GetPID(pkg) == 0x10002)
    {
        //获取SR503的涨跌停价
        char InstrumentId[20] = "";
        if (API_GFString(pkg, FID_InstrumentId, InstrumentId, 20))
        {
            if (!strcmp(InstrumentId, "SR503"))
            {
                SR503_LimitUpPrice = API_GFDouble(pkg, FID_HighLimit);
                SR503_LimitDownPrice = API_GFDouble(pkg, FID_LowLimit);
            }
        }
    }

	if(API_GetPID(pkg) == )

    APIpkgTofile(pkg, 1);
    return 0;
}

//出错的回调函数
void OnErrors(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text)
{
    std::cout << "错误代码:" << error_code << "    " << "错误正文:" << error_text << std::endl;
}