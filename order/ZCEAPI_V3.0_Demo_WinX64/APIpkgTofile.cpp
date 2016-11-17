//��API���ݰ�д���ļ���,�ļ����ּ��뵱ǰʱ��

#include <iostream>
#include <fstream>
#include "FTDAPI.h"
#include "FieldID.h"

#pragma warning(disable:4996)		//VS2013�º���strcpy�Ȳ���ȫ�ľ���

//���ɱ�����,�������ļ���д������ʱʹ��
const char  FIDName[250][100] = {
    "                                                           ",
    "FID_INIT_PASSWORD            ��·��ʼ����                  ",
    "FID_AUTH_SERIAL_NO           ��Ȩϵ�к�                    ",
    "FID_AUTH_CODE                ��Ȩ��                        ",
    "                                                           ",
    "FID_Chain                    ���������                    ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "FID_Abstract                 ժҪ ˵��                     ",
    "FID_ActionLocalId            �����������ر��              ",
    "FID_ActionType               ִ������                      ",
    "FID_ActiveTime               ����ʱ��                      ",
    "FID_ActiveUserId             ��������Ա����                ",
    "FID_AddValue                 �������������ʽ�              ",
    "FID_AlwDate                  �������������              ",
    "FID_AlwHisDate               ��ʷ�ֲ�ȷ���������          ",
    "FID_AlwQty                   ��׼���� ��������׼����       ",
    "FID_AskLot                   ��������                      ",
    "FID_AskPrice                 ������                        ",
    "FID_AutoSuspend              �Զ������־                  ",
    "FID_AveragePrice             ����                          ",
    "FID_Balance                  �ѽ�������                    ",
    "FID_BalanceValue             ���ñ�֤�����                ",
    "FID_BidLot                   ��������                      ",
    "FID_BidPrice                 ����۸�                      ",
    "FID_BroadcastSequenceNo      �㲥ģʽ�е��������к�        ",
    "FID_BroadcastSequenceSeries  �㲥ģʽ��������            ",
    "FID_BuyHedgeOffsetMargin     ��ƽ�ַ��ر�֤��            ",
    "FID_BuyHedgeOffsetProfit     ��ƽ��ӯ��                  ",
    "FID_BuyHedgeOpenFrozMargin   �򱣿��ֶ��ᱣ֤��            ",
    "FID_BuyHedgeOpenUsedMargin   �򱣿���ʹ�ñ�֤��            ",
    "FID_BuyHedgePosition         �򿪲���(��)                  ",
    "FID_BuyHedgeTurnOver         �򱣳ɽ���                    ",
    "FID_BuyHedgeVolume           ��ɽ���(��)                  ",
    "FID_BuyOffsetFlag            ��ƽ�ֱ�־                  ",
    "FID_BuyOffsHPosition         ��ƽ����(��)                  ",
    "FID_BuyOffsSPosition         ��ƽ����(Ͷ)                  ",
    "FID_BuyPrice                 �򱨼�                        ",
    "FID_BuySpecOffsetMargin      ��Ͷƽ�ַ��ر�֤��            ",
    "FID_BuySpecOffsetProfit      ��Ͷƽ��ӯ��                  ",
    "FID_BuySpecOpenFrozMargin    ��Ͷ���ֶ��ᱣ֤��            ",
    "FID_BuySpecOpenUsedMargin    ��Ͷ����ʹ�ñ�֤��            ",
    "FID_BuySpecPosition          �򿪲���(Ͷ)                  ",
    "FID_BuySpecTurnOver          ��Ͷ�ɽ���                    ",
    "FID_BuySpecVolume            ��ɽ���(Ͷ)                  ",
    "FID_CancelDate               ȡ������                      ",
    "FID_CancelFlag               ��������                      ",
    "FID_CancelTime               ȡ��ʱ��                      ",
    "FID_ClearDate                ��������                      ",
    "FID_ClearPrice               �����                        ",
    "FID_ClientId                 �ͻ�ID                        ",
    "FID_ClientName               �ͻ�����                      ",
    "FID_ClientType               �ͻ����                      ",
    "FID_ClosePrice               ���̼�                        ",
    "FID_CmbType                  ��϶�������                  ",
    "FID_ComeFrom                 ��Ϣ��Դ                      ",
    "FID_ConnectionReference      ��·��ʾ                      ",
    "FID_Content                  ��Ϣ����                      ",
    "FID_Currency                 �����õĻ���                  ",
    "FID_DealQty                  �ɹ���������                  ",
    "FID_DealStatus               ����״̬                      ",
    "FID_DelValue                 ������������ʽ�              ",
    "FID_DeriveAskLot             �����������                  ",
    "FID_DeriveAskPrice           ���������                    ",
    "FID_DeriveBidLot             �����������                  ",
    "FID_DeriveBidPrice           ��������                    ",
    "FID_Direction                ��������                      ",
    "FID_EndDelvDate              ��󽻸���                    ",
    "FID_EndTrdDate               �����                      ",
    "FID_ErrorCode                �������                      ",
    "FID_ErrorText                ��������                      ",
    "FID_ExchangeDateTime         ������ϵͳʱ��                ",
    "FID_Forcedistime             ǿƽ�Ĵ�ϼ��                ",
    "FID_ForceExitCode            ǿ���˳���                    ",
    "FID_ForceExitMsg             ǿ���˳�ԭ��                  ",
    "FID_ForceGroupId             ǿƽ���                      ",
    "FID_FuseFlag                 �۶ϱ��                      ",
    "FID_Fuselimit                �۶��޶�                      ",
    "FID_Fusepersisttime          �۶�������ʱ��              ",
    "FID_Fusepoint                �ڸ�ʱ���󲻿��۶�          ",
    "FID_FuseRights               �ɷ��۶�                      ",
    "FID_HedgeDate                ��������                      ",
    "FID_HedgeFlag                Ͷ�����                      ",
    "FID_HighLimit                ��ͣ��                        ",
    "FID_HighLimitRate            ��ͣ����                      ",
    "FID_HighPrice                ��߼�                        ",
    "FID_HoldQty                  �ֲ�����                      ",
    "FID_InitMargin               ��ʼ��֤��                    ",
    "FID_InsertTime               ¼��ʱ��                      ",
    "FID_InstrStopCode            ֹͣ����ԭ��                  ",
    "FID_InstrumentId             ��Լ����                      ",
    "FID_InstrumentName           ��Լ����                      ",
    "FID_InstrumentStatus         ��Լ����״̬                  ",
    "FID_InstrumentType           ��Լ����                      ",
    "FID_InstrumentVersion        ��Լ�汾��                    ",
    "FID_IpAddr                   ��¼�ߵ�IP��ַ                ",
    "FID_LastLot                  ���һ�ʳɽ�����              ",
    "FID_LastPrice                ���¼�                        ",
    "FID_LifeHigh                 ��ʷ��߳ɽ��۸�              ",
    "FID_LifeLow                  ��ʷ��ͳɽ��۸�              ",
    "FID_LimitPrice               �޼ۣ���ֹ�𶨵��ı����ۣ�    ",
    "FID_LongOffsFrozHPosition    ��ͷƽ�ֶ���ֲ���(��)        ",
    "FID_LongOffsFrozSPosition    ��ͷƽ�ֶ���ֲ���(Ͷ)        ",
    "FID_LongOpenFrozHPosition    ��ͷ���ֶ���ֲ��֣�����      ",
    "FID_LongOpenFrozSPosition    ��ͷ���ֶ���ֲ��֣�Ͷ��      ",
    "FID_LowLimit                 ��ͣ��                        ",
    "FID_LowLimitRate             ��ͣ����                      ",
    "FID_LowPrice                 ��ͼ�                        ",
    "FID_Margin                   ��֤��                        ",
    "FID_MarketId                 �г�����                      ",
    "FID_MarketMatchDataStatus    �Ƿ��������ͳɽ�����          ",
    "FID_MarketName               �г�����                      ",
    "FID_MarketStatusId           �г�����״̬                  ",
    "FID_MatchCondition           �����ɽ�����                  ",
    "FID_MatchDate                �ɽ�����                      ",
    "FID_MatchSession             �����ɽ�ʱ��                  ",
    "FID_MatchTime                �ɽ�ʱ��                      ",
    "FID_MaxLot                   �����µ�����                ",
    "FID_MaxOrderLocalId          ���ɹ��������ر��          ",
    "FID_MessageReference         �û��Զ�������                ",
    "FID_MinimalVolume            ��С�ɽ���                    ",
    "FID_MinLot                   ��С���µ�����                ",
    "FID_NewPassword              �¿���                        ",
    "FID_NewsType                 ��Ϣ����                      ",
    "FID_NewsUrgency              �����̶�                      ",
    "FID_OffsetFlag               ��ƽ�ֱ��                    ",
    "FID_OldPassword              �ɿ���                        ",
    "FID_OpenInterest             �ֲ���                        ",
    "FID_OpenPrice                ���̼�                        ",
    "FID_OpenQty                  �ѽ�������                    ",
    "FID_OrderActionCode          ��������������                ",
    "FID_OrderCMBType             ��������:��λ����             ",
    "FID_OrderDate                ��������                      ",
    "FID_OrderLocalId             ί�б��                      ",
    "FID_OrderStatus              ����״̬                      ",
    "FID_OrderStatus2             ����״̬                      ",
    "FID_OrderSysId               ��ͬ���                      ",
    "FID_OrderType                ��������                      ",
    "FID_ParticipantId            ���׻�Ա����                  ",
    "FID_ParticipantName          ��Ա����                      ",
    "FID_ParticipantType          ��Ա����                      ",
    "FID_PartiTrdRight            ��ԱȨ��                      ",
    "FID_Password                 ����                          ",
    "FID_PreClose                 ǰ���̼۸�                    ",
    "FID_PreOpenInterest          ���տ�����                    ",
    "FID_PreSettle                ǰ����۸�                    ",
    "FID_Price                    �۸�                          ",
    "FID_ProtocolVersion          ʹ��FTD�汾��                 ",
    "FID_Pubstyle                 ���۽׶κ�Լ���鷢����ʽ      ",
    "FID_Qty                      ��������                      ",
    "FID_RemainQty                ʣ���� (�ɽ�������)         ",
    "FID_ReqDate                  ���뽨�ֿ�ʼ����              ",
    "FID_ReqQty                   �������� ��Ա��������         ",
    "FID_ReqSeqNum                �����������к�                ",
    "FID_RequestBy                ����(0->һ���Ա��1->������)",
    "FID_ResponseTime             ������Ӧʱ��                  ",
    "FID_SecondLeg                ��϶����ڶ���                ",
    "FID_SellHedgeOffsetMargin    ����ƽ�ַ��ر�֤��            ",
    "FID_SellHedgeOffsetProfit    ����ƽ��ӯ��                  ",
    "FID_SellHedgeOpenFrozMargin  �������ֶ��ᱣ֤��            ",
    "FID_SellHedgeOpenUsedMargin  ��������ʹ�ñ�֤��            ",
    "FID_SellHedgePosition        ��������(��)                  ",
    "FID_SellHedgeTurnOver        �����ɽ���                    ",
    "FID_SellHedgeVolume          ���ɽ���(��)                  ",
    "FID_SellOffsetFlag           ����ƽ�ֱ�־                  ",
    "FID_SellOffsHPosition        ��ƽ����(��)                  ",
    "FID_SellOffsSPosition        ��ƽ����(Ͷ)                  ",
    "FID_SellPrice                ������                        ",
    "FID_SellSpecOffsetMargin     ��Ͷƽ�ַ��ر�֤��            ",
    "FID_SellSpecOffsetProfit     ��Ͷƽ��ӯ��                  ",
    "FID_SellSpecOpenFrozMargin   ��Ͷ���ֶ��ᱣ֤��            ",
    "FID_SellSpecOpenUsedMargin   ��Ͷ����ʹ�ñ�֤��            ",
    "FID_SellSpecPosition         ��������(Ͷ)                  ",
    "FID_SellSpecTurnOver         ��Ͷ�ɽ���                    ",
    "FID_SellSpecVolume           ���ɽ���(Ͷ)                  ",
    "FID_SendTime                 ����ʱ��                      ",
    "FID_SequenceNo               ���к�                        ",
    "FID_SequenceSeries           ��DataFlowFlag ��������     ",
    "FID_ServerAppName            ��ԱӦ��ϵͳ����              ",
    "FID_SettleFlag               0������ 1��ƽ��               ",
    "FID_SettlePrice              ���ս�������                ",
    "FID_ShortCutKey              �����ݼ�                    ",
    "FID_ShortOffsFrozHPosition   ��ͷƽ�ֶ���ֲ���(��)        ",
    "FID_ShortOffsFrozSPosition   ��ͷƽ�ֶ���ֲ���(Ͷ)        ",
    "FID_ShortOpenFrozHPosition   ��ͷ���ֶ���ֲ��֣�����      ",
    "FID_ShortOpenFrozSPosition   ��ͷ���ֶ���ֲ��֣�Ͷ��      ",
    "FID_SpdDate                  ��ʼ����                      ",
    "FID_SpdEndDate               ��������                      ",
    "FID_StartDelvDate            ��ʼ������                    ",
    "FID_StartTime                ��ʼʱ��                      ",
    "FID_StartTrdDate             ��ʼ������                    ",
    "FID_StayTime                 �趨ͣ��ʱ��(��)              ",
    "FID_StopPrice                ֹ��۸�                      ",
    "FID_SuspendTime              ����ʱ��                      ",
    "FID_ThroughTime              ֱ��ʱ��                      ",
    "FID_Tick                     ��С�䶯��λ                  ",
    "FID_TimeOut                  ���ͼ���ź�ʱ����          ",
    "FID_TimeSpan                 ʱ��                          ",
    "FID_TimeStamp                ʱ���                        ",
    "FID_TotalMarketMatchData     ���ͳɽ������¼����          ",
    "FID_TotalVolume              �ܳɽ���                      ",
    "FID_TradeDate                ����ί������                  ",
    "FID_TradeId                  �ɽ����                      ",
    "FID_TradeLot                 �ܳɽ�����                    ",
    "FID_TradePrice               ���³ɽ��۸�                  ",
    "FID_TradeRights              ����Ȩ��                      ",
    "FID_TradeTurnover            �ܳɽ����                    ",
    "FID_TradeType                �г���������                  ",
    "FID_TradeVolume              ��ɽ���                      ",
    "FID_Unbalance                δ��������                    ",
    "FID_Unit                     ÿ�ֳ���                      ",
    "FID_UpdateTime               ����޸�ʱ��                  ",
    "FID_URLLink                  ����Ϣ��WEB����               ",
    "FID_UserId                   ����Ա����                    ",
    "FID_ValidThrough             ��Чʱ��Լ��                  ",
    "FID_VirtualQty               �ɽ�������,                   ",
    "FID_VolAskLot                ����������,                   ",
    "FID_VolBidLot                ����������,                   ",
    "FID_Volume                   ����                          ",
    "FID_VolumeTotal              ʣ�����걨����������Ϊ��λ��  ",
    "FID_VolumeTotalOrginal       ԭʼ���걨����������Ϊ��λ��  ",
    "FID_WDTime                   ����ʱ��                      ",
    "FID_YdBuyHedgePosition       ǰ��ֲ���(��)                ",
    "FID_YdBuyOffsHPosition       ��ƽ����(��)                  ",
    "FID_YdBuyOffsSPosition       ��ƽ����(Ͷ)                  ",
    "FID_YdBuySpecPosition        ǰ��ֲ���(Ͷ)                ",
    "FID_YdLongOffsFrozHPosition  ���ն�ͷƽ�ֶ���ֲ���(��)    ",
    "FID_YdLongOffsFrozSPosition  ���ն�ͷƽ�ֶ���ֲ���(Ͷ)    ",
    "FID_YdSellHedgePosition      ǰ���ֲ���(��)                ",
    "FID_YdSellOffsHPosition      ��ƽ����(��)                  ",
    "FID_YdSellOffsSPosition      ��ƽ����(Ͷ)                  ",
    "FID_YdSellSpecPosition       ǰ���ֲ���(Ͷ)                ",
    "FID_YdShortOffsFrozHPosition ���տ�ͷƽ�ֶ���ֲ���(��)    ",
    "FID_YdShortOffsFrozSPosition ���տ�ͷƽ�ֶ���ֲ���(Ͷ)    "
};

