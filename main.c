#include"main.h"


sbit naoling=P2^7;


void main()
{
	ZD();
	time.shi=12;   //初始时间
	time.fen=00;
	time.miao=00;
	naotime.shi=12;
	naotime.fen=00;
	naotime.miao=03;

    
	while(1)
	{
        Int_Key_Scan();
        keypad();
		jinwei();
        if(setshijian== 1||setnaozhong==1)
        {
        	nicunshuzu(pzset,pset);
            display_flash(pset);
            display(pset);
        }
        else
		{
            zhuancun(ptime,pduan);
            display(pduan);
        }
        if(time.shi==naotime.shi&&time.fen==naotime.fen&&time.miao==naotime.miao&&naozhongflag==1)
        {
        	naoling=0;
        	P3=0x00;
        }
        else if(s==999)
        {
        	naoling=1;
        }
	}
}
