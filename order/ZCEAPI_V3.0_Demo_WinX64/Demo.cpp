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

//��������
//��¼����
bool ZCELogin(ExchgConnectionHandle conn, short int DFF, const char *ParticipantId, const char *UserId, const char *Password);
//���ڻ��޼۵�
bool Order_LimitPrice(ExchgConnectionHandle conn, const char *ParticipantId, const char *UserId, const char *ClientId);
//������ѯ
bool ReqQryOrder(ExchgConnectionHandle conn, const char *ParticipantId, const char *UserId);
//�ͻ���Ϣ��ѯ
bool ReqQryClient(ExchgConnectionHandle conn, const char *ParticipantId);
//�ɽ������ѯ
bool ReqQryMarketMatchData(ExchgConnectionHandle conn);
//�г�����״̬��ѯ
bool ReqQryMarketStatus(ExchgConnectionHandle conn);
//��Լ��ѯ
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

	//���ûص�����
	ExchgConnectionCallBack OnOpen = OnAPIOpen;
	ExchgConnectionCallBack OnClose = OnAPIClose;
	ExchgConnectionCallBack ErrorCallBack = OnErrors;	//��·״̬����ص�����
	ExchgPackageCallBack LoginCallBack = OnAPILogin;	//�ɹ���¼�Ļص�����
	ExchgPackageCallBack LogoutCallBack = OnAPILogout;	//�˳���¼�Ļص�����
	ExchgPackageCallBack recvCallBack = OnRec;		    //�յ����ݰ��ص�����

	API_BOOL Encrypt = API_TRUE;
	API_BOOL Commpress = API_TRUE;
	MARKET_ID Market_ID = MARKET_ZCE;
	int heart_beat_interval = 20;
	int heart_beat_timeout = 150;
	char IpAddr[20] = "172.20.71.129";       //��������IP��ַ,��218.29.68.231
	int port = 22677;         	//���ӽ������Ķ˿�,��:22577(�Ǽ���),22677(����)

	ExchgConnectionHandle DialogConn = NULL;
	ExchgConnectionHandle PrivateConn = NULL;
	ExchgConnectionHandle BroadcastConn = NULL;

	//�����Ի������Ӷ���
	DialogConn= API_CreateExchgConnection(Encrypt, Commpress, Market_ID, heart_beat_interval, heart_beat_timeout);
	if (DialogConn == NULL)
	{
		std::cout << "Can not create Dialog connection to ZCE��" << std::endl;
		return 0;
	}
	//����˽�������Ӷ���
	PrivateConn = API_CreateExchgConnection(Encrypt, Commpress, Market_ID, heart_beat_interval, heart_beat_timeout);
	if (PrivateConn == NULL)
	{
		std::cout << "Can not create Private connection to ZCE��" << std::endl;
		return 0;
	}
	//�����㲥�����Ӷ���
	BroadcastConn = API_CreateExchgConnection(Encrypt, Commpress, Market_ID, heart_beat_interval, heart_beat_timeout);
	if (BroadcastConn == NULL)
	{
		std::cout << "Can not create Broadcast connection to ZCE��" << std::endl;
		return 0;
	}

	//���ûص�����
	//������·���ӻص�����
	API_SetOpenCallBack(DialogConn, OnOpen, NULL);
	//������·�Ͽ��ص�����
	API_SetCloseCallBack(DialogConn, OnClose, NULL);
	//���õ�¼�ɹ��ص�����
	API_SetLoginCallBack(DialogConn, LoginCallBack, NULL);
	//�����˳��ɹ��ص�����
	API_SetLogoutCallBack(DialogConn, LogoutCallBack, NULL);
	//�����յ����ݰ��ص�����
	API_SetRecvCallBack(DialogConn, recvCallBack, NULL);
	//������·����ص�
	API_SetErrorCallBack(DialogConn, ErrorCallBack, NULL);

	//������·���ӻص�����
	API_SetOpenCallBack(PrivateConn, OnOpen, NULL);
	//������·�Ͽ��ص�����
	API_SetCloseCallBack(PrivateConn, OnClose, NULL);
	//���õ�¼�ɹ��ص�����
	API_SetLoginCallBack(PrivateConn, LoginCallBack, NULL);
	//�����˳��ɹ��ص�����
	API_SetLogoutCallBack(PrivateConn, LogoutCallBack, NULL);
	//�����յ����ݰ��ص�����
	API_SetRecvCallBack(PrivateConn, recvCallBack, NULL);
	//������·����ص�
	API_SetErrorCallBack(PrivateConn, ErrorCallBack, NULL);

	//������·���ӻص�����
	API_SetOpenCallBack(BroadcastConn, OnOpen, NULL);
	//������·�Ͽ��ص�����
	API_SetCloseCallBack(BroadcastConn, OnClose, NULL);
	//���õ�¼�ɹ��ص�����
	API_SetLoginCallBack(BroadcastConn, LoginCallBack, NULL);
	//�����˳��ɹ��ص�����
	API_SetLogoutCallBack(BroadcastConn, LogoutCallBack, NULL);
	//�����յ����ݰ��ص�����
	API_SetRecvCallBack(BroadcastConn, recvCallBack, NULL);
	//������·����ص�
	API_SetErrorCallBack(BroadcastConn, ErrorCallBack, NULL);

	//�����¼�˻���Ϣ
	char ParticipantId[20] = "";    //���׻�Ա����
	char UserId[15] = "";           //����Ա����
	char Password[20] = "";         //����
	char ClientId[10] = "";         //�ͻ����

	//���ӳɹ����¼������,��¼�Ի���
	if (!ZCELogin(DialogConn, 0, ParticipantId, UserId, Password))
	{
		//����Q�˳�
		std::cout << "����Q�˳�����!" << std::endl;
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
		return 0;		//���ɹ���½ʱ,�˳�����
	}
	//���ӳɹ����¼������,��¼˽����
	if (!ZCELogin(PrivateConn, 1, ParticipantId, UserId, Password))
	{
		//����Q�˳�
		std::cout << "����Q�˳�����!" << std::endl;
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
		return 0;		//���ɹ���½ʱ,�˳�����
	}
	//���ӳɹ����¼������,��¼�㲥��
	if (!ZCELogin(BroadcastConn, 2, ParticipantId, UserId, Password))
	{
		//����Q�˳�
		std::cout << "����Q�˳�����!" << std::endl;
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
		return 0;		//���ɹ���½ʱ,�˳�����
	}

	if (!ReqQryMarketStatus(DialogConn))
	{
		return -1;
	}
	if (Order_LimitPrice(DialogConn, ParticipantId, UserId, ClientId))
	{
		std::cout << "���ڻ��޼۵��ɹ�" << std::endl << std::endl;
	}
	else
	{
		std::cout << "���ڻ��޼۵�ʧ��" << std::endl << std::endl;
	}
	
	//�Ͽ����ͷŽ��������Ӷ���
	API_FreeExchgConnection(DialogConn);
	API_FreeExchgConnection(PrivateConn);
	API_FreeExchgConnection(BroadcastConn);

	//ֹͣZCEAPI����
	ftd_api_stop();

	return 0;
}

