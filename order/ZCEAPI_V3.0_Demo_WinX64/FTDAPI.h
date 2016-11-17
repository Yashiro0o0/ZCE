/**************************************************
Copyright:ESUNNY
Author: ZZY
Date:2014-08-011
Description:FTDAPI.h，ZCEAPI对外函数声明文件。
Note:请不要修改该文件
 *************************************************/

#ifndef FTDAPI_H_
#define FTDAPI_H_

#include "Config.h"

#ifdef __cplusplus
extern "C"{
#endif /* __cplusplus */ 

/*****************************************************
*Function:	ftd_api_getVersion     
*Summary:	得到API的版本号字符串，如:1.0.12.1。
*Parameters:
	versionbuf:	存放获取的版本号字符串的地址
	buflen:		存放版本号字符串地址的大小
*Return : 
	缓冲区不够返回-1，不然返回版本字符串长度。
******************************************************/
int FTDAPI_CALL ftd_api_getVersion(char * versionbuf,unsigned int buflen);

/*****************************************************
*Function:	ftd_api_init
*Summary:	初始化API库。
*Parameters:
	mode:	线程模式，目前只能取MULTI_THREAD_MODE
	LogFilePath:	API日志文件路径
	MonitorPort:	监测端口。目前未用。
*Return :
	成功返回API_TRUE,失败返回API_FALSE.
******************************************************/
API_BOOL FTDAPI_CALL ftd_api_init(THREAD_MODE mode,const char *LogFilePath,int MonitorPort);

/*****************************************************
*Function:	ftd_api_stop
*Summary:	停止API库的使用，建议非退出前不要调用。
*Parameters:
*Return :
******************************************************/
void FTDAPI_CALL ftd_api_stop();

/*****************************************************
*Function:	API_AllocPackage
*Summary:	创建通信数据包。
*Parameters:
*Return :
	成功返回数据包对象句柄，不然返回NULL。
******************************************************/
MsgPackageHandle FTDAPI_CALL API_AllocPackage();

/*****************************************************
*Function:	API_FreePackage
*Summary:	回收数据包对象。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
*Return :
******************************************************/
void FTDAPI_CALL API_FreePackage(MsgPackageHandle pkg);

/*---------------------------报文数据操作--------------------------*/

/*****************************************************
*Function:	API_GetPID
*Summary:	获取报文PID。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
*Return :
	成功返回数据PID，不然返回0xFFFFF
******************************************************/
int FTDAPI_CALL API_GetPID(MsgPackageHandle pkg);

/*****************************************************
*Function:	API_SetPID
*Summary:	设置报文PID。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
	pid:要设置的PID
*Return :
******************************************************/
void FTDAPI_CALL API_SetPID(MsgPackageHandle pkg,int pid);

/*****************************************************
*Function:	API_GetFieldType
*Summary:	取得某数据域的当前数据类型。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
	fid:数据域号。
*Return :
	返回指定数据包中指定数据域的数据域类型。没有该数据域返回FTNULL。
******************************************************/
API_FIELDTYPE FTDAPI_CALL API_GetFieldType(MsgPackageHandle pkg, int fid);

/*****************************************************
 *Function:	API_GFChar
 *Summary:	以Char型取指定数据域的值。
 *Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
	fid:数据域号。
	def:没有该数据域时的默认返回值。
 *Return :
	返回指定数据包中指定数据域的字段值。没有该数据域返回def。
 ******************************************************/
char FTDAPI_CALL API_GFChar(MsgPackageHandle pkg,int fid,char def=' ');

/*****************************************************
*Function:	API_SFChar
*Summary:	对指定数据域设置Char类型的值。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
	fid:数据域号。
	val:要设置值。
*Return : 错误码
	0:代表赋值成功
	-1:代表该数据域不能用该类型赋值
	-99:数据包非法
******************************************************/
int FTDAPI_CALL API_SFChar(MsgPackageHandle pkg,int fid,char val);

/*****************************************************
*Function:	API_GFInt
*Summary:	以INT型取指定数据域的值。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
	fid:数据域号。
	def:没有该数据域时的默认返回值。
*Return :
	返回指定数据包中指定数据域的字段值。没有该数据域返回def。
******************************************************/
 int FTDAPI_CALL API_GFInt(MsgPackageHandle pkg,int fid,int def=0);

 /*****************************************************
 *Function:	API_SFChar
 *Summary:	对指定数据域设置整数类型的值。
 *Parameters:
	 pkg:通过函数API_AllocPackage返回的数据包句柄。
	 fid:数据域号。
	 val:要设置值。
 *Return : 错误码
	 0:代表赋值成功
	 -1:代表该数据域不能用该类型赋值
	 -99:数据包非法
 ******************************************************/
 int FTDAPI_CALL API_SFInt(MsgPackageHandle pkg,int fid,int val);

/*****************************************************
 *Function:	API_GFDouble
 *Summary:	以Double型取指定数据域的值。
 *Parameters:
	 pkg:通过函数API_AllocPackage返回的数据包句柄。
	 fid:数据域号。
	 def:没有该数据域时的默认返回值。
 *Return :
	返回指定数据包中指定数据域的字段值。没有该数据域返回def。
 ******************************************************/
 double FTDAPI_CALL API_GFDouble(MsgPackageHandle pkg,int fid,double def=0);

 /*****************************************************
 *Function:	API_SFDouble
 *Summary:	对指定数据域设置Double类型值。
 *Parameters:
	 pkg:通过函数API_AllocPackage返回的数据包句柄。
	 fid:数据域号。
	 val:要设置值。
	 precision:Double值的精度。
 *Return : 错误码
	 0:代表赋值成功
	 -1:代表该数据域不能用该类型赋值
	 -99:数据包非法
 ******************************************************/
 int FTDAPI_CALL API_SFDouble(MsgPackageHandle pkg,int fid,double val,int precision=4);

 /*****************************************************
 *Function:	API_GFString
 *Summary:	以String型取指定数据域的值。
 *Parameters:
	 pkg:通过函数API_AllocPackage返回的数据包句柄。
	 fid:数据域号。
	 buf:保存获取值的地址。
	 bufsize:保存获取值的地址大小。
 *Return :
	获取值的长度。0表示没取到值。
 ******************************************************/
 int FTDAPI_CALL API_GFString(MsgPackageHandle pkg,int fid, char* buf,int bufsize);

 /*****************************************************
 *Function:	API_SFString
 *Summary:	对指定数据域设置String类型值。
 *Parameters:
	 pkg:通过函数API_AllocPackage返回的数据包句柄。
	 fid:数据域号。
	 buf:设置的数据地址。
	 bufsize:设置的数据长度。
 *Return : 错误码
	 0:赋值成功
	 -1:该fid不能用该类型赋值
	 -2:bufsize为0并且没pkg中fid字段并不存在。
	 -99:数据包非法
 ******************************************************/
 int FTDAPI_CALL API_SFString(MsgPackageHandle pkg,int fid,const char* buf,int bufsize);

 /*****************************************************
 *Function:	API_GFDateTime
 *Summary:	以API_DateTime型取指定数据域的值。
 *Parameters:
	 pkg:通过函数API_AllocPackage返回的数据包句柄。
	 fid:数据域号。
	 val:保存获取值的地址。
 *Return :
	成功获取返回API_TRUE;不然返回API_FALSE。
 ******************************************************/
 API_BOOL FTDAPI_CALL API_GFDateTime(MsgPackageHandle pkg, int fid, API_DateTime*val);

 /*****************************************************
 *Function:	API_SFDateTime
 *Summary:	对指定数据域设置API_DateTime类型值。
 *Parameters:
	 pkg:通过函数API_AllocPackage返回的数据包句柄。
	 fid:数据域号。
	 val:设置的数据地址。
 *Return : 错误码
	 0:赋值成功
	 -1:该fid不能用该类型赋值
	 -99:数据包非法
 ******************************************************/
 int FTDAPI_CALL API_SFDateTime(MsgPackageHandle pkg, int fid, API_DateTime*val);

 /*****************************************************
 *Function:	API_FieldIsNull
 *Summary:	判断指定数据包中某个数据域是否为空。
 *Parameters:
	 pkg:通过函数API_AllocPackage返回的数据包句柄。
	 fid:数据域号。
 *Return :
	空返回API_TRUE;不然返回API_FALSE。
 ******************************************************/
 API_BOOL FTDAPI_CALL API_FieldIsNull(MsgPackageHandle pkg,int fid);

/*****************************************************
 *Function:	API_FieldIsNull
 *Summary:	清除某个特定的数据域的值。
 *Parameters:
	 pkg:通过函数API_AllocPackage返回的数据包句柄。
	 fid:数据域号。
 *Return : 
******************************************************/
void FTDAPI_CALL API_ClearField(MsgPackageHandle pkg, int fid);

/*****************************************************
*Function:	API_ClearAll
*Summary:	清除数据报里的所有数据域。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
*Return :
******************************************************/
void FTDAPI_CALL API_ClearAll(MsgPackageHandle pkg);

/*****************************************************
*Function:	API_Copy
*Summary:	把source的数据全部复制到pkg。
*Parameters:
	pkg，source:通过函数API_AllocPackage返回的数据包句柄。
*Return :
******************************************************/
void FTDAPI_CALL API_Copy(MsgPackageHandle pkg,MsgPackageHandle source);

/*****************************************************
*Function:	API_FirstField
*Summary:	移动指定数据包的内部数据域指针到第一个数据域。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
*Return :
	-1:pkg 为空包。
	-99:pkg非法。
******************************************************/
int FTDAPI_CALL API_FirstField(MsgPackageHandle pkg);

/*****************************************************
*Function:	API_NextField
*Summary:	将指定数据包的内部数据域指针下移一位。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
*Return :
	-1:已到结尾。
	-99:pkg非法。
******************************************************/
int FTDAPI_CALL API_NextField(MsgPackageHandle pkg);

/*****************************************************
*Function:	API_CFType
*Summary:	取出指定数据包的当前数据域的数据类型。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
*Return :
	返回指定数据包中当前数据域的数据域类型。失败返回FTNULL。
******************************************************/
API_FIELDTYPE FTDAPI_CALL API_CFType(MsgPackageHandle pkg);

/*****************************************************
*Function:	API_CFDT
*Summary:	以API_DateTime型取当前数据域的值。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
	dt:保存获取值的地址。
*Return :
	成功获取返回API_TRUE;不然返回API_FALSE。
******************************************************/
API_BOOL FTDAPI_CALL API_CFDT(MsgPackageHandle pkg, API_DateTime *dt);

/*****************************************************
*Function:	API_CFChar
*Summary:	以Char型取当前数据域的值。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
	def:失败时的默认返回值。
*Return :
	返回指定数据包中当前数据域的字段值。失败返回def。
******************************************************/
char FTDAPI_CALL API_CFChar(MsgPackageHandle pkg,char def=' ');

/*****************************************************
*Function:	API_CFInt
*Summary:	以INT型取当前数据域的值。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
	def:失败时的默认返回值。
*Return :
	返回指定数据包中当前数据域的字段值。失败域返回def。
******************************************************/
int FTDAPI_CALL API_CFInt(MsgPackageHandle pkg,int def=0);

/*****************************************************
*Function:	API_CFDouble
*Summary:	以Double型取当前数据域的值。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
	prec:传回浮点数的精度。默认为0，即不取精度。
	def:失败的默认返回值。
*Return :
	返回指定数据包中当前数据域的字段值。失败域返回def。
******************************************************/
double FTDAPI_CALL API_CFDouble(MsgPackageHandle pkg,int *prec=0,double def=0);

/*****************************************************
*Function:	API_CFString
*Summary:	以String型取当前数据域的值。
*Parameters:
	pkg:通过函数API_AllocPackage返回的数据包句柄。
	buf:保存获取值的地址。
	bufsize:保存获取值的地址大小。
*Return :
	获取值的长度。0表示没取到值。
******************************************************/
int  FTDAPI_CALL API_CFString(MsgPackageHandle pkg,char* buf,int bufsize);

/*****************************************************
*Function:	API_Now
*Summary:	取得当前本地系统的时间。
*Parameters:
	dt:保存取到时间的地址。
*Return :
******************************************************/
void FTDAPI_CALL API_Now(API_DateTime*dt);

/*****************************************************
*Function:	API_CreateExchgConnection
*Summary:	创建交易所连接对象。
*Parameters:
	Encrypt:是否加密。
	Commpress:是否压缩。
	Market:连接的市场。目前只能取MARKET_ZCE
	heart_beat_interval:心跳间隔。单位秒
	heart_beat_timeout:心跳超时。单位秒
*Return :
	返回创建的连接对象句柄。
******************************************************/
ExchgConnectionHandle FTDAPI_CALL API_CreateExchgConnection(API_BOOL Encrypt,API_BOOL Commpress,MARKET_ID Market
											,int heart_beat_interval,int heart_beat_timeout);

/*****************************************************
*Function:	API_SetConnectionOpt
*Summary:	设置连接的属性参数。
*Parameters:
	conn:交易所连接对象句柄
	keepIdle:连接空闲时间。单位秒
	keepInterval:连接检测间隔。单位秒
	keepCount:检测次数。
*Return :
	成功设置返回0，否则返回错误码。
Note:该函数目前只对Linux平台起作用。
******************************************************/
int FTDAPI_CALL API_SetConnectionOpt(ExchgConnectionHandle conn, int keepIdle, int keepInterval, int keepCount);

/*****************************************************
*Function:	API_Connect
*Summary:	发起与交易所连接
*Parameters:
	conn:交易所连接对象句柄。
	HostIpAddr:代表交易所IP地址的字符串指针
	Port:交易所前置系统端口号
	Wait:超时等待时间，单位秒
*Return :
	连接建立成功返回API_TRUE,否则返回API_FALSE。
Note:该函数不推荐使用，建议使用API_ConnectEx。
******************************************************/
API_BOOL FTDAPI_CALL API_Connect(ExchgConnectionHandle conn,const char* HostIpAddr,int Port,double Wait);

/*****************************************************
*Function:	API_ConnectEx
*Summary:	发起与交易所连接
*Parameters:
	conn:交易所连接对象句柄。
	DNSIp:域名解析服务IP地址
	DNSPort:域名解析服务端口
	Wait:超时等待时间
	UserID:席位号
	gwVersion:前置的版本信息
	ConnMode:申请方式，‘0’:自动分配IP，‘1’:指定IP
	gwIP:在申请方式为1的情况下指定的前置IP
	gwPort:在申请方式为1的情况下指定的前置端口
	errMsg:输出参数。返回错误信息的内存空间。由用户分配，最少51个字节。
*Return :
	错误码:
	0:Err_Success			:成功
	-1:Err_SendDNSReq		:发送DNS请求失败
	-2:Err_RevDNSRsp		:接收DNS应答失败
	-3:Err_DNSData			:接收DNS数据错误
	-4:Err_GetIP			:没有得到分配的前置IP
	-5:Err_ConnectDNS		:连接DNS服务失败
	-6:Err_ConnectGW		:连接交易所前置失败
******************************************************/
int FTDAPI_CALL API_ConnectEx(ExchgConnectionHandle conn,const char* DNSIp,	int DNSPort,double Wait,				
											const char * UserID,const char * gwVersion,	char ConnMode,				
											const char* gwIP,int gwPort,char * errMsg);

/*****************************************************
*Function:	API_Connected
*Summary:	判断交易所连接对象是否已经连接到交易所
*Parameters:
	conn:交易所连接对象句柄。
*Return :
	若连接对象连接到了交易所，返回API_TRUE,否则返回API_FALSE。
******************************************************/
 API_BOOL API_Connected(ExchgConnectionHandle conn);

/*****************************************************
*Function:	API_Login
*Summary:	登录到交易所
*Parameters:
	conn:交易所连接对象句柄。
	reqPkg:包含登录信息的数据包句柄
	Wait:登录超时等待时间。单位秒
*Return :
	登录交易所成功返回API_TRUE,不成功返回API_FALSE。
******************************************************/
API_BOOL FTDAPI_CALL API_Login(ExchgConnectionHandle conn,MsgPackageHandle reqPkg,double Wait);

/*****************************************************
*Function:	API_Logout
*Summary:	退出登录
*Parameters:
	conn:交易所连接对象句柄。
	reqPkg:包含登出信息的数据包句柄
	Wait:登录超时等待时间。单位秒
*Return :
	登出交易所成功返回API_TRUE,不成功返回API_FALSE。
******************************************************/
 API_BOOL FTDAPI_CALL API_Logout(ExchgConnectionHandle conn,MsgPackageHandle reqPkg,double Wait);

/*****************************************************
 *Function:	API_Send
 *Summary:	发送一个数据包
 *Parameters:
	conn:交易所连接对象句柄。
	pkg:包含登出信息的数据包句柄
 *Return :
	发送成功返回API_TRUE,不成功返回API_FALSE。
******************************************************/
 API_BOOL FTDAPI_CALL API_Send(ExchgConnectionHandle conn,MsgPackageHandle pkg);


/*****************************************************
*Function:	API_Recv
*Summary:	从本地数据包缓冲队列中取一个数据包
*Parameters:
	conn:交易所连接对象句柄。
	wait:等待秒数，wait=0:没有数据立即返回
*Return :
	有数据包则返回取得的ZCEAPI数据包句柄。没有数据包则返回NULL
******************************************************/
MsgPackageHandle FTDAPI_CALL API_Recv(ExchgConnectionHandle conn,double wait=0);

/*****************************************************
*Function:	API_DisConnect
*Summary:	断开与交易所的连接
*Parameters:
	conn:交易所连接对象句柄。
*Return :
******************************************************/
void FTDAPI_CALL API_DisConnect(ExchgConnectionHandle conn);

/*****************************************************
*Function:	API_FreeExchgConnection
*Summary:	关闭并释放交易所连接对象
*Parameters:
	conn:交易所连接对象句柄。
*Return :
******************************************************/
void FTDAPI_CALL API_FreeExchgConnection(ExchgConnectionHandle conn);

/*****************************************************
*Function:	API_GetDataFlowStatus
*Summary:	取得数据流状态
*Parameters:
	conn:交易所连接对象句柄。
	DataFlowFlag:数据流标示
*Return :
	返回具体数据流的状态
******************************************************/
API_DFSTATUS FTDAPI_CALL API_GetDataFlowStatus(ExchgConnectionHandle conn, API_DFFLAG DataFlowFlag);

/*****************************************************
*Function:	API_SetOpenCallBack
*Summary:	设置指定的交易所连接对象打开链路时的回调函数
*Parameters:
	conn:交易所连接对象句柄。
	callback:要设置的链路状态回调函数
	CallBackArg:要设置的链路状态回调函数的参数，它将最终传给链路状态回调函数。
*Return :
******************************************************/
void FTDAPI_CALL API_SetOpenCallBack(ExchgConnectionHandle conn, ExchgConnectionCallBack callback, void * CallBackArg);

/*****************************************************
*Function:	API_SetCloseCallBack
*Summary:	设置指定的交易所连接对象链路断开时的回调函数
*Parameters:
	conn:交易所连接对象句柄。
	callback:要设置的链路状态回调函数
	CallBackArg:要设置的链路状态回调函数的参数，它将最终传给链路状态回调函数。
*Return :
******************************************************/
void FTDAPI_CALL API_SetCloseCallBack(ExchgConnectionHandle conn, ExchgConnectionCallBack callback, void * CallBackArg);

/*****************************************************
*Function:	API_SetErrorCallBack
*Summary:	设置指定的连接交易所对象的链路出错时的回调函数
*Parameters:
	conn:交易所连接对象句柄。
	callback:要设置的链路状态回调函数
	CallBackArg:要设置的链路状态回调函数的参数，它将最终传给链路状态回调函数。
*Return :
******************************************************/
void FTDAPI_CALL API_SetErrorCallBack(ExchgConnectionHandle conn, ExchgConnectionCallBack callback, void * CallBackArg);

/*****************************************************
*Function:	API_SetRecvCallBack
*Summary:	设置有数据处理时的回调函数
*Parameters:
	conn:交易所连接对象句柄。
	callback:要设置的返回数据包回调函数
	CallBackArg:要设置的返回数据包回调函数的参数，它将最终传给返回数据包回调函数。
*Return :
******************************************************/
void FTDAPI_CALL API_SetRecvCallBack(ExchgConnectionHandle conn, ExchgPackageCallBack callback, void * CallBackArg);

/*****************************************************
*Function:	API_SetLoginCallBack
*Summary:	设置收到登录应答时的回调函数
*Parameters:
	conn:交易所连接对象句柄。
	callback:要设置的返回数据包回调函数
	CallBackArg:要设置的返回数据包回调函数的参数，它将最终传给返回数据包回调函数。
*Return :
******************************************************/
void FTDAPI_CALL API_SetLoginCallBack(ExchgConnectionHandle conn, ExchgPackageCallBack callback, void * CallBackArg);

/*****************************************************
*Function:	API_SetLogoutCallBack
*Summary:	设置收到登出应答时的回调函数
*Parameters:
	conn:交易所连接对象句柄。
	callback:要设置的返回数据包回调函数
	CallBackArg:要设置的返回数据包回调函数的参数，它将最终传给返回数据包回调函数。
*Return :
******************************************************/
void FTDAPI_CALL API_SetLogoutCallBack(ExchgConnectionHandle conn, ExchgPackageCallBack callback, void * CallBackArg);

#ifdef __cplusplus
}
#endif /* __cplusplus */ 

#endif

