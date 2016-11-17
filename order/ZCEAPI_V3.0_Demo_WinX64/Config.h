/**************************************************
Copyright:ESUNNY
Author: ZZY
Date:2014-08-011
Description:Config.h，ZCEAPI类型和常量声明文件。
Note:请不要修改该文件
*************************************************/

#ifndef CONFIG_H_
#define CONFIG_H_

#include <limits.h>

//以下定义根据编译器不同可能需要修改
#ifdef WIN32//windows平台定义
	//调用约定
	#define FTDAPI_CALL __cdecl
#else//Linux平台定义
	#define FTDAPI_CALL 
#endif 

#ifndef NULL
#define NULL 0
#endif

typedef unsigned short int API_UINT16;
typedef unsigned char API_BYTE;
typedef	unsigned int API_UINT32;

//日期类型
#pragma pack(push,1)

typedef struct tagDateTime
{
	API_UINT16 year;
	API_BYTE  month, day, hour, minute, second;
	API_UINT32 microsec;
}API_DateTime;

#pragma pack(pop)

typedef int API_BOOL;
#define API_TRUE	1
#define API_FALSE	0

/*线程模型*/
typedef int THREAD_MODE;
#define MULTI_THREAD_MODE 1

/*建立连接时是否阻塞*/
#define CONNECT_WAIT 1
#define CONNECT_NO_WAIT 0

/*交易所*/
typedef int MARKET_ID;
#define MARKET_ZCE 1

//域类型
typedef int API_FIELDTYPE;
#define	FTNULL			0 
#define	FTCHAR			1
#define	FTLONG			2
#define	FTSTRING		3
#define	FTDOUBLE		4
#define	FTDATETIME		5

//数据流标示
typedef int API_DFFLAG;
#define DFF_DIALOG		0		//对话流
#define DFF_PRIVATE		1		//私有流
#define DFF_PUBLISH		2		//广播流

//数据流状态常数
typedef int API_DFSTATUS;
#define DFS_CLOSED 0		//连接断开
#define DFS_OPENED 1		//刚刚建立连接
#define DFS_NEGOTIATEKEY 2	//刚刚协商密钥，还没有登录
#define DFS_LOGIN_OK     3	//已经登录成功

class MsgPackage;
class ExchangeConnection;
/*数据包句柄*/
typedef MsgPackage* MsgPackageHandle;
/*交易所连接对象句柄*/
typedef ExchangeConnection* ExchgConnectionHandle;

/*包含数据的回调函数,客户程序的返回值决定API对此数据包的后续处理方式
*返回0:API将此数据包放入接收数据包队列，客户可以调用Recv再次取得此包
*返回非0:API将此数据包销毁
*/
typedef int (FTDAPI_CALL*ExchgPackageCallBack)(void * CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg);
/*连接状态的回调函数*/
typedef void (FTDAPI_CALL*ExchgConnectionCallBack)(void * CallBackArg, ExchgConnectionHandle, int error_code, const char* error_text);

#endif

