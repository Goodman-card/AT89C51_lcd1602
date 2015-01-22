#include<reg51.h>
#define uchar unsigned char
#define uint unsigned int 
uchar code table1[]=" ZhuShiqi208120734";
uchar code table2[]=" Happybirthy to me!";
sbit RS=P1^0;
sbit RW=P1^1;
sbit E=P1^2;	
void delay(uint ms)
{
uint n;
for(;ms>0;ms--)
for(n=124;n>0;n--);
}
/*写指令*/
void write_Instruction(uchar Instruction)
{
RS=0;
RW=0;
E=0;
P0=Instruction;
delay(1);
E=1;
delay(1);
E=0;
}
/*写数据*/
void write_Data(uchar Data)
{
RS=1;
RW=0;
E=0;
P0=Data;
delay(5);
E=1;
delay(5);
E=0;
}
/*初始化*/
void Init()
{
delay(15);
write_Instruction(0x38);
delay(5);
write_Instruction(0x38);
delay(5);
write_Instruction(0x38);
delay(5);
write_Instruction(0x38);
write_Instruction(0x38);
write_Instruction(0x08);
write_Instruction(0x01);
write_Instruction(0x06);
write_Instruction(0x0c);
}
void left_move()
{
uchar i;
for(i=0;i<16;i++)
{
write_Instruction(0x18);
delay(3000);
}
}
void main()
{
uchar i;
Init();
while(1)
{
write_Instruction(0x80);

for(i=0;i<19;i++)
{
write_Data(table1[i]);
delay(5);
}

write_Instruction(0x80+0x40);
for(i=0;i<20;i++)
{
write_Data(table2[i]);
delay(5);
}
left_move();
}
} 
