#include"keypad.h"

uchar  g_uiCurrKey;            //当前按键值
uchar  g_uiLastKey;            //上次按键值
uchar  g_uiKeyScanCount;       //按键扫描计数，作用：消抖动

uchar  g_uiPreKeyValue;        // 上一次的有效按键值
uchar  g_uiKeyDown;            //键被按下，返回的键值。       作用：单次按键，单次返回有效键值；按住不放，也只返回被按下的一个键值
uchar  g_uiKeyRelease;         //键被释放后，返回的键值。     作用：只有按下的按键被释放后，才返回按下的键值
uchar  g_uiKeyContinue;        //键连续按键，重复返回的键值。 作用：只要按住不放，就会重复地返回相同键值

void shezhi(uchar a)
{
    if(setshijian==1||setnaozhong==1)
    {
        zset[flashwei]=a;
        flashwei--;
        if(flashwei==-1)
            flashwei=0;
        flashtime=300;
    }
}

void Backspace()
{
	if(setshijian==1||setnaozhong==1)
    {
        flashwei++;
        if(flashwei>5)
            flashwei=5;
        flashtime=300;
    }
}

void qingchu()
{
	zset[0]=0;
	zset[1]=0;
	zset[2]=0;
	zset[3]=0;
	zset[4]=0;
	zset[5]=0;
	flashwei=5;
}


void querenjian(Time * nao,Time * shij,Time *she)
{

	if(setnaozhong==1)
	{
		nao->miao=she->miao;
		nao->fen=she->fen;
		nao->shi=she->shi;
	}
	else if(setshijian==1)
	{
		shij->miao=she->miao;
		shij->fen=she->fen;
		shij->shi=she->shi;
	}
}

void Int_Key_Scan(void)
{
    static unsigned short LastReadKey;        //上次从IO口读取的键值 ,注意是静态变量
    unsigned short CurrReadKey;               //当前从IO口读取的键值

//---------------------- 需要修改的地方 --------------------------------------//
    unsigned short KeyRow,KeyColumn;

    //读取按键的行数
    P3 = 0xf0;
    KeyRow = P3;

    //读取按键的列数
    P3 = 0x0f;
    KeyColumn = P3;

    P3=0xff;
    //读取行列数，就是当前键值了
    CurrReadKey = KeyRow|KeyColumn;         //获取当前的键值      
    //P3=CurrReadKey;
//-----------------------------------------------------------------------//

    if(CurrReadKey == LastReadKey)            //如果当前读取的键值与上次从IO口读取的键值相同
    {
        if(1/*g_uiKeyScanCount >= KEYDEBOUNCE*/)   //首先判断是否大于等于debounce的设定值(即是，是否大于等于设定的采样次数)
        {
            //按住不放,多次响应
            g_uiCurrKey = CurrReadKey;                //如果是,将当前的读取值判定为有效按键值(如果是，在采样周期中，都是这个值，则判定为有效按键值)
            g_uiKeyContinue = g_uiCurrKey ;           //长按，多次响应 按键值
            //按住不放只响应一次
            if(g_uiPreKeyValue == g_uiCurrKey)
            {
                g_uiKeyDown = 0xff;                    //没有键值
            }
            else
            {
                g_uiKeyDown = g_uiCurrKey;             //如果不同，按键有效,(就是第一次有效值时)
            }

            //按键释放时，按键值才有效     
            if(g_uiCurrKey == 0xff)                  //当有效按键值从非0到0的状态时(即是，从有按键到无按键，表示已经释放了)，表示之前按键已经释放了
            {
                g_uiKeyRelease = g_uiPreKeyValue;
            }

            g_uiPreKeyValue = g_uiCurrKey;               //记录上次有效按键值
        }
        else                                       //如果否，则debounce加一(如果否，则继续采样键值)
        {
            g_uiKeyScanCount++;
        }
    }
    else                                          //如果当前读取的键值与上次从IO口读取的键值不同，说明按键已经变化
    {
        g_uiKeyDown = 0xff;                       //放开按键后第一次进入扫描程序，清零g_uiKeyDown.作用：消除一个BUG（你猜BUG是什么？）
        g_uiKeyScanCount = 0;                     //清零之前的按键的debounce计数
        LastReadKey = CurrReadKey;                //将当前读取的键值记录为上次读取的按键值
    }   
}

void keypad(void)
{
    
        //第一种：KeyDown的使
        //单按时和长按时，都只返回一次有效键值（无需等到按键释放，就可以返回有效键值）
        switch(g_uiKeyDown)
        {
            case 0xEE://7
                       {
                       		shezhi(7);
                       }
                        break;

            case 0xED://8
                        {
                       		shezhi(8);
                       }
                        
                        break;

            case 0xEB://9
                         {
                       		shezhi(9);
                       }
                        
                        break;

            case 0xE7://闹钟开关
            {
                if(naozhongflag==1)naozhongflag=0;
                else if(naozhongflag==0)naozhongflag=1;
            }
                        break;

            case 0xDE://4
                        {
                       		shezhi(4);
                       }
                        break;

            case 0xDD://5
                        {
                       		shezhi(5);
                       }
                        break;

            case 0xDB://6
                        {
                       		shezhi(6);
                       }
                        break;

            case 0xD7://时间设置
            {
            	flashwei=5;
            	zhuancun(ptime,pzset);
                setshijian=1;
                flash=1;
            }
                        break;   

            case 0xBE://1
                       {
                       		shezhi(1);
                       }
                       break;

            case 0xBD://2
                       {
                       		shezhi(2);
                       }
                       break;

            case 0xBB://3
                        {
                       		shezhi(3);
                       }
                       break;

            case 0xB7://闹钟设置
            {
            	flashwei=5;
            	zhuancun(pnaotime,pzset);
                setnaozhong=1;
                flash=1;
             
            }
                       break; 

            case 0x7E://确认    储存设置，退出设置
            {
            	nicun(psettime,pzset);
            	querenjian(pnaotime,ptime,psettime);
                setnaozhong=0;
                setshijian=0;
                flash=0;
                flashwei=0;
            }
                       break;

            case 0x7D://0
                        {
                       		shezhi(0);
                       }
                       break;

            case 0x7B://清除
            			qingchu();
                        break;

            case 0x77://退格
            			Backspace();
                        break;        

            case 0xFF:
                        //没有按键程序
                        //...
                        break;
        }
}

