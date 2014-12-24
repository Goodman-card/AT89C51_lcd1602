
#include<reg51.h>
#include<stdio.h>
#include"LCM16X2P.H"
#define OSC 11052900

unsigned char ucTH,ucTL,Ticks;

//************************************************************************
//函数名： TOISR
//功能: 50ms中断服务程序
//************************************************************************
void TOISR(void) interrupt 1
{
    TH0 = ucTH;
	TL0 = ucTL;
	TR0 = 1;
	Ticks ++;
	if(Ticks == 20)
	{
	    Ticks = 0;
	   LCM_BLC=!LCM_BLC;
	}
}

//************************************************************************
//函数名: main
//************************************************************************
void main(void)
{
// 初始化
    EA = 0;  //停止所有中断
    Ticks = 0; 
    ucTH = (65536-OSC/12/20)/256; //计算50ms定时的时间常数
    ucTL = (65536-OSC/12/20)%256;
    TMOD = 0x01; //T0: 模式1,16位定时器
    TH0 = ucTH;
    TL0 = ucTL;
    ET0 = 1; //T0 允许中断 
    TR0 = 1; //启动定时器 
	EA = 1;	 //打开总中断允许
	LCMInit();
	LCMClear();
	LCMDisplayString(0,0,"zsq208120734");
	LCMDisplayString(1,0,"Happy Birthday!");
	LCMBlink(1,12,BLINK);
	while(1);   
}

