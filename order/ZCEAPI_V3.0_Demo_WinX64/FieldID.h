#ifndef FIELDID_H_
#define FIELDID_H_

//FieldID.h
//API元数据ID在这里定义

//协商密钥
#define PID_INVALIDPID 0xFFFFF
#define PID_NEGOTIATEDESKEY_REQ 0x00000
#define PID_NEGOTIATEDESKEY_RSP 0x10000
//登录请求
#define PID_LOGIN_REQ 0x00016
#define PID_LOGIN_RSP 0x10016
//退出登录请求
#define PID_LOGOUT_REQ 0x00017 
#define PID_LOGOUT_RSP 0x10017

#define FID_Abstract					16		//[80] /*摘要/说明 目前未用*/ 
#define FID_ActionLocalId				17			//[24] /*报单操作本地编号*/ 
#define FID_ActionType					18		//    /* 执行类型，'E'-执行(OPTION_EXEC)，'C'-放弃(OPTION_ABANDON)*/
#define FID_ActiveTime					19		//[8]  /*激活时间*/ 
#define FID_ActiveUserId				20			//[15] /*操作交易员编码*/ 
#define FID_AddValue					21		//[14]   /*本交易日新增资金,FTDFloatType<14,2>*/ 
#define FID_AlwDate						22	//[8]   /*允许建仓最后日期*/
#define FID_AlwHisDate					23		//[8]  /*历史持仓确认最后日期 AlwHisDate<=AlwDate*/
#define FID_AlwQty						24	//[4] /*批准数量 交易所批准数量,二进制网络序*/
#define FID_AskLot						25	//[4]  /*卖出数量,二进制网络序*/ 
#define FID_AskPrice					26		//[12] /*卖出价,FTDFloatType<12,4>*/ 
#define FID_AutoSuspend					27		//  /*自动挂起标志 1->真,0->假*/
#define FID_AveragePrice				28			//[12] /*均价,FTDFloatType<12,4>*/ 
#define FID_Balance						29	//[4]  /*已建仓数量,二进制网络序*/
#define FID_BalanceValue				30			//[14]  /*可用保证金余额,FTDFloatType<14,2>*/ 
#define FID_BidLot						31	//[4]  /*买入数量,二进制网络序*/ 
#define FID_BidPrice					32		//[12] /*买入价格,FTDFloatType<12,4>*/ 
#define FID_BroadcastSequenceNo			33				//[4] /*广播模式中的数据序列号,二进制网络序*/ 
#define FID_BroadcastSequenceSeries		34					//[2] /*广播模式序列类别号,二进制网络序*/ 
#define FID_BuyHedgeOffsetMargin		35					//[14] /*买保平仓返回保证金,FTDFloatType<14,2>*/ 
#define FID_BuyHedgeOffsetProfit		36					//[14] /*买保平仓盈亏,FTDFloatType<14,2>*/ 
#define FID_BuyHedgeOpenFrozMargin		37					//[14] /*买保开仓冻结保证金,FTDFloatType<14,2>*/ 
#define FID_BuyHedgeOpenUsedMargin		38					//[14] /*买保开仓使用保证金,FTDFloatType<14,2>*/ 
#define FID_BuyHedgePosition			39				//[4] /*买开仓量(保),二进制网络序*/ 
#define FID_BuyHedgeTurnOver			40				//[14] /*买保成交额,FTDFloatType<14,2>*/ 
#define FID_BuyHedgeVolume				41			//[4]  /*买成交量(保),二进制网络序*/ 
#define FID_BuyOffsetFlag 				42			//  /*买开平仓标志  0－开仓 1－平仓*/
#define FID_BuyOffsHPosition			43				//[4] /*买平今量(保),二进制网络序*/ 
#define FID_BuyOffsSPosition			44				//[4] /*买平今量(投),二进制网络序*/ 
#define FID_BuyPrice 					45		//[12]  /*买报价,FTDFloatType<12,4>*/
#define FID_BuySpecOffsetMargin			46				//[14] /*买投平仓返回保证金,FTDFloatType<14,2>*/ 
#define FID_BuySpecOffsetProfit			47				//[14] /*买投平仓盈亏,FTDFloatType<14,2>*/ 
#define FID_BuySpecOpenFrozMargin		48					//[14] /*买投开仓冻结保证金,FTDFloatType<14,2>*/ 
#define FID_BuySpecOpenUsedMargin		49					//[14] /*买投开仓使用保证金,FTDFloatType<14,2>*/ 
#define FID_BuySpecPosition				50			//[4]  /*买开仓量(投),二进制网络序*/ 
#define FID_BuySpecTurnOver				51			//[14] /*买投成交额,FTDFloatType<14,2>*/ 
#define FID_BuySpecVolume				52			//[4]  /*买成交量(投),二进制网络序*/ 
#define FID_CancelDate					53		//[8]  /*取消日期 目前未用*/
#define FID_CancelFlag					54		//   /*定单类型 0->普通定单，1->止损定单，2->组合定单*/
#define FID_CancelTime					55		//[8]  /*取消时间 目前未用*/
#define FID_ClearDate					56		//[8]  /*清算日期 目前未用*/
#define FID_ClearPrice					57		//[12]  /*结算价 ,FTDFloatType<12,4>*/ 
#define FID_ClientId					58		//[8] 
#define FID_ClientName					59		//[80] /*客户名称*/ 
#define FID_ClientType					60		//  /*客户类别 目前未用*/
#define FID_ClosePrice					61		//[12]  /*收盘价,FTDFloatType<12,4>*/ 
#define FID_CmbType						62	//     /*组合定单类型，0-SPZ 1-SPD 2-IPS 3-BUL 4-BER 5-BLT 6-BRT 7-STD 8-STG 9-PRT*/
#define FID_ComeFrom					63		//[20] /*消息来源 目前未用*/ 
#define FID_ConnectionReference			64				//[5] /*链路标示 目前未用*/
#define FID_Content						65	//[500] /*消息正文*/ 
#define FID_Currency					66		//[3]  /*交易用的货币  交易用的货币，目前="RMB"*/
#define FID_DealQty						67	//[4]  /*成功处理数量 缺省=0,二进制网络序, 未处理*/
#define FID_DealStatus					68		//    /*处理状态 0－删除 1－挂起 2－激活*/
#define FID_DelValue					69		//[14]   /*本交易日提出资金,FTDFloatType<14,2>*/ 
#define FID_DeriveAskLot				70			//[4] /*组合卖出数量*/
#define FID_DeriveAskPrice				71			//[12]     /*组合卖出价*/
#define FID_DeriveBidLot				72			//[4] /*组合买入数量*/
#define FID_DeriveBidPrice				73			//[12]     /*组合买入价*/
#define FID_Direction 					74		//   /*买卖方向 0->买,1->卖，2->所有 可以不用输入*/
#define FID_EndDelvDate					75		//[8]  /*最后交割日*/
#define FID_EndTrdDate					76		//[8]  /*最后交易日*/ 
#define FID_ErrorCode					77		//[10] /*错误代码*/ 
#define FID_ErrorText					78		//[100] /*错误正文*/ 
#define FID_ExchangeDateTime			79				//[20]/*交易所系统时间  yyyymmddhhmmss*/
#define FID_Forcedistime				80			//[4] /*强平的撮合间隔,二进制网络序, 目前未用*/ 
#define FID_ForceExitCode				81			//   /*强制退出号 目前为0*/
#define FID_ForceExitMsg				82			//[100]  /*强制退出原因*/ 
#define FID_ForceGroupId				83			//[24] /*强平组号 目前未用*/ 
#define FID_FuseFlag					84			//   /*熔断标记 1->真,0->假  目前未用*/
#define FID_Fuselimit					85			//[12]  /*熔断限额 目前未用*/
#define FID_Fusepersisttime				86			//[4]/*熔断最大持续时间,二进制网络序, 目前未用*/ 
#define FID_Fusepoint					87			//[6]  /*在该时间点后不可熔断 目前未用*/ 
#define FID_FuseRights					88			//   /*可否熔断 1->真,0->假，目前为0*/
#define FID_HedgeDate					89			//[8]  /*申请日期*/
#define FID_HedgeFlag					90			//   /*投保标记 1->投机,3->套期保值*/
#define FID_HighLimit					91			//[12]  /*涨停板,FTDFloatType<12,4>*/ 
#define FID_HighLimitRate				92			//[4] /*涨停板率  目前未用*/ 
#define FID_HighPrice					93			//[12] /*最高价,FTDFloatType<12,4>*/ 
#define FID_HoldQty						94			//[4]  /* 持仓数量,二进制网络序, 目前未用*/
#define FID_InitMargin					95			//[14]  /*初始保证金,FTDFloatType<14,2>*/ 
#define FID_InsertTime					96			//[20]  /*录入时间*/ 
#define FID_InstrStopCode				97			//  /*停止交易原因 目前为0*/
#define FID_InstrumentId				98				//[20] /*合约编码 例如，期货为WS509，期权为WS509C1600*/ 
#define FID_InstrumentName				99				//[80]  /*合约名称*/
#define FID_InstrumentStatus			100					// /*合约交易状态 （N－正常，S－挂起，D－删除）*/ 
#define FID_InstrumentType				101				//  /*合约类型 0:期货,1:期权,2:组合*/
#define FID_InstrumentVersion			102					///*合约版本号 目前为0*/
#define FID_IpAddr						103			//[20]   /*登录者的IP地址 如192.168.99.100*/
#define FID_LastLot						104			//[4] /*最后一笔成交手数，双向计算,二进制网络序*/ 
#define FID_LastPrice					105			//[12] /*最新价,FTDFloatType<12,4>*/ 
#define FID_LifeHigh					106			//[12]  /*历史最高成交价格,FTDFloatType<12,4>*/ 
#define FID_LifeLow						107			//[12]  /*历史最低成交价格,FTDFloatType<12,4>*/ 
#define FID_LimitPrice					108			//[12]  /*限价（或止损定单的保护价）,FTDFloatType<12,4>*/ 
#define FID_LongOffsFrozHPosition		109						//[4] /*多头平仓冻结持仓手(保),二进制网络序*/ 
#define FID_LongOffsFrozSPosition		110						//[4] /*多头平仓冻结持仓手(投),二进制网络序*/ 
#define FID_LongOpenFrozHPosition		111						//[4] /*多头开仓冻结持仓手（保）,二进制网络序*/ 
#define FID_LongOpenFrozSPosition		112						//[4] /*多头开仓冻结持仓手（投）,二进制网络序*/ 
#define FID_LowLimit					113			//[12]  /*跌停板,FTDFloatType<12,4>*/ 
#define FID_LowLimitRate				114				//[4] /*跌停板率  目前未用*/ 
#define FID_LowPrice					115			//[12]  /*最低价,FTDFloatType<12,4>*/ 
#define FID_Margin						116			//[12]   /*保证金,FTDFloatType<12,4>*/ 
#define FID_MarketId					117			//[10]  /*市场编码 目前为"ZCE001"*/ 
#define FID_MarketMatchDataStatus		118						// /*是否主动发送成交行情 1->真,0->假*/
#define FID_MarketName					119			//[80]  /*市场名称*/ 
#define FID_MarketStatusId				120				// /*市场交易状态
#define FID_MatchCondition				121				// /*报单成交属性 1->即时全部成交,2->即时部分成交,3->当日有效,4->取消前有效,5->指定日期前有效*/
#define FID_MatchDate					122			//[8]  /*成交日期*/
#define FID_MatchSession				123				// /*报单成交时间  目前未用*/
#define FID_MatchTime					124			//[8]  /*成交时间*/
#define FID_MaxLot						125			//[4] /*最大可下单手数，限价单每笔的最大手数，目前为1000，二进制网络序*/ 
#define FID_MaxOrderLocalId				126				//[24]/*最大成功报单本地编号*/
#define FID_MessageReference			127					//[6]/*用户自定义数据。备注信息*/ 
#define FID_MinimalVolume				128				//[4] /*最小成交量,二进制网络序,目前未用*/ 
#define FID_MinLot						129			//[4]  /*最小可下单手数 目前为1,二进制网络序*/ 
#define FID_NewPassword					130			//[40]  /*新口令*/
#define FID_NewsType					131			//[3] /*消息类型 目前='0'*/
#define FID_NewsUrgency					132			// /*紧急程度 目前未用*/
#define FID_OffsetFlag					133			//   /*开平仓标记 0->开仓,1->平仓,2->强平*/
#define FID_OldPassword					134			//[40]  /*旧口令*/
#define FID_OpenInterest				135				//[4] /*持仓量,二进制网络序*/ 
#define FID_OpenPrice					136			//[12] /*开盘价,FTDFloatType<12,4>*/ 
#define FID_OpenQty						137			//[4] /*已建仓数量,二进制网络序*/
#define FID_OrderActionCode				138				// /*报单操作类型码 0->删除,1->挂起,2->激活*/
#define FID_OrderCMBType				139				//  /*报单类型:按位处理, bit0->限价,bit1->市价, bit3->止损 bit7->组合定单*/
#define FID_OrderDate					140			//[8]   /*申请日期*/
#define FID_OrderLocalId				141				//[24] /*委托编号*/ 
#define FID_OrderStatus					142			//  /*报单状态 0->全部成交,1->部分成交还在队列中,2->部分成交不在队列中,3->未成交还在队列中,4->未成交不在队列中,5->撤单 6->止损单触发*/
#define FID_OrderStatus2				143				//   /*报单状态 0－删除 1－挂起 2－激活*/
#define FID_OrderSysId					144			//[20]  /*合同编号*/ 
#define FID_OrderType					145			// /*报单类型 0->限价,1->市价, 3->止损,7->组合定单*/ /*101->跨期套利确认,102->持仓套保确认,103->请求报价,104->期权权力行使, 105->报价请求响应, 106->期权权力放弃*/
#define FID_ParticipantId				146				//[8] /*交易会员编码*/ 
#define FID_ParticipantName				147				//[80]/*会员名称*/ 
#define FID_ParticipantType				148				// /*会员类型 0->自营,1->经纪,2->综合,3->特别,4->做市商*/
#define FID_PartiTrdRight				149				//  /*会员权限 0->完全,1->只可平,2->不准交易*/
#define FID_Password					150			//[40]  /*口令*/
#define FID_PreClose					151			//[12]  /*前收盘价格,FTDFloatType<12,4>*/
#define FID_PreOpenInterest				152				//[4]/*昨日空盘量，双向计算,二进制网络序*/ 
#define FID_PreSettle					153			//[12]  /*前结算价格,FTDFloatType<12,4>*/ 
#define FID_Price						154			//[12]   /*价格,FTDFloatType<12,4>*/
#define FID_ProtocolVersion				155				//[8]  /*使用FTD版本号 目前=1*/
#define FID_Pubstyle					156			//   /*竞价阶段合约行情发布方式 0->不发布,1->发布*/
#define FID_Qty							157			//[4]  /* 申请数量 ,二进制网络序*/
#define FID_RemainQty					158			//[4] /*剩余额度 (可建仓数量),二进制网络序 */
#define FID_ReqDate						159			//[8]   /*申请建仓开始日期*/
#define FID_ReqQty						160			//[4] /*申请数量 会员申请数量,二进制网络序*/
#define FID_ReqSeqNum 					161			//[20]  /*报价请求序列号*/
#define FID_RequestBy 					162			//   /*请求方(0->一般会员，1->交易所)*/
#define FID_ResponseTime				163				//[8]  /*请求响应时间*/
#define FID_SecondLeg					164			//[20] /*组合定单第二腿*/
#define FID_SellHedgeOffsetMargin		165						//[14] /*卖保平仓返回保证金,FTDFloatType<14,2>*/ 
#define FID_SellHedgeOffsetProfit		166						//[14] /*卖保平仓盈亏,FTDFloatType<14,2>*/ 
#define FID_SellHedgeOpenFrozMargin		167						//[14]/*卖保开仓冻结保证金,FTDFloatType<14,2>*/ 
#define FID_SellHedgeOpenUsedMargin		168						//[14]/*卖保开仓使用保证金,FTDFloatType<14,2>*/ 
#define FID_SellHedgePosition			169					//[4] /*卖开仓量(保),二进制网络序*/ 
#define FID_SellHedgeTurnOver			170					//[14] /*卖保成交额,FTDFloatType<14,2>*/ 
#define FID_SellHedgeVolume				171				//[4]  /*卖成交量(保),二进制网络序*/ 
#define FID_SellOffsetFlag 				172				//  /*卖开平仓标志  0－开仓 1－平仓*/
#define FID_SellOffsHPosition			173					//[4] /*卖平今量(保),二进制网络序*/ 
#define FID_SellOffsSPosition			174					//[4] /*卖平今量(投),二进制网络序*/ 
#define FID_SellPrice 					175			//[12]  /*卖报价,FTDFloatType<12,4>*/
#define FID_SellSpecOffsetMargin		176						//[14] /*卖投平仓返回保证金,FTDFloatType<14,2>*/ 
#define FID_SellSpecOffsetProfit		177						//[14] /*卖投平仓盈亏,FTDFloatType<14,2>*/ 
#define FID_SellSpecOpenFrozMargin		178						//[14] /*卖投开仓冻结保证金,FTDFloatType<14,2>*/ 
#define FID_SellSpecOpenUsedMargin		179						//[14] /*卖投开仓使用保证金,FTDFloatType<14,2>*/ 
#define FID_SellSpecPosition			180					//[4] /*卖开仓量(投),二进制网络序*/ 
#define FID_SellSpecTurnOver			181					//[14] /*卖投成交额,FTDFloatType<14,2>*/ 
#define FID_SellSpecVolume				182				//[4]  /*卖成交量(投),二进制网络序*/ 
#define FID_SendTime					183			//[8] /*发送时间 hhmmss*/ 
#define FID_SequenceNo					184			//[4]  /*序列号 ,二进制网络序*/ 
#define FID_SequenceSeries				185				//[2] /*序列类别号 ,二进制网络序*/ 
#define FID_ServerAppName				186				//[20]  /*会员应用系统名称 目前未用*/
#define FID_SettleFlag					187			//    /* 0－开仓 1－平仓*/
#define FID_SettlePrice					188			//[12] /*当日交割结算价,FTDFloatType<12,4>*/ 
#define FID_ShortCutKey					189			//  /*输入快捷键  目前未用 目前为0*/ 
#define FID_ShortOffsFrozHPosition		190						//[4] /*空头平仓冻结持仓手(保),二进制网络序*/ 
#define FID_ShortOffsFrozSPosition		191						//[4] /*空头平仓冻结持仓手(投),二进制网络序*/ 
#define FID_ShortOpenFrozHPosition		192						//[4] /*空头开仓冻结持仓手（保）,二进制网络序*/ 
#define FID_ShortOpenFrozSPosition		193						//[4] /*空头开仓冻结持仓手（投）,二进制网络序*/ 
#define FID_SpdDate						194		//[8]    /*开始日期*/
#define FID_SpdEndDate					195			//[8]   /*结束日期*/
#define FID_StartDelvDate				196				//[8]  /*开始交割日  目前未用*/ 
#define FID_StartTime					197			//[8]  /*开始时间 目前未用*/
#define FID_StartTrdDate				198				//[8]  /*开始交易日*/ 
#define FID_StayTime 					199			//[2] /*设定停留时间(秒), 0表示不限制,二进制网络序*/
#define FID_StopPrice					200			//[12]  /*止损价格,FTDFloatType<12,4>*/ 
#define FID_SuspendTime					201			//[8]  /*挂起时间*/ 
#define FID_ThroughTime					202			//[8]  /*直到时间 目前未用*/
#define FID_Tick						203		//[12]   /*最小变动价位, FTDFloatType<12,4>，例如，小麦为1，棉花为5*/ 
#define FID_TimeOut						204		//[3]   /*发送监测信号时间间隔 目前未用*/
#define FID_TimeSpan					205			//[3]  /*时区，正数表示东区，负数表示西区 目前未用*/
#define FID_TimeStamp					206			//[20] /*时间戳  format=yyyymmddhhmmss*/ 
#define FID_TotalMarketMatchData		207						//[4] /*发送成交行情记录总数,二进制网络序*/ 
#define FID_TotalVolume					208			//[4] /*总成交量,二进制网络序*/ 
#define FID_TradeDate					209			//[8] /*交易委托日期*/
#define FID_TradeId						210		//[20]  /*成交编号*/
#define FID_TradeLot					211			//[4] /*总成交手数，双向计算,二进制网络序*/ 
#define FID_TradePrice					212			//[12]  /*最新成交价格,FTDFloatType<12,4>*/ 
#define FID_TradeRights					213			//  /*交易权限 0->完全,1->只可平,2->不准交易*/
#define FID_TradeTurnover				214				//[4] /*总成交金额，双向计算,二进制网络序*/ 
#define FID_TradeType					215			//   /*市场交易类型 目前为0*/
#define FID_TradeVolume					216			//[4] /*今成交量,二进制网络序*/ 
#define FID_Unbalance					217			//[4] /*未建仓数量,二进制网络序*/
#define FID_Unit						218		//[4]  /*每手乘数，例如，WT/WT/GN=10,CF=5,二进制网络序*/ 
#define FID_UpdateTime					219			//[8]  /*最后修改时间*/ 
#define FID_URLLink						220		//[200] /*此消息的WEB联结 目前未用*/ 
#define FID_UserId						221		//[15]   /*交易员编码*/ 
#define FID_ValidThrough				222				//[8]  /*有效时间约束 yyyymmdd*/ 
#define FID_VirtualQty					223			//[4] /*可建仓数量,二进制网络序*/
#define FID_VolAskLot					224			//[4]  /*总卖出数量,二进制网络序*/ 
#define FID_VolBidLot					225			//[4]  /*总买入数量,二进制网络序*/ 
#define FID_Volume						226		//[4]  /*数量,二进制网络序*/
#define FID_VolumeTotal					227			//[4] /*剩余总申报数量（以手为单位）,二进制网络序*/ 
#define FID_VolumeTotalOrginal			228					//[4] /*原始总申报数量（以手为单位）,二进制网络序*/ 
#define FID_WDTime						229		//[8]    /* 撤消时间 */
#define FID_YdBuyHedgePosition			230					//[4] /*前买持仓量(保),二进制网络序*/ 
#define FID_YdBuyOffsHPosition			231					//[4] /*买平昨量(保),二进制网络序*/ 
#define FID_YdBuyOffsSPosition			232					//[4] /*买平昨量(投),二进制网络序*/ 
#define FID_YdBuySpecPosition			233					//[4] /*前买持仓量(投),二进制网络序*/ 
#define FID_YdLongOffsFrozHPosition		234						//[4]/*上日多头平仓冻结持仓手(保),二进制网络序*/ 
#define FID_YdLongOffsFrozSPosition		235						//[4]/*上日多头平仓冻结持仓手(投),二进制网络序*/ 
#define FID_YdSellHedgePosition			236					//[4] /*前卖持仓量(保),二进制网络序*/ 
#define FID_YdSellOffsHPosition			237					//[4] /*卖平昨量(保),二进制网络序*/ 
#define FID_YdSellOffsSPosition			238					//[4] /*卖平昨量(投),二进制网络序*/ 
#define FID_YdSellSpecPosition			239					//[4] /*前卖持仓量(投),二进制网络序*/ 
#define FID_YdShortOffsFrozHPosition	240							//[4]/*上日空头平仓冻结持仓手(保),二进制网络序*/ 
#define FID_YdShortOffsFrozSPosition	241							//[4]/*上日空头平仓冻结持仓手(投),二进制网络序*/ 
#define FID_Reserve						242				//按本地号,系统号查询报单的保留字段。2009年3月2日加入。
#define FID_BuyHoldQty					243				/*持买仓*/
#define	FID_SellHoldQty					244				/*持卖仓*/		
#define	FID_AvgBuyPrice					245				/*买均价*/
#define	FID_AvgSellPrice				246				/*卖均价*/
#define	FID_BuyVHolding					247				/*可平买*/
#define	FID_SellVHolding				248				/*可平卖*/
#define	FID_OpenPL						249				/*浮动盈亏*/
#define FID_OpenDate					250				//开仓日期
#define FID_HedgeVHolding				251				///*套期保值未平仓量*/
#define FID_MaxOpen						252				//核准最大持仓量--------2009年7月31日加入
#define FID_CurMaxOpen					253				//当前最大可开仓量
#define FID_LastHolding					254				//昨日持仓量
#define FID_CheckFunds					255				//核定结算准备金
#define FID_RealFunds					256				//实际资金
#define FID_LastMarginAmt				257				//昨日持仓应交保证金
#define FID_CurrMargin					258				//当前应交全部保证金
#define FID_OpenMargin					259				//今日开仓应交保证金
							
//登录请求需要填写的数据				
										
//数据流标志编号						
#define FID_DataFlowFlag	FID_SequenceSeries/*数据流名称 0->对话流,1->私有流,2->广播流*/
										
//链路初始密码							
#define FID_INIT_PASSWORD	0x0002		
//交易员编码							
#define FID_TRADER_ID		FID_UserId	
//授权系列号
#define FID_AUTH_SERIAL_NO	0x0003
//授权码
#define FID_AUTH_CODE		0x0004
//交易会员编码
#define FID_PARTICIPANTID  FID_ParticipantId
//交易员密码
#define FID_PASSWORD		FID_Password
//报文链 'Y':仍有后续报文，'N'没有后续报文
#define FID_Chain			0x0006

#endif

