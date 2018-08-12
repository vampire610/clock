#include "calculate.h"



Time time;                //时间
Time *ptime=&time;

Time settime;             //设置时间
Time *psettime=&settime;

Time naotime;             //闹钟时间
Time *pnaotime=&naotime;

uchar duan[8]={0,1,2,3,4,5,6,7};
uchar set[8]={0,1,2,3,4,5,6,7};
uchar zset[8]={0,1,2,3,4,5,17,17};
uchar *pzset=zset;
uchar *pduan=duan;
uchar *pset=set;

uint s=0;			/*时间计数*/

uchar  naozhongflag=1;  //闹钟开启标志位
uchar  setnaozhong=0;   //设置闹钟标志位
uchar  setshijian=0;    //设置时间标志位

void nicunshuzu(uchar * pZC,uchar * pSET)
{
	*pSET=*pZC;
	*(pSET + 1)=*(pZC + 1);
	*(pSET + 2)=*(pZC + 2);
	*(pSET + 3)=*(pZC + 3);
	*(pSET + 4)=*(pZC + 4);
	*(pSET + 5)=*(pZC + 5);
	*(pSET + 6)=17;
	*(pSET + 7)=17;
}

void nicun(Time * pTI, uchar *pDU)
{
	pTI->miao = (*pDU) + (*(pDU + 1)) * 10;
	pTI->fen = (*(pDU + 2)) + (*(pDU + 3)) * 10;
	pTI->shi = (*(pDU + 4)) + (*(pDU + 5)) * 10;
}

void jinwei()
{ 
	if(time.miao>=60)
	{
		time.fen++;
		time.miao=0;
	}
	if(time.fen>=60)
	{
		time.shi++;
		time.fen=0;
	}
	if(time.shi>=24)
	{
		time.shi=0;
	}
}

void zhuancun(Time * pTIME,uchar *pDUAN)
{
	*pDUAN=pTIME->miao%10;
	*(pDUAN + 1) = pTIME->miao / 10;
	*(pDUAN + 2) = pTIME->fen % 10;
	*(pDUAN + 3) = pTIME->fen / 10;
	*(pDUAN + 4) = pTIME->shi % 10;
	*(pDUAN + 5) = pTIME->shi / 10;
	*(pDUAN + 6) = 17;
	if(naozhongflag==1)
		*(pDUAN + 7) = 1;
	if(naozhongflag==0)
		*(pDUAN + 7) = 0;
}