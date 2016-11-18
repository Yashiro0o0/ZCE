#include <iostream>
#include <string>
#include "FTDAPI.h"
#include "FieldID.h"
#include  "CallBack.h"
#include <direct.h>

#pragma comment(lib, "FTDDLL.lib")
#pragma warning(disable:4996)

long long MaxOrderLocalId = 0;
int MarketStatus = 0;

//函数声明
//登录函数
bool ZCELogin(ExchgConnectionHandle conn, short int DFF, const char *ParticipantId, const char *UserId, const char *Password);
//下期货限价单
bool Order_LimitPrice(ExchgConnectionHandle conn, const char *ParticipantId, const char *UserId, const char *ClientId);
//报单查询
bool ReqQryOrder(ExchgConnectionHandle conn, const char *ParticipantId, const char *UserId);
//客户信息查询
bool ReqQryClient(ExchgConnectionHandle conn, const char *ParticipantId);
//成交行情查询
bool ReqQryMarketMatchData(ExchgConnectionHandle conn);
//市场交易状态查询
bool ReqQryMarketStatus(ExchgConnectionHandle conn);
//合约查询
bool ReqQryInstrument(ExchgConnectionHandle conn);

int main(int argc, char **argv)
{
	_mkdir("./Record");
	if (ftd_api_init(MULTI_THREAD_MODE, "./log", 0))
	{
		std::cout << "Succeed in Init API" << std::endl;
	}
	else
	{
		std::cout << "Failed in Init API" << std::endl;
		return 0;
	}

	char Version[20] = "";
	if (ftd_api_getVersion(Version, 20 == -1))
	{
		std::cout << "Failed in get version !" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "ZCEAPI version is : " << Version << std::endl;
	}

	//设置回调函数
	ExchgConnectionCallBack OnOpen = OnAPIOpen;
	ExchgConnectionCallBack OnClose = OnAPIClose;
	ExchgConnectionCallBack ErrorCallBack = OnErrors;	//链路状态出错回调函数
	ExchgPackageCallBack LoginCallBack = OnAPILogin;	//成功登录的回调函数
	ExchgPackageCallBack LogoutCallBack = OnAPILogout;	//退出登录的回调函数
	ExchgPackageCallBack recvCallBack = OnRec;		    //收到数据包回调函数

	API_BOOL Encrypt = API_TRUE;
	API_BOOL Commpress = API_TRUE;
	MARKET_ID Market_ID = MARKET_ZCE;
	int heart_beat_interval = 20;
	int heart_beat_timeout = 150;
	char IpAddr[20] = "172.20.71.129";       //交易所的IP地址,如218.29.68.231
	int port = 22677;         	//连接交易所的端口,如:22577(非加密),22677(加密)

	ExchgConnectionHandle DialogConn = NULL;
	ExchgConnectionHandle PrivateConn = NULL;
	ExchgConnectionHandle BroadcastConn = NULL;

	//建立对话流连接对象
	DialogConn= API_CreateExchgConnection(Encrypt, Commpress, Market_ID, heart_beat_interval, heart_beat_timeout);
	if (DialogConn == NULL)
	{
		std::cout << "Can not create Dialog connection to ZCE！" << std::endl;
		return 0;
	}
	//建立私有流连接对象
	PrivateConn = API_CreateExchgConnection(Encrypt, Commpress, Market_ID, heart_beat_interval, heart_beat_timeout);
	if (PrivateConn == NULL)
	{
		std::cout << "Can not create Private connection to ZCE！" << std::endl;
		return 0;
	}
	//建立广播流连接对象
	BroadcastConn = API_CreateExchgConnection(Encrypt, Commpress, Market_ID, heart_beat_interval, heart_beat_timeout);
	if (BroadcastConn == NULL)
	{
		std::cout << "Can not create Broadcast connection to ZCE！" << std::endl;
		return 0;
	}

	//设置回调函数
	//设置链路连接回调函数
	API_SetOpenCallBack(DialogConn, OnOpen, NULL);
	//设置链路断开回调函数
	API_SetCloseCallBack(DialogConn, OnClose, NULL);
	//设置登录成功回调函数
	API_SetLoginCallBack(DialogConn, LoginCallBack, NULL);
	//设置退出成功回调函数
	API_SetLogoutCallBack(DialogConn, LogoutCallBack, NULL);
	//设置收到数据包回调函数
	API_SetRecvCallBack(DialogConn, recvCallBack, NULL);
	//设置链路出错回调
	API_SetErrorCallBack(DialogConn, ErrorCallBack, NULL);

	//设置链路连接回调函数
	API_SetOpenCallBack(PrivateConn, OnOpen, NULL);
	//设置链路断开回调函数
	API_SetCloseCallBack(PrivateConn, OnClose, NULL);
	//设置登录成功回调函数
	API_SetLoginCallBack(PrivateConn, LoginCallBack, NULL);
	//设置退出成功回调函数
	API_SetLogoutCallBack(PrivateConn, LogoutCallBack, NULL);
	//设置收到数据包回调函数
	API_SetRecvCallBack(PrivateConn, recvCallBack, NULL);
	//设置链路出错回调
	API_SetErrorCallBack(PrivateConn, ErrorCallBack, NULL);

	//设置链路连接回调函数
	API_SetOpenCallBack(BroadcastConn, OnOpen, NULL);
	//设置链路断开回调函数
	API_SetCloseCallBack(BroadcastConn, OnClose, NULL);
	//设置登录成功回调函数
	API_SetLoginCallBack(BroadcastConn, LoginCallBack, NULL);
	//设置退出成功回调函数
	API_SetLogoutCallBack(BroadcastConn, LogoutCallBack, NULL);
	//设置收到数据包回调函数
	API_SetRecvCallBack(BroadcastConn, recvCallBack, NULL);
	//设置链路出错回调
	API_SetErrorCallBack(BroadcastConn, ErrorCallBack, NULL);

	//输入登录账户信息
	char ParticipantId[20] = "";    //交易会员编码
	char UserId[15] = "";           //交易员编码
	char Password[20] = "";         //口令
	char ClientId[10] = "";         //客户编号

	//连接成功后登录交易所,登录对话流
	if (!ZCELogin(DialogConn, 0, ParticipantId, UserId, Password))
	{
		//输入Q退出
		std::cout << "输入Q退出程序!" << std::endl;
		char command;
		bool quit = false;
		while (true)
		{
			std::cin >> command;
			if (command == 'Q')
			{
				quit = true;
			}
			if (quit) break;
		}
		return 0;		//不成功登陆时,退出程序
	}
	//连接成功后登录交易所,登录私有流
	if (!ZCELogin(PrivateConn, 1, ParticipantId, UserId, Password))
	{
		//输入Q退出
		std::cout << "输入Q退出程序!" << std::endl;
		char command;
		bool quit = false;
		while (true)
		{
			std::cin >> command;
			if (command == 'Q')
			{
				quit = true;
			}
			if (quit) break;
		}
		return 0;		//不成功登陆时,退出程序
	}
	//连接成功后登录交易所,登录广播流
	if (!ZCELogin(BroadcastConn, 2, ParticipantId, UserId, Password))
	{
		//输入Q退出
		std::cout << "输入Q退出程序!" << std::endl;
		char command;
		bool quit = false;
		while (true)
		{
			std::cin >> command;
			if (command == 'Q')
			{
				quit = true;
			}
			if (quit) break;
		}
		return 0;		//不成功登陆时,退出程序
	}

	if (!ReqQryMarketStatus(DialogConn))
	{
		return -1;
	}
	if (Order_LimitPrice(DialogConn, ParticipantId, UserId, ClientId))
	{
		std::cout << "下期货限价单成功" << std::endl << std::endl;
	}
	else
	{
		std::cout << "下期货限价单失败" << std::endl << std::endl;
	}
	
	//断开并释放交易所连接对象
	API_FreeExchgConnection(DialogConn);
	API_FreeExchgConnection(PrivateConn);
	API_FreeExchgConnection(BroadcastConn);

	//停止ZCEAPI服务
	ftd_api_stop();

	return 0;
}

