#ifndef __CALCULATE_H_
#define __CALCULATE_H_

#include "main.h"


typedef struct 
{
	uchar shi;
	uchar fen;
	uchar miao;
}Time;

extern Time time;                //时间
extern Time *ptime;

extern Time settime;             //设置时间
extern Time *psettime;

extern Time naotime;             //闹钟时间
extern Time *pnaotime;

extern uchar duan[8];
extern uchar set[8];
extern uchar zset[8];
extern uchar *pzset;
extern uchar *pduan;
extern uchar *pset;

extern uint s;			/*时间计数*/

extern uchar  naozhongflag=1;  //闹钟开启标志位
extern uchar  setnaozhong=0;   //设置闹钟标志位
extern uchar  setshijian=0;    //设置时间标志位

extern void nicunshuzu(uchar * pZC,uchar * pSET);
extern void nicun(Time * pTI, uchar *pDU);
extern void jinwei();
extern void zhuancun(Time * pTIME,uchar *pDUAN);
