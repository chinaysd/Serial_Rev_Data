#include "system.h"

extern KEY_PARA_T Key_Para[KEY_NUM];
extern unsigned char Rev_Data_Arr[10];
unsigned char Uart1SendFlag,Uart1ReceiveFlag;
unsigned int temp;

TIMEOUT_PARA TIMEOUT_Para[2];

void System_Init(void)
{
	 static unsigned char key_number;
	
	 TimeOutDet_Init();
	
   BackCall_Led_Init(LED_NUM,Led_Init);	
   Led_Close(LED_STATUS_CLOSE);
	
	 for(key_number = 0;key_number < KEY_NUM;key_number++)
	 {
		 Key_Para[key_number].ID = key_number;
		 Key_App_Init(&Key_Para[key_number]);
	 }
	 WDTCON |= 0X10;
	 Uart_Init();
	 Timer_Init();	 
}

void System_Handle(void)
{
	WDTCON |= 0X10;
	if(TimeOutDet_Check(&TIMEOUT_Para[0]))
	{
		TimeOut_Record(&TIMEOUT_Para[0],OnLine_Time);
		
	}
	if(Key1_Status())
	{
		Led_Open(LED_STATUS_OPEN);
		Protocol_Send(0x55,0x01);
	}
	else if(Key2_Status())
	{
		Led_Open(LED_STATUS_OPEN);
		Protocol_Send(0x55,0x01);
	}
	else if(Key3_Status())
	{
		Led_Open(LED_STATUS_OPEN);
		Protocol_Send(0x55,0x01);
	}
	else if(Key4_Status())
	{
		Led_Open(LED_STATUS_OPEN);
		Protocol_Send(0x55,0x01);
	}
	else if(Key5_Status())
	{
		Led_Open(LED_STATUS_OPEN);
		Protocol_Send(0x55,0x01);
	}
	else if(Key6_Status())
	{
		Led_Open(LED_STATUS_OPEN);
		Protocol_Send(0x55,0x01);
	}
	else if(Key7_Status())
	{
		Led_Open(LED_STATUS_OPEN);
		Protocol_Send(0x55,0x01);
	}
	else
	{
		//Led_Close(LED_STATUS_CLOSE);
	}
	//temp = Rev_Data();
	
	if(If_Rev_Over())
	{
		temp = (unsigned int)(Get_Data(Rev_Data_Arr[1],Rev_Data_Arr[2]));
		memset(&Rev_Data_Arr,0,sizeof(Rev_Data_Arr));
		switch (temp)
		{
			case 0x01:
								Led_Open(LED_STATUS_OPEN);
								break;
			case 0x02:
								Led_Close(LED_STATUS_CLOSE);
								break;
			case 0x04:
								Led_Open(LED_STATUS_OPEN);
								break;
			default:
								break;
		}
	}
		
}

/*****************************************************
*函数名称：void TWI_Int() interrupt 7
*函数功能：SSI中断函数
*入口参数：void
*出口参数：void
*****************************************************/

void Uart1_Int() interrupt 7   //Uart1中断函数
{
	Rev_Data_Str();
	if(SSCON0&0x02)    //发送标志位判断
	{
		SSCON0 &= 0xFD;
		Uart1SendFlag = 1;
	}
	if((SSCON0&0x01))  //接收标志位判断
	{
		SSCON0 &= 0xFE;
		Uart1ReceiveFlag = 1;
	}	
}

/**************************************************
*函数名称：void timer0/1/2() interrupt 1/3/5
*函数功能：定时器中断产生方波
*入口参数：void
*出口参数：void
**************************************************/
void timer0() interrupt 1
{
  TL0 = (65536 - 6000)%256;
	TH0 = (65536 - 6000)/256;
	//P13 = ~P13;
	TimeOutDet_DecHandle();
	
}

void timer1() interrupt 3
{
	
}

void Timer2Int(void) interrupt 5
{		
	TF2 = 0;   //溢出清零
 
}



