#ifndef CALLBACK_H_
#define CALLBACK_H_

#include "FTDAPI.h"

//������·����ص�����,����ʵ����CallBack.cpp�ļ���
void OnAPIOpen(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text);		//��·���ӵĻص�����
void OnAPIClose(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text);	//��·�Ͽ��Ļص�����
void OnErrors(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text);		//����Ļص�����
int OnAPILogin(void * CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg);						//��¼�Ļص�����
int OnAPILogout(void * CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg);						//�˳��Ļص�����
int OnRec(void * CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg);							//�յ����ݰ��Ļص�����

#endif