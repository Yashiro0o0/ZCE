#include <iostream>
#include <string>
#include "CallBack.h"
#include "FieldID.h"

//ȫ�ֱ���
extern long long MaxOrderLocalId;   //�����洢������󶨵���
extern int MarketStatus;            //�г�״̬
extern double SR503_LimitUpPrice;   //SR503����ͣ��
extern double SR503_LimitDownPrice; //SR503�ĵ�ͣ��

//������һ��API���ݰ�����һ���ĸ�ʽ���浽�ļ���,direction����������(0�Ƿ���,1�ǽ���,����Ϊ����¼�˱�־)
void APIpkgTofile(MsgPackageHandle pkg, int direction);

//��¼�Ļص�����
int OnAPILogin(void * CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg)
{
	//�ж��Ƿ��¼�ɹ�
	if (API_FieldIsNull(pkg, FID_ErrorCode))
	{
		std::cout << "��¼�ɹ���" << std::endl;
	}
	else
	{
		std::cout << "��¼ʧ��";
		char errorCode[20];
		API_GFString(pkg, FID_ErrorCode, errorCode,10);
		std::cout << "������Ϊ��" << errorCode << std::endl;
	}

	//���ñ������ί�б��
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

//�˳��Ļص�����
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

//��·���ӵĻص�����
void OnAPIOpen(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text)
{
    if (error_code == 0)
    {
        std::cout << error_text << std::endl;
    }
    else
    {
        std::cout << "�������:" << error_code << "    " << "��������:" << error_text << std::endl;
    }
}

//��·�Ͽ��Ļص�����
void OnAPIClose(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text)
{
    if (error_code == 0)
    {
        std::cout << error_text << std::endl;
    }
    else
    {
        std::cout << "�������:" << error_code << "    " << "��������:" << error_text << std::endl;
    }
}

//�յ����ݰ��Ļص�����
int OnRec(void * CallBackArg, ExchgConnectionHandle conn, MsgPackageHandle pkg)
{

    if (API_GetPID(pkg) == 0x10002)
    {
        //��ȡSR503���ǵ�ͣ��
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

//����Ļص�����
void OnErrors(void * CallBackArg, ExchgConnectionHandle conn, int error_code, const char* error_text)
{
    std::cout << "�������:" << error_code << "    " << "��������:" << error_text << std::endl;
}