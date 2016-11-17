//将API数据包写到文件中,文件名字加入当前时间

#include <iostream>
#include <fstream>
#include "FTDAPI.h"
#include "FieldID.h"

#pragma warning(disable:4996)		//VS2013下忽略strcpy等不安全的警告

//不可变数组,用于向文件中写入数据时使用
const char  FIDName[250][100] = {
    "                                                           ",
    "FID_INIT_PASSWORD            链路初始密码                  ",
    "FID_AUTH_SERIAL_NO           授权系列号                    ",
    "FID_AUTH_CODE                授权码                        ",
    "                                                           ",
    "FID_Chain                    报文链标记                    ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "                                                           ",
    "FID_Abstract                 摘要 说明                     ",
    "FID_ActionLocalId            报单操作本地编号              ",
    "FID_ActionType               执行类型                      ",
    "FID_ActiveTime               激活时间                      ",
    "FID_ActiveUserId             操作交易员编码                ",
    "FID_AddValue                 本交易日新增资金              ",
    "FID_AlwDate                  允许建仓最后日期              ",
    "FID_AlwHisDate               历史持仓确认最后日期          ",
    "FID_AlwQty                   批准数量 交易所批准数量       ",
    "FID_AskLot                   卖出数量                      ",
    "FID_AskPrice                 卖出价                        ",
    "FID_AutoSuspend              自动挂起标志                  ",
    "FID_AveragePrice             均价                          ",
    "FID_Balance                  已建仓数量                    ",
    "FID_BalanceValue             可用保证金余额                ",
    "FID_BidLot                   买入数量                      ",
    "FID_BidPrice                 买入价格                      ",
    "FID_BroadcastSequenceNo      广播模式中的数据序列号        ",
    "FID_BroadcastSequenceSeries  广播模式序列类别号            ",
    "FID_BuyHedgeOffsetMargin     买保平仓返回保证金            ",
    "FID_BuyHedgeOffsetProfit     买保平仓盈亏                  ",
    "FID_BuyHedgeOpenFrozMargin   买保开仓冻结保证金            ",
    "FID_BuyHedgeOpenUsedMargin   买保开仓使用保证金            ",
    "FID_BuyHedgePosition         买开仓量(保)                  ",
    "FID_BuyHedgeTurnOver         买保成交额                    ",
    "FID_BuyHedgeVolume           买成交量(保)                  ",
    "FID_BuyOffsetFlag            买开平仓标志                  ",
    "FID_BuyOffsHPosition         买平今量(保)                  ",
    "FID_BuyOffsSPosition         买平今量(投)                  ",
    "FID_BuyPrice                 买报价                        ",
    "FID_BuySpecOffsetMargin      买投平仓返回保证金            ",
    "FID_BuySpecOffsetProfit      买投平仓盈亏                  ",
    "FID_BuySpecOpenFrozMargin    买投开仓冻结保证金            ",
    "FID_BuySpecOpenUsedMargin    买投开仓使用保证金            ",
    "FID_BuySpecPosition          买开仓量(投)                  ",
    "FID_BuySpecTurnOver          买投成交额                    ",
    "FID_BuySpecVolume            买成交量(投)                  ",
    "FID_CancelDate               取消日期                      ",
    "FID_CancelFlag               定单类型                      ",
    "FID_CancelTime               取消时间                      ",
    "FID_ClearDate                清算日期                      ",
    "FID_ClearPrice               结算价                        ",
    "FID_ClientId                 客户ID                        ",
    "FID_ClientName               客户名称                      ",
    "FID_ClientType               客户类别                      ",
    "FID_ClosePrice               收盘价                        ",
    "FID_CmbType                  组合定单类型                  ",
    "FID_ComeFrom                 消息来源                      ",
    "FID_ConnectionReference      链路标示                      ",
    "FID_Content                  消息正文                      ",
    "FID_Currency                 交易用的货币                  ",
    "FID_DealQty                  成功处理数量                  ",
    "FID_DealStatus               处理状态                      ",
    "FID_DelValue                 本交易日提出资金              ",
    "FID_DeriveAskLot             组合卖出数量                  ",
    "FID_DeriveAskPrice           组合卖出价                    ",
    "FID_DeriveBidLot             组合买入数量                  ",
    "FID_DeriveBidPrice           组合买入价                    ",
    "FID_Direction                买卖方向                      ",
    "FID_EndDelvDate              最后交割日                    ",
    "FID_EndTrdDate               最后交易                      ",
    "FID_ErrorCode                错误代码                      ",
    "FID_ErrorText                错误正文                      ",
    "FID_ExchangeDateTime         交易所系统时间                ",
    "FID_Forcedistime             强平的撮合间隔                ",
    "FID_ForceExitCode            强制退出号                    ",
    "FID_ForceExitMsg             强制退出原因                  ",
    "FID_ForceGroupId             强平组号                      ",
    "FID_FuseFlag                 熔断标记                      ",
    "FID_Fuselimit                熔断限额                      ",
    "FID_Fusepersisttime          熔断最大持续时间              ",
    "FID_Fusepoint                在该时间点后不可熔断          ",
    "FID_FuseRights               可否熔断                      ",
    "FID_HedgeDate                申请日期                      ",
    "FID_HedgeFlag                投保标记                      ",
    "FID_HighLimit                涨停板                        ",
    "FID_HighLimitRate            涨停板率                      ",
    "FID_HighPrice                最高价                        ",
    "FID_HoldQty                  持仓数量                      ",
    "FID_InitMargin               初始保证金                    ",
    "FID_InsertTime               录入时间                      ",
    "FID_InstrStopCode            停止交易原因                  ",
    "FID_InstrumentId             合约编码                      ",
    "FID_InstrumentName           合约名称                      ",
    "FID_InstrumentStatus         合约交易状态                  ",
    "FID_InstrumentType           合约类型                      ",
    "FID_InstrumentVersion        合约版本号                    ",
    "FID_IpAddr                   登录者的IP地址                ",
    "FID_LastLot                  最后一笔成交手数              ",
    "FID_LastPrice                最新价                        ",
    "FID_LifeHigh                 历史最高成交价格              ",
    "FID_LifeLow                  历史最低成交价格              ",
    "FID_LimitPrice               限价（或止损定单的保护价）    ",
    "FID_LongOffsFrozHPosition    多头平仓冻结持仓手(保)        ",
    "FID_LongOffsFrozSPosition    多头平仓冻结持仓手(投)        ",
    "FID_LongOpenFrozHPosition    多头开仓冻结持仓手（保）      ",
    "FID_LongOpenFrozSPosition    多头开仓冻结持仓手（投）      ",
    "FID_LowLimit                 跌停板                        ",
    "FID_LowLimitRate             跌停板率                      ",
    "FID_LowPrice                 最低价                        ",
    "FID_Margin                   保证金                        ",
    "FID_MarketId                 市场编码                      ",
    "FID_MarketMatchDataStatus    是否主动发送成交行情          ",
    "FID_MarketName               市场名称                      ",
    "FID_MarketStatusId           市场交易状态                  ",
    "FID_MatchCondition           报单成交属性                  ",
    "FID_MatchDate                成交日期                      ",
    "FID_MatchSession             报单成交时间                  ",
    "FID_MatchTime                成交时间                      ",
    "FID_MaxLot                   最大可下单手数                ",
    "FID_MaxOrderLocalId          最大成功报单本地编号          ",
    "FID_MessageReference         用户自定义数据                ",
    "FID_MinimalVolume            最小成交量                    ",
    "FID_MinLot                   最小可下单手数                ",
    "FID_NewPassword              新口令                        ",
    "FID_NewsType                 消息类型                      ",
    "FID_NewsUrgency              紧急程度                      ",
    "FID_OffsetFlag               开平仓标记                    ",
    "FID_OldPassword              旧口令                        ",
    "FID_OpenInterest             持仓量                        ",
    "FID_OpenPrice                开盘价                        ",
    "FID_OpenQty                  已建仓数量                    ",
    "FID_OrderActionCode          报单操作类型码                ",
    "FID_OrderCMBType             报单类型:按位处理             ",
    "FID_OrderDate                申请日期                      ",
    "FID_OrderLocalId             委托编号                      ",
    "FID_OrderStatus              报单状态                      ",
    "FID_OrderStatus2             报单状态                      ",
    "FID_OrderSysId               合同编号                      ",
    "FID_OrderType                报单类型                      ",
    "FID_ParticipantId            交易会员编码                  ",
    "FID_ParticipantName          会员名称                      ",
    "FID_ParticipantType          会员类型                      ",
    "FID_PartiTrdRight            会员权限                      ",
    "FID_Password                 口令                          ",
    "FID_PreClose                 前收盘价格                    ",
    "FID_PreOpenInterest          昨日空盘量                    ",
    "FID_PreSettle                前结算价格                    ",
    "FID_Price                    价格                          ",
    "FID_ProtocolVersion          使用FTD版本号                 ",
    "FID_Pubstyle                 竞价阶段合约行情发布方式      ",
    "FID_Qty                      申请数量                      ",
    "FID_RemainQty                剩余额度 (可建仓数量)         ",
    "FID_ReqDate                  申请建仓开始日期              ",
    "FID_ReqQty                   申请数量 会员申请数量         ",
    "FID_ReqSeqNum                报价请求序列号                ",
    "FID_RequestBy                请求方(0->一般会员，1->交易所)",
    "FID_ResponseTime             请求响应时间                  ",
    "FID_SecondLeg                组合定单第二腿                ",
    "FID_SellHedgeOffsetMargin    卖保平仓返回保证金            ",
    "FID_SellHedgeOffsetProfit    卖保平仓盈亏                  ",
    "FID_SellHedgeOpenFrozMargin  卖保开仓冻结保证金            ",
    "FID_SellHedgeOpenUsedMargin  卖保开仓使用保证金            ",
    "FID_SellHedgePosition        卖开仓量(保)                  ",
    "FID_SellHedgeTurnOver        卖保成交额                    ",
    "FID_SellHedgeVolume          卖成交量(保)                  ",
    "FID_SellOffsetFlag           卖开平仓标志                  ",
    "FID_SellOffsHPosition        卖平今量(保)                  ",
    "FID_SellOffsSPosition        卖平今量(投)                  ",
    "FID_SellPrice                卖报价                        ",
    "FID_SellSpecOffsetMargin     卖投平仓返回保证金            ",
    "FID_SellSpecOffsetProfit     卖投平仓盈亏                  ",
    "FID_SellSpecOpenFrozMargin   卖投开仓冻结保证金            ",
    "FID_SellSpecOpenUsedMargin   卖投开仓使用保证金            ",
    "FID_SellSpecPosition         卖开仓量(投)                  ",
    "FID_SellSpecTurnOver         卖投成交额                    ",
    "FID_SellSpecVolume           卖成交量(投)                  ",
    "FID_SendTime                 发送时间                      ",
    "FID_SequenceNo               序列号                        ",
    "FID_SequenceSeries           即DataFlowFlag 序列类别号     ",
    "FID_ServerAppName            会员应用系统名称              ",
    "FID_SettleFlag               0－开仓 1－平仓               ",
    "FID_SettlePrice              当日交割结算价                ",
    "FID_ShortCutKey              输入快捷键                    ",
    "FID_ShortOffsFrozHPosition   空头平仓冻结持仓手(保)        ",
    "FID_ShortOffsFrozSPosition   空头平仓冻结持仓手(投)        ",
    "FID_ShortOpenFrozHPosition   空头开仓冻结持仓手（保）      ",
    "FID_ShortOpenFrozSPosition   空头开仓冻结持仓手（投）      ",
    "FID_SpdDate                  开始日期                      ",
    "FID_SpdEndDate               结束日期                      ",
    "FID_StartDelvDate            开始交割日                    ",
    "FID_StartTime                开始时间                      ",
    "FID_StartTrdDate             开始交易日                    ",
    "FID_StayTime                 设定停留时间(秒)              ",
    "FID_StopPrice                止损价格                      ",
    "FID_SuspendTime              挂起时间                      ",
    "FID_ThroughTime              直到时间                      ",
    "FID_Tick                     最小变动价位                  ",
    "FID_TimeOut                  发送监测信号时间间隔          ",
    "FID_TimeSpan                 时区                          ",
    "FID_TimeStamp                时间戳                        ",
    "FID_TotalMarketMatchData     发送成交行情记录总数          ",
    "FID_TotalVolume              总成交量                      ",
    "FID_TradeDate                交易委托日期                  ",
    "FID_TradeId                  成交编号                      ",
    "FID_TradeLot                 总成交手数                    ",
    "FID_TradePrice               最新成交价格                  ",
    "FID_TradeRights              交易权限                      ",
    "FID_TradeTurnover            总成交金额                    ",
    "FID_TradeType                市场交易类型                  ",
    "FID_TradeVolume              今成交量                      ",
    "FID_Unbalance                未建仓数量                    ",
    "FID_Unit                     每手乘数                      ",
    "FID_UpdateTime               最后修改时间                  ",
    "FID_URLLink                  此消息的WEB联结               ",
    "FID_UserId                   交易员编码                    ",
    "FID_ValidThrough             有效时间约束                  ",
    "FID_VirtualQty               可建仓数量,                   ",
    "FID_VolAskLot                总卖出数量,                   ",
    "FID_VolBidLot                总买入数量,                   ",
    "FID_Volume                   数量                          ",
    "FID_VolumeTotal              剩余总申报数量（以手为单位）  ",
    "FID_VolumeTotalOrginal       原始总申报数量（以手为单位）  ",
    "FID_WDTime                   撤消时间                      ",
    "FID_YdBuyHedgePosition       前买持仓量(保)                ",
    "FID_YdBuyOffsHPosition       买平昨量(保)                  ",
    "FID_YdBuyOffsSPosition       买平昨量(投)                  ",
    "FID_YdBuySpecPosition        前买持仓量(投)                ",
    "FID_YdLongOffsFrozHPosition  上日多头平仓冻结持仓手(保)    ",
    "FID_YdLongOffsFrozSPosition  上日多头平仓冻结持仓手(投)    ",
    "FID_YdSellHedgePosition      前卖持仓量(保)                ",
    "FID_YdSellOffsHPosition      卖平昨量(保)                  ",
    "FID_YdSellOffsSPosition      卖平昨量(投)                  ",
    "FID_YdSellSpecPosition       前卖持仓量(投)                ",
    "FID_YdShortOffsFrozHPosition 上日空头平仓冻结持仓手(保)    ",
    "FID_YdShortOffsFrozSPosition 上日空头平仓冻结持仓手(投)    "
};

