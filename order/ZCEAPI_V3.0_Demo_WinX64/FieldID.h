#ifndef FIELDID_H_
#define FIELDID_H_

//FieldID.h
//APIԪ����ID�����ﶨ��

//Э����Կ
#define PID_INVALIDPID 0xFFFFF
#define PID_NEGOTIATEDESKEY_REQ 0x00000
#define PID_NEGOTIATEDESKEY_RSP 0x10000
//��¼����
#define PID_LOGIN_REQ 0x00016
#define PID_LOGIN_RSP 0x10016
//�˳���¼����
#define PID_LOGOUT_REQ 0x00017 
#define PID_LOGOUT_RSP 0x10017

#define FID_Abstract					16		//[80] /*ժҪ/˵�� Ŀǰδ��*/ 
#define FID_ActionLocalId				17			//[24] /*�����������ر��*/ 
#define FID_ActionType					18		//    /* ִ�����ͣ�'E'-ִ��(OPTION_EXEC)��'C'-����(OPTION_ABANDON)*/
#define FID_ActiveTime					19		//[8]  /*����ʱ��*/ 
#define FID_ActiveUserId				20			//[15] /*��������Ա����*/ 
#define FID_AddValue					21		//[14]   /*�������������ʽ�,FTDFloatType<14,2>*/ 
#define FID_AlwDate						22	//[8]   /*�������������*/
#define FID_AlwHisDate					23		//[8]  /*��ʷ�ֲ�ȷ��������� AlwHisDate<=AlwDate*/
#define FID_AlwQty						24	//[4] /*��׼���� ��������׼����,������������*/
#define FID_AskLot						25	//[4]  /*��������,������������*/ 
#define FID_AskPrice					26		//[12] /*������,FTDFloatType<12,4>*/ 
#define FID_AutoSuspend					27		//  /*�Զ������־ 1->��,0->��*/
#define FID_AveragePrice				28			//[12] /*����,FTDFloatType<12,4>*/ 
#define FID_Balance						29	//[4]  /*�ѽ�������,������������*/
#define FID_BalanceValue				30			//[14]  /*���ñ�֤�����,FTDFloatType<14,2>*/ 
#define FID_BidLot						31	//[4]  /*��������,������������*/ 
#define FID_BidPrice					32		//[12] /*����۸�,FTDFloatType<12,4>*/ 
#define FID_BroadcastSequenceNo			33				//[4] /*�㲥ģʽ�е��������к�,������������*/ 
#define FID_BroadcastSequenceSeries		34					//[2] /*�㲥ģʽ��������,������������*/ 
#define FID_BuyHedgeOffsetMargin		35					//[14] /*��ƽ�ַ��ر�֤��,FTDFloatType<14,2>*/ 
#define FID_BuyHedgeOffsetProfit		36					//[14] /*��ƽ��ӯ��,FTDFloatType<14,2>*/ 
#define FID_BuyHedgeOpenFrozMargin		37					//[14] /*�򱣿��ֶ��ᱣ֤��,FTDFloatType<14,2>*/ 
#define FID_BuyHedgeOpenUsedMargin		38					//[14] /*�򱣿���ʹ�ñ�֤��,FTDFloatType<14,2>*/ 
#define FID_BuyHedgePosition			39				//[4] /*�򿪲���(��),������������*/ 
#define FID_BuyHedgeTurnOver			40				//[14] /*�򱣳ɽ���,FTDFloatType<14,2>*/ 
#define FID_BuyHedgeVolume				41			//[4]  /*��ɽ���(��),������������*/ 
#define FID_BuyOffsetFlag 				42			//  /*��ƽ�ֱ�־  0������ 1��ƽ��*/
#define FID_BuyOffsHPosition			43				//[4] /*��ƽ����(��),������������*/ 
#define FID_BuyOffsSPosition			44				//[4] /*��ƽ����(Ͷ),������������*/ 
#define FID_BuyPrice 					45		//[12]  /*�򱨼�,FTDFloatType<12,4>*/
#define FID_BuySpecOffsetMargin			46				//[14] /*��Ͷƽ�ַ��ر�֤��,FTDFloatType<14,2>*/ 
#define FID_BuySpecOffsetProfit			47				//[14] /*��Ͷƽ��ӯ��,FTDFloatType<14,2>*/ 
#define FID_BuySpecOpenFrozMargin		48					//[14] /*��Ͷ���ֶ��ᱣ֤��,FTDFloatType<14,2>*/ 
#define FID_BuySpecOpenUsedMargin		49					//[14] /*��Ͷ����ʹ�ñ�֤��,FTDFloatType<14,2>*/ 
#define FID_BuySpecPosition				50			//[4]  /*�򿪲���(Ͷ),������������*/ 
#define FID_BuySpecTurnOver				51			//[14] /*��Ͷ�ɽ���,FTDFloatType<14,2>*/ 
#define FID_BuySpecVolume				52			//[4]  /*��ɽ���(Ͷ),������������*/ 
#define FID_CancelDate					53		//[8]  /*ȡ������ Ŀǰδ��*/
#define FID_CancelFlag					54		//   /*�������� 0->��ͨ������1->ֹ�𶨵���2->��϶���*/
#define FID_CancelTime					55		//[8]  /*ȡ��ʱ�� Ŀǰδ��*/
#define FID_ClearDate					56		//[8]  /*�������� Ŀǰδ��*/
#define FID_ClearPrice					57		//[12]  /*����� ,FTDFloatType<12,4>*/ 
#define FID_ClientId					58		//[8] 
#define FID_ClientName					59		//[80] /*�ͻ�����*/ 
#define FID_ClientType					60		//  /*�ͻ���� Ŀǰδ��*/
#define FID_ClosePrice					61		//[12]  /*���̼�,FTDFloatType<12,4>*/ 
#define FID_CmbType						62	//     /*��϶������ͣ�0-SPZ 1-SPD 2-IPS 3-BUL 4-BER 5-BLT 6-BRT 7-STD 8-STG 9-PRT*/
#define FID_ComeFrom					63		//[20] /*��Ϣ��Դ Ŀǰδ��*/ 
#define FID_ConnectionReference			64				//[5] /*��·��ʾ Ŀǰδ��*/
#define FID_Content						65	//[500] /*��Ϣ����*/ 
#define FID_Currency					66		//[3]  /*�����õĻ���  �����õĻ��ң�Ŀǰ="RMB"*/
#define FID_DealQty						67	//[4]  /*�ɹ��������� ȱʡ=0,������������, δ����*/
#define FID_DealStatus					68		//    /*����״̬ 0��ɾ�� 1������ 2������*/
#define FID_DelValue					69		//[14]   /*������������ʽ�,FTDFloatType<14,2>*/ 
#define FID_DeriveAskLot				70			//[4] /*�����������*/
#define FID_DeriveAskPrice				71			//[12]     /*���������*/
#define FID_DeriveBidLot				72			//[4] /*�����������*/
#define FID_DeriveBidPrice				73			//[12]     /*��������*/
#define FID_Direction 					74		//   /*�������� 0->��,1->����2->���� ���Բ�������*/
#define FID_EndDelvDate					75		//[8]  /*��󽻸���*/
#define FID_EndTrdDate					76		//[8]  /*�������*/ 
#define FID_ErrorCode					77		//[10] /*�������*/ 
#define FID_ErrorText					78		//[100] /*��������*/ 
#define FID_ExchangeDateTime			79				//[20]/*������ϵͳʱ��  yyyymmddhhmmss*/
#define FID_Forcedistime				80			//[4] /*ǿƽ�Ĵ�ϼ��,������������, Ŀǰδ��*/ 
#define FID_ForceExitCode				81			//   /*ǿ���˳��� ĿǰΪ0*/
#define FID_ForceExitMsg				82			//[100]  /*ǿ���˳�ԭ��*/ 
#define FID_ForceGroupId				83			//[24] /*ǿƽ��� Ŀǰδ��*/ 
#define FID_FuseFlag					84			//   /*�۶ϱ�� 1->��,0->��  Ŀǰδ��*/
#define FID_Fuselimit					85			//[12]  /*�۶��޶� Ŀǰδ��*/
#define FID_Fusepersisttime				86			//[4]/*�۶�������ʱ��,������������, Ŀǰδ��*/ 
#define FID_Fusepoint					87			//[6]  /*�ڸ�ʱ���󲻿��۶� Ŀǰδ��*/ 
#define FID_FuseRights					88			//   /*�ɷ��۶� 1->��,0->�٣�ĿǰΪ0*/
#define FID_HedgeDate					89			//[8]  /*��������*/
#define FID_HedgeFlag					90			//   /*Ͷ����� 1->Ͷ��,3->���ڱ�ֵ*/
#define FID_HighLimit					91			//[12]  /*��ͣ��,FTDFloatType<12,4>*/ 
#define FID_HighLimitRate				92			//[4] /*��ͣ����  Ŀǰδ��*/ 
#define FID_HighPrice					93			//[12] /*��߼�,FTDFloatType<12,4>*/ 
#define FID_HoldQty						94			//[4]  /* �ֲ�����,������������, Ŀǰδ��*/
#define FID_InitMargin					95			//[14]  /*��ʼ��֤��,FTDFloatType<14,2>*/ 
#define FID_InsertTime					96			//[20]  /*¼��ʱ��*/ 
#define FID_InstrStopCode				97			//  /*ֹͣ����ԭ�� ĿǰΪ0*/
#define FID_InstrumentId				98				//[20] /*��Լ���� ���磬�ڻ�ΪWS509����ȨΪWS509C1600*/ 
#define FID_InstrumentName				99				//[80]  /*��Լ����*/
#define FID_InstrumentStatus			100					// /*��Լ����״̬ ��N��������S������D��ɾ����*/ 
#define FID_InstrumentType				101				//  /*��Լ���� 0:�ڻ�,1:��Ȩ,2:���*/
#define FID_InstrumentVersion			102					///*��Լ�汾�� ĿǰΪ0*/
#define FID_IpAddr						103			//[20]   /*��¼�ߵ�IP��ַ ��192.168.99.100*/
#define FID_LastLot						104			//[4] /*���һ�ʳɽ�������˫�����,������������*/ 
#define FID_LastPrice					105			//[12] /*���¼�,FTDFloatType<12,4>*/ 
#define FID_LifeHigh					106			//[12]  /*��ʷ��߳ɽ��۸�,FTDFloatType<12,4>*/ 
#define FID_LifeLow						107			//[12]  /*��ʷ��ͳɽ��۸�,FTDFloatType<12,4>*/ 
#define FID_LimitPrice					108			//[12]  /*�޼ۣ���ֹ�𶨵��ı����ۣ�,FTDFloatType<12,4>*/ 
#define FID_LongOffsFrozHPosition		109						//[4] /*��ͷƽ�ֶ���ֲ���(��),������������*/ 
#define FID_LongOffsFrozSPosition		110						//[4] /*��ͷƽ�ֶ���ֲ���(Ͷ),������������*/ 
#define FID_LongOpenFrozHPosition		111						//[4] /*��ͷ���ֶ���ֲ��֣�����,������������*/ 
#define FID_LongOpenFrozSPosition		112						//[4] /*��ͷ���ֶ���ֲ��֣�Ͷ��,������������*/ 
#define FID_LowLimit					113			//[12]  /*��ͣ��,FTDFloatType<12,4>*/ 
#define FID_LowLimitRate				114				//[4] /*��ͣ����  Ŀǰδ��*/ 
#define FID_LowPrice					115			//[12]  /*��ͼ�,FTDFloatType<12,4>*/ 
#define FID_Margin						116			//[12]   /*��֤��,FTDFloatType<12,4>*/ 
#define FID_MarketId					117			//[10]  /*�г����� ĿǰΪ"ZCE001"*/ 
#define FID_MarketMatchDataStatus		118						// /*�Ƿ��������ͳɽ����� 1->��,0->��*/
#define FID_MarketName					119			//[80]  /*�г�����*/ 
#define FID_MarketStatusId				120				// /*�г�����״̬
#define FID_MatchCondition				121				// /*�����ɽ����� 1->��ʱȫ���ɽ�,2->��ʱ���ֳɽ�,3->������Ч,4->ȡ��ǰ��Ч,5->ָ������ǰ��Ч*/
#define FID_MatchDate					122			//[8]  /*�ɽ�����*/
#define FID_MatchSession				123				// /*�����ɽ�ʱ��  Ŀǰδ��*/
#define FID_MatchTime					124			//[8]  /*�ɽ�ʱ��*/
#define FID_MaxLot						125			//[4] /*�����µ��������޼۵�ÿ�ʵ����������ĿǰΪ1000��������������*/ 
#define FID_MaxOrderLocalId				126				//[24]/*���ɹ��������ر��*/
#define FID_MessageReference			127					//[6]/*�û��Զ������ݡ���ע��Ϣ*/ 
#define FID_MinimalVolume				128				//[4] /*��С�ɽ���,������������,Ŀǰδ��*/ 
#define FID_MinLot						129			//[4]  /*��С���µ����� ĿǰΪ1,������������*/ 
#define FID_NewPassword					130			//[40]  /*�¿���*/
#define FID_NewsType					131			//[3] /*��Ϣ���� Ŀǰ='0'*/
#define FID_NewsUrgency					132			// /*�����̶� Ŀǰδ��*/
#define FID_OffsetFlag					133			//   /*��ƽ�ֱ�� 0->����,1->ƽ��,2->ǿƽ*/
#define FID_OldPassword					134			//[40]  /*�ɿ���*/
#define FID_OpenInterest				135				//[4] /*�ֲ���,������������*/ 
#define FID_OpenPrice					136			//[12] /*���̼�,FTDFloatType<12,4>*/ 
#define FID_OpenQty						137			//[4] /*�ѽ�������,������������*/
#define FID_OrderActionCode				138				// /*�������������� 0->ɾ��,1->����,2->����*/
#define FID_OrderCMBType				139				//  /*��������:��λ����, bit0->�޼�,bit1->�м�, bit3->ֹ�� bit7->��϶���*/
#define FID_OrderDate					140			//[8]   /*��������*/
#define FID_OrderLocalId				141				//[24] /*ί�б��*/ 
#define FID_OrderStatus					142			//  /*����״̬ 0->ȫ���ɽ�,1->���ֳɽ����ڶ�����,2->���ֳɽ����ڶ�����,3->δ�ɽ����ڶ�����,4->δ�ɽ����ڶ�����,5->���� 6->ֹ�𵥴���*/
#define FID_OrderStatus2				143				//   /*����״̬ 0��ɾ�� 1������ 2������*/
#define FID_OrderSysId					144			//[20]  /*��ͬ���*/ 
#define FID_OrderType					145			// /*�������� 0->�޼�,1->�м�, 3->ֹ��,7->��϶���*/ /*101->��������ȷ��,102->�ֲ��ױ�ȷ��,103->���󱨼�,104->��ȨȨ����ʹ, 105->����������Ӧ, 106->��ȨȨ������*/
#define FID_ParticipantId				146				//[8] /*���׻�Ա����*/ 
#define FID_ParticipantName				147				//[80]/*��Ա����*/ 
#define FID_ParticipantType				148				// /*��Ա���� 0->��Ӫ,1->����,2->�ۺ�,3->�ر�,4->������*/
#define FID_PartiTrdRight				149				//  /*��ԱȨ�� 0->��ȫ,1->ֻ��ƽ,2->��׼����*/
#define FID_Password					150			//[40]  /*����*/
#define FID_PreClose					151			//[12]  /*ǰ���̼۸�,FTDFloatType<12,4>*/
#define FID_PreOpenInterest				152				//[4]/*���տ�������˫�����,������������*/ 
#define FID_PreSettle					153			//[12]  /*ǰ����۸�,FTDFloatType<12,4>*/ 
#define FID_Price						154			//[12]   /*�۸�,FTDFloatType<12,4>*/
#define FID_ProtocolVersion				155				//[8]  /*ʹ��FTD�汾�� Ŀǰ=1*/
#define FID_Pubstyle					156			//   /*���۽׶κ�Լ���鷢����ʽ 0->������,1->����*/
#define FID_Qty							157			//[4]  /* �������� ,������������*/
#define FID_RemainQty					158			//[4] /*ʣ���� (�ɽ�������),������������ */
#define FID_ReqDate						159			//[8]   /*���뽨�ֿ�ʼ����*/
#define FID_ReqQty						160			//[4] /*�������� ��Ա��������,������������*/
#define FID_ReqSeqNum 					161			//[20]  /*�����������к�*/
#define FID_RequestBy 					162			//   /*����(0->һ���Ա��1->������)*/
#define FID_ResponseTime				163				//[8]  /*������Ӧʱ��*/
#define FID_SecondLeg					164			//[20] /*��϶����ڶ���*/
#define FID_SellHedgeOffsetMargin		165						//[14] /*����ƽ�ַ��ر�֤��,FTDFloatType<14,2>*/ 
#define FID_SellHedgeOffsetProfit		166						//[14] /*����ƽ��ӯ��,FTDFloatType<14,2>*/ 
#define FID_SellHedgeOpenFrozMargin		167						//[14]/*�������ֶ��ᱣ֤��,FTDFloatType<14,2>*/ 
#define FID_SellHedgeOpenUsedMargin		168						//[14]/*��������ʹ�ñ�֤��,FTDFloatType<14,2>*/ 
#define FID_SellHedgePosition			169					//[4] /*��������(��),������������*/ 
#define FID_SellHedgeTurnOver			170					//[14] /*�����ɽ���,FTDFloatType<14,2>*/ 
#define FID_SellHedgeVolume				171				//[4]  /*���ɽ���(��),������������*/ 
#define FID_SellOffsetFlag 				172				//  /*����ƽ�ֱ�־  0������ 1��ƽ��*/
#define FID_SellOffsHPosition			173					//[4] /*��ƽ����(��),������������*/ 
#define FID_SellOffsSPosition			174					//[4] /*��ƽ����(Ͷ),������������*/ 
#define FID_SellPrice 					175			//[12]  /*������,FTDFloatType<12,4>*/
#define FID_SellSpecOffsetMargin		176						//[14] /*��Ͷƽ�ַ��ر�֤��,FTDFloatType<14,2>*/ 
#define FID_SellSpecOffsetProfit		177						//[14] /*��Ͷƽ��ӯ��,FTDFloatType<14,2>*/ 
#define FID_SellSpecOpenFrozMargin		178						//[14] /*��Ͷ���ֶ��ᱣ֤��,FTDFloatType<14,2>*/ 
#define FID_SellSpecOpenUsedMargin		179						//[14] /*��Ͷ����ʹ�ñ�֤��,FTDFloatType<14,2>*/ 
#define FID_SellSpecPosition			180					//[4] /*��������(Ͷ),������������*/ 
#define FID_SellSpecTurnOver			181					//[14] /*��Ͷ�ɽ���,FTDFloatType<14,2>*/ 
#define FID_SellSpecVolume				182				//[4]  /*���ɽ���(Ͷ),������������*/ 
#define FID_SendTime					183			//[8] /*����ʱ�� hhmmss*/ 
#define FID_SequenceNo					184			//[4]  /*���к� ,������������*/ 
#define FID_SequenceSeries				185				//[2] /*�������� ,������������*/ 
#define FID_ServerAppName				186				//[20]  /*��ԱӦ��ϵͳ���� Ŀǰδ��*/
#define FID_SettleFlag					187			//    /* 0������ 1��ƽ��*/
#define FID_SettlePrice					188			//[12] /*���ս�������,FTDFloatType<12,4>*/ 
#define FID_ShortCutKey					189			//  /*�����ݼ�  Ŀǰδ�� ĿǰΪ0*/ 
#define FID_ShortOffsFrozHPosition		190						//[4] /*��ͷƽ�ֶ���ֲ���(��),������������*/ 
#define FID_ShortOffsFrozSPosition		191						//[4] /*��ͷƽ�ֶ���ֲ���(Ͷ),������������*/ 
#define FID_ShortOpenFrozHPosition		192						//[4] /*��ͷ���ֶ���ֲ��֣�����,������������*/ 
#define FID_ShortOpenFrozSPosition		193						//[4] /*��ͷ���ֶ���ֲ��֣�Ͷ��,������������*/ 
#define FID_SpdDate						194		//[8]    /*��ʼ����*/
#define FID_SpdEndDate					195			//[8]   /*��������*/
#define FID_StartDelvDate				196				//[8]  /*��ʼ������  Ŀǰδ��*/ 
#define FID_StartTime					197			//[8]  /*��ʼʱ�� Ŀǰδ��*/
#define FID_StartTrdDate				198				//[8]  /*��ʼ������*/ 
#define FID_StayTime 					199			//[2] /*�趨ͣ��ʱ��(��), 0��ʾ������,������������*/
#define FID_StopPrice					200			//[12]  /*ֹ��۸�,FTDFloatType<12,4>*/ 
#define FID_SuspendTime					201			//[8]  /*����ʱ��*/ 
#define FID_ThroughTime					202			//[8]  /*ֱ��ʱ�� Ŀǰδ��*/
#define FID_Tick						203		//[12]   /*��С�䶯��λ, FTDFloatType<12,4>�����磬С��Ϊ1���޻�Ϊ5*/ 
#define FID_TimeOut						204		//[3]   /*���ͼ���ź�ʱ���� Ŀǰδ��*/
#define FID_TimeSpan					205			//[3]  /*ʱ����������ʾ������������ʾ���� Ŀǰδ��*/
#define FID_TimeStamp					206			//[20] /*ʱ���  format=yyyymmddhhmmss*/ 
#define FID_TotalMarketMatchData		207						//[4] /*���ͳɽ������¼����,������������*/ 
#define FID_TotalVolume					208			//[4] /*�ܳɽ���,������������*/ 
#define FID_TradeDate					209			//[8] /*����ί������*/
#define FID_TradeId						210		//[20]  /*�ɽ����*/
#define FID_TradeLot					211			//[4] /*�ܳɽ�������˫�����,������������*/ 
#define FID_TradePrice					212			//[12]  /*���³ɽ��۸�,FTDFloatType<12,4>*/ 
#define FID_TradeRights					213			//  /*����Ȩ�� 0->��ȫ,1->ֻ��ƽ,2->��׼����*/
#define FID_TradeTurnover				214				//[4] /*�ܳɽ���˫�����,������������*/ 
#define FID_TradeType					215			//   /*�г��������� ĿǰΪ0*/
#define FID_TradeVolume					216			//[4] /*��ɽ���,������������*/ 
#define FID_Unbalance					217			//[4] /*δ��������,������������*/
#define FID_Unit						218		//[4]  /*ÿ�ֳ��������磬WT/WT/GN=10,CF=5,������������*/ 
#define FID_UpdateTime					219			//[8]  /*����޸�ʱ��*/ 
#define FID_URLLink						220		//[200] /*����Ϣ��WEB���� Ŀǰδ��*/ 
#define FID_UserId						221		//[15]   /*����Ա����*/ 
#define FID_ValidThrough				222				//[8]  /*��Чʱ��Լ�� yyyymmdd*/ 
#define FID_VirtualQty					223			//[4] /*�ɽ�������,������������*/
#define FID_VolAskLot					224			//[4]  /*����������,������������*/ 
#define FID_VolBidLot					225			//[4]  /*����������,������������*/ 
#define FID_Volume						226		//[4]  /*����,������������*/
#define FID_VolumeTotal					227			//[4] /*ʣ�����걨����������Ϊ��λ��,������������*/ 
#define FID_VolumeTotalOrginal			228					//[4] /*ԭʼ���걨����������Ϊ��λ��,������������*/ 
#define FID_WDTime						229		//[8]    /* ����ʱ�� */
#define FID_YdBuyHedgePosition			230					//[4] /*ǰ��ֲ���(��),������������*/ 
#define FID_YdBuyOffsHPosition			231					//[4] /*��ƽ����(��),������������*/ 
#define FID_YdBuyOffsSPosition			232					//[4] /*��ƽ����(Ͷ),������������*/ 
#define FID_YdBuySpecPosition			233					//[4] /*ǰ��ֲ���(Ͷ),������������*/ 
#define FID_YdLongOffsFrozHPosition		234						//[4]/*���ն�ͷƽ�ֶ���ֲ���(��),������������*/ 
#define FID_YdLongOffsFrozSPosition		235						//[4]/*���ն�ͷƽ�ֶ���ֲ���(Ͷ),������������*/ 
#define FID_YdSellHedgePosition			236					//[4] /*ǰ���ֲ���(��),������������*/ 
#define FID_YdSellOffsHPosition			237					//[4] /*��ƽ����(��),������������*/ 
#define FID_YdSellOffsSPosition			238					//[4] /*��ƽ����(Ͷ),������������*/ 
#define FID_YdSellSpecPosition			239					//[4] /*ǰ���ֲ���(Ͷ),������������*/ 
#define FID_YdShortOffsFrozHPosition	240							//[4]/*���տ�ͷƽ�ֶ���ֲ���(��),������������*/ 
#define FID_YdShortOffsFrozSPosition	241							//[4]/*���տ�ͷƽ�ֶ���ֲ���(Ͷ),������������*/ 
#define FID_Reserve						242				//�����غ�,ϵͳ�Ų�ѯ�����ı����ֶΡ�2009��3��2�ռ��롣
#define FID_BuyHoldQty					243				/*�����*/
#define	FID_SellHoldQty					244				/*������*/		
#define	FID_AvgBuyPrice					245				/*�����*/
#define	FID_AvgSellPrice				246				/*������*/
#define	FID_BuyVHolding					247				/*��ƽ��*/
#define	FID_SellVHolding				248				/*��ƽ��*/
#define	FID_OpenPL						249				/*����ӯ��*/
#define FID_OpenDate					250				//��������
#define FID_HedgeVHolding				251				///*���ڱ�ֵδƽ����*/
#define FID_MaxOpen						252				//��׼���ֲ���--------2009��7��31�ռ���
#define FID_CurMaxOpen					253				//��ǰ���ɿ�����
#define FID_LastHolding					254				//���ճֲ���
#define FID_CheckFunds					255				//�˶�����׼����
#define FID_RealFunds					256				//ʵ���ʽ�
#define FID_LastMarginAmt				257				//���ճֲ�Ӧ����֤��
#define FID_CurrMargin					258				//��ǰӦ��ȫ����֤��
#define FID_OpenMargin					259				//���տ���Ӧ����֤��
							
//��¼������Ҫ��д������				
										
//��������־���						
#define FID_DataFlowFlag	FID_SequenceSeries/*���������� 0->�Ի���,1->˽����,2->�㲥��*/
										
//��·��ʼ����							
#define FID_INIT_PASSWORD	0x0002		
//����Ա����							
#define FID_TRADER_ID		FID_UserId	
//��Ȩϵ�к�
#define FID_AUTH_SERIAL_NO	0x0003
//��Ȩ��
#define FID_AUTH_CODE		0x0004
//���׻�Ա����
#define FID_PARTICIPANTID  FID_ParticipantId
//����Ա����
#define FID_PASSWORD		FID_Password
//������ 'Y':���к������ģ�'N'û�к�������
#define FID_Chain			0x0006

#endif