//�������ݰ���PID�õ����ݰ���ҵ������,��PID�����ڻ���PID���Ϸ�,�򷵻ز����ڵ����ݰ�
void getBussinessname(char * Business, int PID)
{
    switch (PID)
    {
    case   0x00016:  strcpy(Business, "$00016 ����Ա��¼����"); break;
    case   0x10016:	 strcpy(Business, "$10016 ����Ա��¼Ӧ��"); break;
    case   0x00017:  strcpy(Business, "$00017 ����Ա�˳���¼����"); break;
    case   0x10017:  strcpy(Business, "$10017 ����Ա�˳���¼Ӧ��"); break;
    case   0x00018:  strcpy(Business, "$00018 ����Ա�޸���������"); break;
    case   0x10018:  strcpy(Business, "$10018 ����Ա�޸�����Ӧ��"); break;

    case   0x03003:  strcpy(Business, "$03003 �����̱�����Ӧ¼������"); break;
    case   0x13003:  strcpy(Business, "$13003 �����̱�����Ӧ¼��Ӧ��"); break;

    case   0x00003:  strcpy(Business, "$00003 ����¼������"); break;
    case   0x10003:  strcpy(Business, "$10003 ����¼��Ӧ��"); break;
    case   0x00004:  strcpy(Business, "$00004 ������������"); break;
    case   0x10004:  strcpy(Business, "$10004 ��������Ӧ��"); break;
    case   0x00006:  strcpy(Business, "$00006 ������ѯ����"); break;
    case   0x10006:  strcpy(Business, "$10006 ������ѯӦ��"); break;

    case   0x03010:	 strcpy(Business, "$03010 ���������ͱ�����ѯ����"); break;
    case   0x13010:	 strcpy(Business, "$13010 ���������ͱ�����ѯӦ��"); break;
    case   0x03013:  strcpy(Business, "$03013 �����ض����ű�����ѯ����"); break;
    case   0x13013:  strcpy(Business, "$13013 �����ض����ű�����ѯӦ��"); break;
    case   0x03046:  strcpy(Business, "$03046 ���仯��������ѯ����");  break;
    case   0x13046:  strcpy(Business, "$13046 ���仯��������ѯӦ��"); break;

    case   0x03017:  strcpy(Business, "$03017 ���ڱ�ֵ��Ȳ�ѯ����"); break;
    case   0x13017:  strcpy(Business, "$13017 ���ڱ�ֵ��Ȳ�ѯӦ��"); break;
    case   0x03018:  strcpy(Business, "$03018 ���ڱ�ֵȷ�ϲ�ѯ����");  break;
    case   0x13018:  strcpy(Business, "$13018 ���ڱ�ֵȷ�ϲ�ѯӦ��"); break;
    case   0x03019:  strcpy(Business, "$03019 ����������Ȳ�ѯ����"); break;
    case   0x13019:  strcpy(Business, "$13019 ����������Ȳ�ѯӦ��"); break;
    case   0x03020:  strcpy(Business, "$03020 ��������ȷ�ϲ�ѯ����"); break;
    case   0x13020:  strcpy(Business, "$13020 ��������ȷ�ϲ�ѯӦ��"); break;

    case   0x03026:  strcpy(Business, "$03026 �����̱�����Ӧ��ѯ����"); break;
    case   0x13026:  strcpy(Business, "$13026 �����̱�����Ӧ��ѯӦ��"); break;

    case   0x03025:  strcpy(Business, "$03025 ��Ȩִ�в�ѯ����"); break;
    case   0x13025:  strcpy(Business, "$13025 ��Ȩִ�в�ѯӦ��"); break;

    case   0x0000B:  strcpy(Business, "$0000B �г���ѯ����"); break;
    case   0x1000B:  strcpy(Business, "$1000B �г���ѯӦ��"); break;
    case   0x0000D:  strcpy(Business, "$0000D �г�����״̬��ѯ����"); break;
    case   0x1000D:  strcpy(Business, "$1000D �г�����״̬��ѯӦ��"); break;

    case   0x00005:  strcpy(Business, "$00005 ��Լ��ѯ����"); break;
    case   0x10005:  strcpy(Business, "$10005 ��Լ��ѯӦ��"); break;
    case   0x0000E:  strcpy(Business, "$0000E Ʒ�ֽ���״̬��ѯ����"); break;
    case   0x1000E:  strcpy(Business, "$1000E Ʒ�ֽ���״̬��ѯӦ��"); break;
    case   0x03015:  strcpy(Business, "$03015 ��Ϻ�Լ��ѯ����"); break;
    case   0x13015:  strcpy(Business, "$13015 ��Ϻ�Լ��ѯӦ��"); break;

    case   0x0000C:  strcpy(Business, "$0000C �ͻ���Ϣ��ѯ����"); break;
    case   0x1000C:  strcpy(Business, "$0000C �ͻ���Ϣ��ѯӦ��"); break;

    case   0x00008:  strcpy(Business, "$00008 ��Ա�ʽ��ѯ����"); break;
    case   0x10008:  strcpy(Business, "$10008 ��Ա�ʽ��ѯӦ��"); break;

    case   0x00002:  strcpy(Business, "$00002 �ɽ������ѯ����"); break;
    case   0x10002:  strcpy(Business, "$10002 �ɽ������ѯӦ��"); break;
    case   0x00007:  strcpy(Business, "$00007 ����ͬ��ųɽ���Լ��ѯ����"); break;
    case   0x10007:  strcpy(Business, "$10007 ����ͬ��ųɽ���Լ��ѯӦ��"); break;
    case   0x03014:  strcpy(Business, "$03014 ���ɽ���ųɽ���Լ��ѯ����"); break;
    case   0x13014:  strcpy(Business, "$13014 ���ɽ���ųɽ���Լ��ѯӦ��"); break;

    case   0x00009:  strcpy(Business, "$00009 ��Ա�ֲֲ�ѯ����"); break;
    case   0x10009:  strcpy(Business, "$10009 ��Ա�ֲֲ�ѯӦ��"); break;
    case   0x0000A:  strcpy(Business, "$0000A ��Ա�ͻ��ֲֲ�ѯ����"); break;
    case   0x1000A:  strcpy(Business, "$1000A ��Ա�ͻ��ֲֲ�ѯӦ��"); break;
    case   0x03031:  strcpy(Business, "$03031 ��Ա�ͻ���ϳֲֲ�ѯ����"); break;
    case   0x13031:  strcpy(Business, "$13031 ��Ա�ͻ���ϳֲֲ�ѯӦ��"); break;

    case   0x10001:  strcpy(Business, "$10001 ������Ӧ"); break;
    case   0x12007:  strcpy(Business, "$12007 ��Լ�����ı�֪ͨ"); break;
    case   0x12006:  strcpy(Business, "$12006 Ʒ��״̬�ı�֪ͨ"); break;
    case   0x12003:  strcpy(Business, "$12003 ��������ʾ�㲥"); break;
    case   0x12004:  strcpy(Business, "$12004 �ɽ�����"); break;
    case   0x13016:  strcpy(Business, "$13016 �������"); break;
    case   0x12005:  strcpy(Business, "$12005 �г�״̬�ı�֪ͨ"); break;
    case   0x13002:  strcpy(Business, "$13002 ��������"); break;

    case   0x11003:  strcpy(Business, "$11003 ����״̬ȷ��"); break;
    case   0x13041:  strcpy(Business, "$13041 ��������ȷ��"); break;
    case   0x13040:  strcpy(Business, "$13040 ���ڱ�ֵȷ��"); break;
    case   0x13042:  strcpy(Business, "$13042 ��Ȩִ��ȷ��"); break;

    case   0x11001:  strcpy(Business, "$11001 ���߳ɽ��ر�"); break;
    default:		 strcpy(Business, "�����ڵ����ݰ�"); break;
    }
}

