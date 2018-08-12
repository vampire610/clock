#include"display.h"

sbit dx=P2^0;
sbit wx=P2^1;

uchar code shu[]={               //数码管显示数组
	0x3f,0x06,0x5b,0x4f,
	0x66,0x6d,0x7d,0x07,
	0x7f,0x6f,0x77,0x7c,
	0x39,0x5e,0x79,0x71,
	0x80,0x00};//点，空
uchar code wei[]={0x7f,0xbf,0xdf,0xef,0xf7,0xfb,0xfd,0xfe};

uint t=0;			/*延时计数*/
uchar w=0;			/*扫描循环*/

uchar flash=0;		/*闪烁标志位*/
uint flashtime=0;	/*闪烁延时*/
char flashwei=5;	/*闪烁位*/

void display(uchar *psss)
{

		if(t==5)
		{
			seg=xx;
			wx=1;
			seg=wei[w];
			wx=0;
			if(w==2||w==4)
			{
				dx=1;
				seg=shu[*(psss+w)]|shu[16];
				dx=0;
			}
			else
			{
				dx=1;
				seg=shu[*(psss+w)];
				dx=0;
			}
			w++;
			if(w>=8)w=0;
			t=0;
		}
	
	
}

void display_flash(uchar *pss)
{
	if(flash==1)
	{
		if(flashtime>=500&&flashtime<1000)
		{
			*(pss+flashwei)=17;
		}
		if(flashtime>999)
		{
			flashtime=0;
		}
	}
	else flashtime=0;
}