//根据数据包的PID得到数据包的业务名字,若PID不存在或者PID不合法,则返回不存在的数据包
void getBussinessname(char * Business, int PID)
{
    switch (PID)
    {
    case   0x00016:  strcpy(Business, "$00016 交易员登录请求"); break;
    case   0x10016:	 strcpy(Business, "$10016 交易员登录应答"); break;
    case   0x00017:  strcpy(Business, "$00017 交易员退出登录请求"); break;
    case   0x10017:  strcpy(Business, "$10017 交易员退出登录应答"); break;
    case   0x00018:  strcpy(Business, "$00018 交易员修改密码请求"); break;
    case   0x10018:  strcpy(Business, "$10018 交易员修改密码应答"); break;

    case   0x03003:  strcpy(Business, "$03003 做市商报价响应录入请求"); break;
    case   0x13003:  strcpy(Business, "$13003 做市商报价响应录入应答"); break;

    case   0x00003:  strcpy(Business, "$00003 报单录入请求"); break;
    case   0x10003:  strcpy(Business, "$10003 报单录入应答"); break;
    case   0x00004:  strcpy(Business, "$00004 报单操作请求"); break;
    case   0x10004:  strcpy(Business, "$10004 报单操作应答"); break;
    case   0x00006:  strcpy(Business, "$00006 报单查询请求"); break;
    case   0x10006:  strcpy(Business, "$10006 报单查询应答"); break;

    case   0x03010:	 strcpy(Business, "$03010 按定单类型报单查询请求"); break;
    case   0x13010:	 strcpy(Business, "$13010 按定单类型报单查询应答"); break;
    case   0x03013:  strcpy(Business, "$03013 按本地定单号报单查询请求"); break;
    case   0x13013:  strcpy(Business, "$13013 按本地定单号报单查询应答"); break;
    case   0x03046:  strcpy(Business, "$03046 按变化量报单查询请求");  break;
    case   0x13046:  strcpy(Business, "$13046 按变化量报单查询应答"); break;

    case   0x03017:  strcpy(Business, "$03017 套期保值额度查询请求"); break;
    case   0x13017:  strcpy(Business, "$13017 套期保值额度查询应答"); break;
    case   0x03018:  strcpy(Business, "$03018 套期保值确认查询请求");  break;
    case   0x13018:  strcpy(Business, "$13018 套期保值确认查询应答"); break;
    case   0x03019:  strcpy(Business, "$03019 跨期套利额度查询请求"); break;
    case   0x13019:  strcpy(Business, "$13019 跨期套利额度查询应答"); break;
    case   0x03020:  strcpy(Business, "$03020 跨期套利确认查询请求"); break;
    case   0x13020:  strcpy(Business, "$13020 跨期套利确认查询应答"); break;

    case   0x03026:  strcpy(Business, "$03026 做市商报价响应查询请求"); break;
    case   0x13026:  strcpy(Business, "$13026 做市商报价响应查询应答"); break;

    case   0x03025:  strcpy(Business, "$03025 期权执行查询请求"); break;
    case   0x13025:  strcpy(Business, "$13025 期权执行查询应答"); break;

    case   0x0000B:  strcpy(Business, "$0000B 市场查询请求"); break;
    case   0x1000B:  strcpy(Business, "$1000B 市场查询应答"); break;
    case   0x0000D:  strcpy(Business, "$0000D 市场交易状态查询请求"); break;
    case   0x1000D:  strcpy(Business, "$1000D 市场交易状态查询应答"); break;

    case   0x00005:  strcpy(Business, "$00005 合约查询请求"); break;
    case   0x10005:  strcpy(Business, "$10005 合约查询应答"); break;
    case   0x0000E:  strcpy(Business, "$0000E 品种交易状态查询请求"); break;
    case   0x1000E:  strcpy(Business, "$1000E 品种交易状态查询应答"); break;
    case   0x03015:  strcpy(Business, "$03015 组合合约查询请求"); break;
    case   0x13015:  strcpy(Business, "$13015 组合合约查询应答"); break;

    case   0x0000C:  strcpy(Business, "$0000C 客户信息查询请求"); break;
    case   0x1000C:  strcpy(Business, "$0000C 客户信息查询应答"); break;

    case   0x00008:  strcpy(Business, "$00008 会员资金查询请求"); break;
    case   0x10008:  strcpy(Business, "$10008 会员资金查询应答"); break;

    case   0x00002:  strcpy(Business, "$00002 成交行情查询请求"); break;
    case   0x10002:  strcpy(Business, "$10002 成交行情查询应答"); break;
    case   0x00007:  strcpy(Business, "$00007 按合同编号成交合约查询请求"); break;
    case   0x10007:  strcpy(Business, "$10007 按合同编号成交合约查询应答"); break;
    case   0x03014:  strcpy(Business, "$03014 按成交编号成交合约查询请求"); break;
    case   0x13014:  strcpy(Business, "$13014 按成交编号成交合约查询应答"); break;

    case   0x00009:  strcpy(Business, "$00009 会员持仓查询请求"); break;
    case   0x10009:  strcpy(Business, "$10009 会员持仓查询应答"); break;
    case   0x0000A:  strcpy(Business, "$0000A 会员客户持仓查询请求"); break;
    case   0x1000A:  strcpy(Business, "$1000A 会员客户持仓查询应答"); break;
    case   0x03031:  strcpy(Business, "$03031 会员客户组合持仓查询请求"); break;
    case   0x13031:  strcpy(Business, "$13031 会员客户组合持仓查询应答"); break;

    case   0x10001:  strcpy(Business, "$10001 错误响应"); break;
    case   0x12007:  strcpy(Business, "$12007 合约参数改变通知"); break;
    case   0x12006:  strcpy(Business, "$12006 品种状态改变通知"); break;
    case   0x12003:  strcpy(Business, "$12003 交易所告示广播"); break;
    case   0x12004:  strcpy(Business, "$12004 成交行情"); break;
    case   0x13016:  strcpy(Business, "$13016 组合行情"); break;
    case   0x12005:  strcpy(Business, "$12005 市场状态改变通知"); break;
    case   0x13002:  strcpy(Business, "$13002 报价请求"); break;

    case   0x11003:  strcpy(Business, "$11003 报单状态确认"); break;
    case   0x13041:  strcpy(Business, "$13041 跨期套利确认"); break;
    case   0x13040:  strcpy(Business, "$13040 套期保值确认"); break;
    case   0x13042:  strcpy(Business, "$13042 期权执行确认"); break;

    case   0x11001:  strcpy(Business, "$11001 单边成交回报"); break;
    default:		 strcpy(Business, "不存在的数据包"); break;
    }
}