bool ZCELogin(ExchgConnectionHandle conn, short int DFF, const char *ParticipantId, const char *UserId, const char *Password)
{
	//��¼�����(PID):0x00016
	MsgPackageHandle  APIpkg;       //���ݰ����
	APIpkg = API_AllocPackage();    //����һ��API���ݰ�

	short int	DataFlowFlag = DFF;							//��������,0->�Ի���,1->˽����,2->�㲥��
	char		ConnectionReference[] = " ";				//��·��ʾ,Ŀǰδ��
	char		ServerAppName[] = "ZCE_DEMO_MT";			//��ԱӦ��ϵͳ����
	char		ProtocolVersion[10] = "2";					//ʹ��FTD�汾��,Ŀǰ=2
	int			TimeOut = 10;								//���ͼ���ź�ʱ����,Ŀǰδ��
	char		IpAddr2[20] = "192.168.199.100";			//��¼�ߵ�IP��ַ,��192.168.199.100
	int			SequenceNo = 0;								//��·Ӧ�����к�
	char		INIT_PASSWORD[20] = "12345678";				//�����ʼ��Կ
	char		AUTH_SERIAL_NO[20] = "12345678-12345678";	//���к�:12345678-12345678
	char		AUTH_CODE[20] = "12345678-12345678";		//��Ȩ��:12345678-12345678
	int			FRspSeqNO;									//�������к�
	int         iStart_SeqNo_Prv = 1;						//ϣ�������ΪiStart_SeqNo_Prv+1�����ݰ���ʼ����˽��������
	int         iStart_SeqNo_Brd = 1;						//ϣ�������ΪiStart_SeqNo_Prv+1�����ݰ���ʼ����˽��������
	int			LoginTimeout = 5;

	//������д��½���ݰ�Ȼ���ٽ����Ƿ��ͳ�ȥ(Ŀǰδ�õ��ֶο��Բ���д) 
	API_SetPID(APIpkg, 0x00016);
	API_SFInt(APIpkg, FID_DataFlowFlag, DataFlowFlag);	    //����ʱ�õ���
	API_SFString(APIpkg, FID_ParticipantId, ParticipantId, strlen(ParticipantId));
	API_SFString(APIpkg, FID_UserId, UserId, strlen(UserId));
	API_SFString(APIpkg, FID_Password, Password, strlen(Password));
	API_SFString(APIpkg, FID_IpAddr, IpAddr2, strlen(IpAddr2));
	API_SFString(APIpkg, FID_AUTH_SERIAL_NO, AUTH_SERIAL_NO, strlen(AUTH_SERIAL_NO));
	API_SFString(APIpkg, FID_AUTH_CODE, AUTH_CODE, strlen(AUTH_CODE));
	API_SFString(APIpkg, FID_INIT_PASSWORD, INIT_PASSWORD, strlen(INIT_PASSWORD));
	API_SFString(APIpkg, FID_ProtocolVersion, ProtocolVersion, strlen(ProtocolVersion));
	if (DFF == 0)						//0->�Ի���
		FRspSeqNO = 0;					//�Ի�����¼�������Ϊ0
	else if (DFF == 1)                  //1->˽����
		FRspSeqNO = iStart_SeqNo_Prv;	//ϣ�������ΪiStart_SeqNo_Prv+1�����ݰ���ʼ����˽��������
	else if (DFF == 2)                  //2->�㲥��
		FRspSeqNO = iStart_SeqNo_Brd;	//ϣ�������ΪiStart_SeqNo_Brd+1�����ݰ���ʼ�����㲥������
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
	//����¼������(PID):0x00003
	MsgPackageHandle  APIpkg;       //���ݰ����
	APIpkg = API_AllocPackage();    //����һ��API���ݰ�

	char OrderSysId[20] = "";   //��ͬ��,�µ��ɹ���ϵͳ��д
	char OrderLocaLId[24] = "";  //ί�б�ţ��������������8λ����+8Ϊ���кŵĸ�ʽ��ԭ������Ϊ���ڳ�����Ч�Ķ�����ʹ��ί�б�ſ��Զ�λ���µ�ÿһ��ί��
	short int	Direction = 0;								//		��������,���Բ�������,0->��,1->��,2->����
	short int	OffsetFlag = 0;								//		��ƽ�ֱ��,0->����,1->ƽ��,2->ǿƽ
	short int	HedgeFlag = 1;								//		Ͷ�����,1->Ͷ��,3->���ڱ�ֵ
	double		StopPrice = 0;								//[12]  ֹ��۸�,FTDFloatType<12,4>
	double		LimitPrice = 0;								//[12]  �޼�(��ֹ�𶨵��ı�����),FTDFloatType<12,4>
	int			VolumeTotalOrginal = 5;						//[4]	ԭʼ���걨����(����Ϊ��λ),������������
	short int	OrderType = 0;								//		��������,0->�޼�,1->�м�,3->ֹ��,7->��϶���,101->��������ȷ��,102->�ֲ��ױ�ȷ��,103->���󱨼�,104->��ȨȨ����ʹ,105->����������Ӧ,106->��ȨȨ������
	short int	MatchCondition = 3;							//		�����ɽ�����,1->��ʱȫ���ɽ�,2->��ʱ���ֳɽ�,3->������Ч,4->ȡ��ǰ��Ч,5->ָ������ǰ��Ч
	char		MatchSession = ' ';							//		�����ɽ�ʱ��,Ŀǰδ��
	API_DateTime	ValidThrough;							//[8]	��Чʱ��Լ��,YYYYMMDD
	int			MinimalVolume = 0;							//[4]	��С�ɽ���,������������,Ŀǰδ��
	short int	AutoSuspend = 1;							//		�Զ������־,1->��,0->��
	API_DateTime	InsertTime;								//[20]  ¼��ʱ��,���µ��ɹ�����ϵͳ��д
	char		MessageReference[100] = "�Զ�������";	    //[100]	�û��Զ�������,��ע��Ϣ
	short int	CMBType = 0;								//		��϶�������,0-SPZ,1-SPD,2-IPS,3-BUL,4-BER,5-BLT,6-BRT,7-STD,8-STG,9-PRT
	char		SecondLeg[20] = " ";						//[20]	��϶����ڶ���
	char InstrumentId[20] = "ZC701";  //��Լ���� �ڻ�������Ȩ������

	API_Now(&ValidThrough);
	API_Now(&InsertTime);
	sprintf(OrderLocaLId, "%lld", ++MaxOrderLocalId);
	LimitPrice = 500; 

	//������д�µ��������ݰ�Ȼ���ٽ����Ƿ��ͳ�ȥ(Ŀǰδ�õ��ֶο��Բ���д) 
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

	//���������ݰ�
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

	//�޸���������,ʹ�����Գɽ�
	Direction = 1;
	API_SFInt(APIpkg, FID_Direction, Direction);

	//�޸ı��ض���ί�б��
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

	//�ͷŵ����Ƿ����API���ݰ�����
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
			std::cout << "ϵͳδװ�أ�δ������" << std::endl;
			break;
		}
		case 1:
		{
			std::cout << "ϵͳ���������Ե�¼��" << std::endl;
			ret = true;
			break;
		}
		case 3:
		{
			std::cout << "���̾����뵥��ʼ�׶Σ�" << std::endl;
			ret = true;
			break;
		}
		case 13:
		{
			std::cout << "���̾����뵥�����׶Σ����̼��Ͼ��ۿ�ʼ��" << std::endl;
			ret = true;
			break;
		}
		case 14:
		{
			std::cout << "���̾��۽�����" << std::endl;
			ret = true;
			break;
		}
		case 4: case 9:
		{
			std::cout << "�������׽׶Σ�" << std::endl;
			ret = true;
			break;
		}
		case 5: case 11:
		{
			std::cout << "��ͣ�׶Σ�" << std::endl;
			break;
		}
		case 7: case 10:
		{
			std::cout << "���ױ��У�" << std::endl;
			break;
		}
		case 6:
		{
			std::cout << "ϵͳ����׶�" << std::endl;
			break;
		}
	}
	return ret;
}