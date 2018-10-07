#include "bsp_uart.h"
#include "string.h"

extern unsigned char Uart1SendFlag,Uart1ReceiveFlag;
unsigned char Res_Num,Sum;
unsigned char Rev_Data_Arr[10];

void Uart_Init(void)
{
	P1CON |= 0X08;
	P1PH  &= ~0X08;
	
	OTCON = 0xC0;    //串行接口SSI选择Uart1通信
	SSCON0 = 0x50;   //设置通信方式为模式一，允许接收
	SSCON1 = Freq*1000000/baud;   //波特率低位控制
	SSCON2 = (Freq*1000000/baud)>>8;   //波特率高位控制
	IE1 = 0x01;      //开启SSI中断
  EA = 1;	
}

static void Send_Data(unsigned char DATA)
{
	SSDAT = DATA;
	while(!Uart1SendFlag);
	Uart1SendFlag = 0;
}

static unsigned char Send_Byte(PROTOCOL_TX *p)
{
	unsigned char i;
	for(i = 0;i < BUF_SIZE;i++)
	{
		Send_Data(p->Buf[i]);
	}
	return 1;
}

unsigned char Protocol_Send(unsigned char addr/*,unsigned char id*/,unsigned int ssdat)
{
	PROTOCOL_TX buf;
	memset(&buf,0,sizeof(buf));
	buf.Data_Format_tx.ADDR     = addr;
	//buf.Data_Format_tx.ID       = id;
	buf.Data_Format_tx.DATA1    = Hight_Data(ssdat);
	buf.Data_Format_tx.DATA2    = Low_Data(ssdat);
	buf.Data_Format_tx.CHECKSUM = (unsigned char)((buf.Data_Format_tx.ADDR)/*+(buf.Data_Format_tx.ID)*/+(buf.Data_Format_tx.DATA1)+(buf.Data_Format_tx.DATA2));
	buf.Data_Format_tx.STOP1    = 0X0D;
	buf.Data_Format_tx.STOP2    = 0X0A;
	return Send_Byte(&buf);
}



unsigned char If_Rev_Over(void)
{
	if(Res_Num & 0x80)
	{
		Res_Num &= 0x00;
		return 1;
	}
	else
	{
		return 0;
	}
}

static unsigned char Rev_Data(void)
{
	unsigned char RX_DATA;
	RX_DATA = SSDAT;
	return RX_DATA;
}

void Rev_Data_Str(void)
{
	static unsigned char Rx_Data;
	Rx_Data = Rev_Data();
	if((Res_Num & 0x80) == 0)
	{
    if(Res_Num & 0x40)
		{
			if(Rx_Data == 0xfb)
			{
				Res_Num |= 0x80;
			}
			else
			{
				Res_Num &= 0x00;
			}
		}	
    else
		{
			if(Rx_Data == Sum)
			{
				Res_Num |= 0x40;
			}
			else
			{
				Rev_Data_Arr[Res_Num] = Rx_Data;
				Res_Num ++;
				Sum = (unsigned char)(Rev_Data_Arr[0]+Rev_Data_Arr[1]+Rev_Data_Arr[2]+Rev_Data_Arr[3]
					                    +Rev_Data_Arr[4]+Rev_Data_Arr[5]+Rev_Data_Arr[6]+Rev_Data_Arr[7]+Rev_Data_Arr[8]);
				if(Rev_Data_Arr[0] != 0xfa)
				{
					Res_Num &= 0x00;
				}
//				if(Rev_Data_Arr[1] != 0xfa)
//				{
//					Res_Num &= 0x00;
//				}
				if(Res_Num > 10)
				{
					Res_Num &= 0x00;
				}
			}
		}			
	}
}