//������һ��API���ݰ�����һ���ĸ�ʽ���浽�ļ���,direction����������(0�Ƿ���,1�ǽ���,����Ϊ����¼�˱�־)
void APIpkgTofile(MsgPackageHandle pkg, int direction)
{
    char		DirectionStr[10] = "";  //����������,�Ƿ��ͻ��ǽ���
    char		DataFlowName[10] = "";  //��������
    char		filepath[50];           //�ļ�Ŀ¼
    char		filename[1024];         //�ļ���
    int			PID;                    //API���ݰ���PID
    int			FID;                    //API���ݰ���FID
    char		Business[128];          //���ݰ�����
    const int	BS = 1024 * 16;         //Ҫд�뵽�ļ��е����ݴ�С.�����е���
    char		buffer[BS];             //Ҫд���ļ��е�����,��¼���������ʱ����
    int 		it;                     //ָ��ǰbuffer�Ľ�β��(�洢buffer����)

    //���ȡ������ʱ����
    char		    fvchar;
    int			    fvint;
    double		    fvdouble;
    char		    fvstring[1024];
    int			    fvstringlen;
    API_DateTime	fvdt;

    switch (direction)
    {
    case 0:
    {
        strcpy(DirectionStr, "����");
        break;
    }
    case 1:
    {
        strcpy(DirectionStr, "����");
        break;
    }
    }

    //ȡ����������־
    switch (API_GFInt(pkg, FID_DataFlowFlag))
    {
    case 0:
    {
        strcpy(DataFlowName, "�Ի���");
        break;
    }
    case 1:
    {
        strcpy(DataFlowName, "˽����");
        break;
    }
    case 2:
    {
        strcpy(DataFlowName, "�㲥��");
        break;
    }
    }

    //���潫API���ݰ��е����ݶ��������д���Ȼ��ŵ���Ӧ���ļ���
    PID = API_GetPID(pkg);				//ȡ�����ݰ�PID
    getBussinessname(Business, PID);	//����PIDȡ�����ݰ���������
    API_DateTime dt;					//�洢��ǰʱ��Ķ���
    API_Now(&dt);                       //��ȡʱ��,�õ�API�ӿں���

    //����·��
    sprintf(filepath, "%s", "./Record/");

    //�����������ļ���
    sprintf(filename, "%s%d-%d-%d %d.%d.%d %s %s %s%s", filepath, dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second, DataFlowName, DirectionStr, Business, ".txt");

    //���洴���ļ�
    std::ofstream f;
    f.open(filename, std::ios::app);
    if (f.fail())
    {
        std::cout << "Fail in opening file!" << std::endl;
        return;
    }

    //�����ݰ���д��
    it = sprintf(buffer, "------------------------- ����PID��%s -------------------------\n", Business);

    //����õ����ݰ�������
    FID = API_FirstField(pkg);  //�õ����ݰ��е�һ��FID
    if (FID > 0)                //��������ʱΪ��
    {
        do{
            switch (API_CFType(pkg))
            {
            case FTCHAR:
            {
                fvchar = API_CFChar(pkg);
                if (isprint(fvchar))	//���ǿɴ�ӡ�ַ�
                    it += sprintf(buffer + it, "%s %c\n", FIDName[FID - 1], fvchar);
                else					//�ǿɴ�ӡ�ַ���16������ʽ���
                    it += sprintf(buffer + it, "%s 0x%x\n", FIDName[FID - 1], fvchar);
                break;
            }
            case FTLONG:
            {
                fvint = API_CFInt(pkg);
                it += sprintf(buffer + it, "%s %d\n", FIDName[FID - 1], fvint);
                break;
            }
            case FTSTRING:
            {
                fvstringlen = API_CFString(pkg, fvstring, 856);
                if (fvstringlen > 0)
                    fvstring[fvstringlen] = '\0';
                else
                    fvstring[0] = '\0';
                it += sprintf(buffer + it, "%s %s\n", FIDName[FID - 1], fvstring);
                break;
            }
            case FTDOUBLE:
            {
                fvdouble = API_CFDouble(pkg);
                it += sprintf(buffer + it, "%s %f\n", FIDName[FID - 1], fvdouble);
                break;
            }
            case FTDATETIME:
            {
                if (API_CFDT(pkg, &fvdt) != API_TRUE)
                    it += sprintf(buffer + it, "%s %s", FIDName[FID - 1], "ȡʱ�����\n");
                else
                    it += sprintf(buffer + it, "%s %d-%d-%d %d:%d:%d \n", FIDName[FID - 1], fvdt.year, fvdt.month, fvdt.day, fvdt.hour, fvdt.minute, fvdt.second);
                break;
            }
            default: it += sprintf(buffer + it, "%s %s", FIDName[FID - 1], "δ֪���ͣ�\n");
            }
            FID = API_NextField(pkg);
        } while (FID > 0);  //һֱѭ����û��������
    }
    //���潫bufferд���ļ�
    size_t len = strlen(buffer);
    f.write(buffer, len);
    f.close();
}