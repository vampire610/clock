#include"interrupt.h" 



void ZD()
{
	TMOD=0x01;                                //定时器0工作在方式1
	TH0=(65536-1000)/256;           //装初值，1ms
	TL0=(65536-1000)%256;
	EA=1;                  //总中断允许
	ET0=1;                 //T0中断允许
	TR0=1;                 //开定时器0
}


void dingshiqi1() interrupt 1     //中断函数
{
	TH0=(65536-1000)/256;                //重新装初值
    TL0=(65536-1000)%256;
    t++;
    s++;
    flashtime++;
    if(s==1000)
    {
    	time.miao++;
    	s=0;
    }
}

