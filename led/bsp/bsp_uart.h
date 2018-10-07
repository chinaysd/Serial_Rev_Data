#ifndef _BSP_UART_H_
#define _BSP_UART_H_

#include "sc92f837x_c.h"

#define UART_ENABLE      1
#define UART_DISABLE     0

#if UART_ENABLE
#define Freq       12
#define baud       9600
#endif

#define BUF_SIZE      6
#define Hight_Data(x)  (((x)>>8)&0xff)
#define Low_Data(x)    ((x)&0xff)
#define Get_Data(x,y)   ((((x)>>8)|y)&0xffff)

typedef struct
{
	unsigned char ADDR;
	//unsigned char ID;
	unsigned char DATA1;
	unsigned char DATA2;
	unsigned char CHECKSUM;
	unsigned char STOP1;
	unsigned char STOP2;
}
DATA_FORMAT_TX;

typedef union
{
	DATA_FORMAT_TX Data_Format_tx;
	unsigned char Buf[BUF_SIZE];
}
PROTOCOL_TX;


void Uart_Init(void);
unsigned char Protocol_Send(unsigned char addr/*,unsigned char id*/,unsigned int ssdat);

//unsigned char Rev_Data(void);
void Rev_Data_Str(void);
unsigned char If_Rev_Over(void);

#endif