bool ZCELogin(ExchgConnectionHandle conn, short int DFF, const char *ParticipantId, const char *UserId, const char *Password)
{
	//登录请求包(PID):0x00016
	MsgPackageHandle  APIpkg;       //数据包句柄
	APIpkg = API_AllocPackage();    //分配一个API数据包

	short int	DataFlowFlag = DFF;							//数据流号,0->对话流,1->私有流,2->广播流
	char		ConnectionReference[] = " ";				//链路标示,目前未用
	char		ServerAppName[] = "ZCE_DEMO_MT";			//会员应用系统名称
	char		ProtocolVersion[10] = "2";					//使用FTD版本号,目前=2
	int			TimeOut = 10;								//发送监测信号时间间隔,目前未用
	char		IpAddr2[20] = "192.168.199.100";			//登录者的IP地址,如192.168.199.100
	int			SequenceNo = 0;								//链路应答序列号
	char		INIT_PASSWORD[20] = "12345678";				//联络初始密钥
	char		AUTH_SERIAL_NO[20] = "12345678-12345678";	//序列号:12345678-12345678
	char		AUTH_CODE[20] = "12345678-12345678";		//授权码:12345678-12345678
	int			FRspSeqNO;									//请求序列号
	int         iStart_SeqNo_Prv = 1;						//希望从序号为iStart_SeqNo_Prv+1的数据包开始补发私有流数据
	int         iStart_SeqNo_Brd = 1;						//希望从序号为iStart_SeqNo_Prv+1的数据包开始补发私有流数据
	int			LoginTimeout = 5;

	//下面填写登陆数据包然后再将他们发送出去(目前未用的字段可以不填写) 
	API_SetPID(APIpkg, 0x00016);
	API_SFInt(APIpkg, FID_DataFlowFlag, DataFlowFlag);	    //创建时得到的
	API_SFString(APIpkg, FID_ParticipantId, ParticipantId, strlen(ParticipantId));
	API_SFString(APIpkg, FID_UserId, UserId, strlen(UserId));
	API_SFString(APIpkg, FID_Password, Password, strlen(Password));
	API_SFString(APIpkg, FID_IpAddr, IpAddr2, strlen(IpAddr2));
	API_SFString(APIpkg, FID_AUTH_SERIAL_NO, AUTH_SERIAL_NO, strlen(AUTH_SERIAL_NO));
	API_SFString(APIpkg, FID_AUTH_CODE, AUTH_CODE, strlen(AUTH_CODE));
	API_SFString(APIpkg, FID_INIT_PASSWORD, INIT_PASSWORD, strlen(INIT_PASSWORD));
	API_SFString(APIpkg, FID_ProtocolVersion, ProtocolVersion, strlen(ProtocolVersion));
	if (DFF == 0)						//0->对话流
		FRspSeqNO = 0;					//对话流登录，序号设为0
	else if (DFF == 1)                  //1->私有流
		FRspSeqNO = iStart_SeqNo_Prv;	//希望从序号为iStart_SeqNo_Prv+1的数据包开始补发私有流数据
	else if (DFF == 2)                  //2->广播流
		FRspSeqNO = iStart_SeqNo_Brd;	//希望从序号为iStart_SeqNo_Brd+1的数据包开始补发广播流数据
	API_SFInt(APIpkg, FID_SequenceNo, FRspSeqNO);

	bool ret;
	if (API_Login(conn, APIpkg, LoginTimeout) == API_TRUE)
	{
		ret = true;
	}
	else
	{
		ret = false;
	}
	API_FreePackage(APIpkg);
	return ret;
}

