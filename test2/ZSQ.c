
#include<reg51.h>
#include<stdio.h>
#include"LCM16X2P.H"
#define OSC 11052900

unsigned char ucTH,ucTL,Ticks;

//************************************************************************
//�������� TOISR
//����: 50ms�жϷ������
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
//������: main
//************************************************************************
void main(void)
{
// ��ʼ��
    EA = 0;  //ֹͣ�����ж�
    Ticks = 0; 
    ucTH = (65536-OSC/12/20)/256; //����50ms��ʱ��ʱ�䳣��
    ucTL = (65536-OSC/12/20)%256;
    TMOD = 0x01; //T0: ģʽ1,16λ��ʱ��
    TH0 = ucTH;
    TL0 = ucTL;
    ET0 = 1; //T0 �����ж� 
    TR0 = 1; //������ʱ�� 
	EA = 1;	 //�����ж�����
	LCMInit();
	LCMClear();
	LCMDisplayString(0,0,"zsq208120734");
	LCMDisplayString(1,0,"Happy Birthday!");
	LCMBlink(1,12,BLINK);
	while(1);   
}

