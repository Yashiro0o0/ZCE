#ifndef CALLBACK_H_
#define CALLBACK_H_

#include "FTDAPI.h"

//声明链路出错回调函数,函数实体在CallBack.cpp文件中
void OnAPIOpen(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text);		//链路连接的回调函数
void OnAPIClose(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text);	//链路断开的回调函数
void OnErrors(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text);		//出错的回调函数
int OnAPILogin(void * CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg);						//登录的回调函数
int OnAPILogout(void * CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg);						//退出的回调函数
int OnRec(void * CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg);							//收到数据包的回调函数

#endif