bool Order_LimitPrice(ExchgConnectionHandle conn, const char *ParticipantId, const char *UserId, const char *ClientId)
{
	//报单录入请求(PID):0x00003
	MsgPackageHandle  APIpkg;       //数据包句柄
	APIpkg = API_AllocPackage();    //分配一个API数据包

	char OrderSysId[20] = "";   //合同号,下单成功由系统填写
	char OrderLocaLId[24] = "";  //委托编号，交易所建议采用8位日期+8为序列号的格式，原因是因为存在长期有效的订单，使用委托编号可以定位所下的每一个委托
	short int	Direction = 0;								//		买卖方向,可以不用输入,0->买,1->卖,2->所有
	short int	OffsetFlag = 0;								//		开平仓标记,0->开仓,1->平仓,2->强平
	short int	HedgeFlag = 1;								//		投保标记,1->投机,3->套期保值
	double		StopPrice = 0;								//[12]  止损价格,FTDFloatType<12,4>
	double		LimitPrice = 0;								//[12]  限价(或止损定单的保护价),FTDFloatType<12,4>
	int			VolumeTotalOrginal = 5;						//[4]	原始总申报数量(以手为单位),二进制网络序
	short int	OrderType = 0;								//		报单类型,0->限价,1->市价,3->止损,7->组合定单,101->跨期套利确认,102->持仓套保确认,103->请求报价,104->期权权力行使,105->报价请求响应,106->期权权力放弃
	short int	MatchCondition = 3;							//		报单成交属性,1->即时全部成交,2->即时部分成交,3->当日有效,4->取消前有效,5->指定日期前有效
	char		MatchSession = ' ';							//		报单成交时间,目前未用
	API_DateTime	ValidThrough;							//[8]	有效时间约束,YYYYMMDD
	int			MinimalVolume = 0;							//[4]	最小成交量,二进制网络序,目前未用
	short int	AutoSuspend = 1;							//		自动挂起标志,1->真,0->假
	API_DateTime	InsertTime;								//[20]  录入时间,若下单成功，由系统填写
	char		MessageReference[100] = "自定义数据";	    //[100]	用户自定义数据,备注信息
	short int	CMBType = 0;								//		组合定单类型,0-SPZ,1-SPD,2-IPS,3-BUL,4-BER,5-BLT,6-BRT,7-STD,8-STG,9-PRT
	char		SecondLeg[20] = " ";						//[20]	组合定单第二腿
	char InstrumentId[20] = "ZC701";  //合约编码 期货或者期权都可以

	API_Now(&ValidThrough);
	API_Now(&InsertTime);
	sprintf(OrderLocaLId, "%lld", ++MaxOrderLocalId);
	LimitPrice = 500; 

	//下面填写下单请求数据包然后再将他们发送出去(目前未用的字段可以不填写) 
	API_SetPID(APIpkg, 0x00003);
	API_SFString(APIpkg, FID_OrderSysId, OrderSysId, strlen(OrderSysId));
	API_SFString(APIpkg, FID_OrderLocalId, OrderLocaLId, strlen(OrderLocaLId));
	API_SFString(APIpkg, FID_ParticipantId, ParticipantId, strlen(ParticipantId));
	API_SFString(APIpkg, FID_UserId, UserId, strlen(UserId));
	API_SFString(APIpkg, FID_ClientId, ClientId, strlen(ClientId));
	API_SFString(APIpkg, FID_InstrumentId, InstrumentId, strlen(InstrumentId));
	API_SFInt(APIpkg, FID_Direction, Direction);
	API_SFInt(APIpkg, FID_OffsetFlag, OffsetFlag);
	API_SFInt(APIpkg, FID_HedgeFlag, HedgeFlag);
	API_SFDouble(APIpkg, FID_StopPrice, StopPrice);
	API_SFDouble(APIpkg, FID_LimitPrice, LimitPrice);
	API_SFInt(APIpkg, FID_VolumeTotalOrginal, VolumeTotalOrginal);
	API_SFInt(APIpkg, FID_OrderType, OrderType);
	API_SFInt(APIpkg, FID_MatchCondition, MatchCondition);
	API_SFChar(APIpkg, FID_MatchSession, MatchSession);
	API_SFDateTime(APIpkg, FID_ValidThrough, &ValidThrough);
	API_SFInt(APIpkg, FID_MinimalVolume, MinimalVolume);
	API_SFInt(APIpkg, FID_AutoSuspend, AutoSuspend);
	API_SFDateTime(APIpkg, FID_InsertTime, &InsertTime);
	API_SFString(APIpkg, FID_MessageReference, MessageReference, strlen(MessageReference));
	API_SFInt(APIpkg, FID_CmbType, CMBType);
	API_SFString(APIpkg, FID_SecondLeg, SecondLeg, strlen(SecondLeg));

	//将发送数据包
	bool ret;
	if (API_Send(conn, APIpkg) == API_TRUE)
	{
		ret = true;
	}
	else
	{
		std::cout << "Fail in sending Order_LimitPrice!" << std::endl;
		ret = false;
	}

	//修改买卖方向,使定单自成交
	Direction = 1;
	API_SFInt(APIpkg, FID_Direction, Direction);

	//修改本地定单委托编号
	sprintf(OrderLocaLId, "%lld", ++MaxOrderLocalId);
	API_SFString(APIpkg, FID_OrderLocalId, OrderLocaLId, strlen(OrderLocaLId));


	if (API_Send(conn, APIpkg) == API_TRUE)
	{
		ret = true;
	}
	else
	{
		std::cout << "Fail in sending Order_LimitPrice!" << std::endl;
		ret = false;
	}

	//释放掉我们分配的API数据包对象
	API_FreePackage(APIpkg);
	return ret;
}

bool ReqQryMarketStatus(ExchgConnectionHandle conn)
{
	bool ret = false;
	switch (MarketStatus)
	{
		case 8:
		{
			std::cout << "系统未装载，未就绪！" << std::endl;
			break;
		}
		case 1:
		{
			std::cout << "系统就绪，可以登录！" << std::endl;
			ret = true;
			break;
		}
		case 3:
		{
			std::cout << "开盘竞价入单开始阶段！" << std::endl;
			ret = true;
			break;
		}
		case 13:
		{
			std::cout << "开盘竞价入单结束阶段，开盘集合竞价开始！" << std::endl;
			ret = true;
			break;
		}
		case 14:
		{
			std::cout << "开盘竞价结束！" << std::endl;
			ret = true;
			break;
		}
		case 4: case 9:
		{
			std::cout << "连续交易阶段！" << std::endl;
			ret = true;
			break;
		}
		case 5: case 11:
		{
			std::cout << "暂停阶段！" << std::endl;
			break;
		}
		case 7: case 10:
		{
			std::cout << "交易闭市！" << std::endl;
			break;
		}
		case 6:
		{
			std::cout << "系统挂起阶段" << std::endl;
			break;
		}
	}
	return ret;
}