//将任意一个API数据包按照一定的格式保存到文件中,direction数据流方向(0是发送,1是接收,其它为不记录此标志)
void APIpkgTofile(MsgPackageHandle pkg, int direction)
{
    char		DirectionStr[10] = "";  //数据流方向,是发送还是接受
    char		DataFlowName[10] = "";  //数据流名
    char		filepath[50];           //文件目录
    char		filename[1024];         //文件名
    int			PID;                    //API数据包的PID
    int			FID;                    //API数据包的FID
    char		Business[128];          //数据包名称
    const int	BS = 1024 * 16;         //要写入到文件中的数据大小.可自行调节
    char		buffer[BS];             //要写到文件中的数据,记录数据域的临时变量
    int 		it;                     //指向当前buffer的结尾处(存储buffer长度)

    //存放取到的临时数据
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
        strcpy(DirectionStr, "发送");
        break;
    }
    case 1:
    {
        strcpy(DirectionStr, "接收");
        break;
    }
    }

    //取出数据流标志
    switch (API_GFInt(pkg, FID_DataFlowFlag))
    {
    case 0:
    {
        strcpy(DataFlowName, "对话流");
        break;
    }
    case 1:
    {
        strcpy(DataFlowName, "私有流");
        break;
    }
    case 2:
    {
        strcpy(DataFlowName, "广播流");
        break;
    }
    }

    //下面将API数据包中的数据读出来进行处理然后放到相应的文件中
    PID = API_GetPID(pkg);				//取得数据包PID
    getBussinessname(Business, PID);	//根据PID取得数据包中文名称
    API_DateTime dt;					//存储当前时间的对象
    API_Now(&dt);                       //获取时间,用到API接口函数

    //创建路径
    sprintf(filepath, "%s", "./Record/");

    //创建完整的文件名
    sprintf(filename, "%s%d-%d-%d %d.%d.%d %s %s %s%s", filepath, dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second, DataFlowName, DirectionStr, Business, ".txt");

    //下面创建文件
    std::ofstream f;
    f.open(filename, std::ios::app);
    if (f.fail())
    {
        std::cout << "Fail in opening file!" << std::endl;
        return;
    }

    //将数据包名写入
    it = sprintf(buffer, "------------------------- 报文PID：%s -------------------------\n", Business);

    //下面得到数据包的内容
    FID = API_FirstField(pkg);  //得到数据包中第一个FID
    if (FID > 0)                //有数据域时为真
    {
        do{
            switch (API_CFType(pkg))
            {
            case FTCHAR:
            {
                fvchar = API_CFChar(pkg);
                if (isprint(fvchar))	//若是可打印字符
                    it += sprintf(buffer + it, "%s %c\n", FIDName[FID - 1], fvchar);
                else					//非可打印字符以16进制形式输出
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
                    it += sprintf(buffer + it, "%s %s", FIDName[FID - 1], "取时间出错！\n");
                else
                    it += sprintf(buffer + it, "%s %d-%d-%d %d:%d:%d \n", FIDName[FID - 1], fvdt.year, fvdt.month, fvdt.day, fvdt.hour, fvdt.minute, fvdt.second);
                break;
            }
            default: it += sprintf(buffer + it, "%s %s", FIDName[FID - 1], "未知类型！\n");
            }
            FID = API_NextField(pkg);
        } while (FID > 0);  //一直循环到没有数据域
    }
    //下面将buffer写入文件
    size_t len = strlen(buffer);
    f.write(buffer, len);
    f.close();
}