#include "bsp_led.h"



unsigned char Led_Init(unsigned char sum)
{
	unsigned char i;
	for(i = 0;i < sum;i++)
	{
		P0CON |= 0X01;
		P0PH  &= ~0X01;
	}
	if(i != sum)
	{
		return LED_ERROR;
	}
	else
	{
		return LED_SUCCESS;
	}
}

void BackCall_Led_Init(unsigned char n,unsigned char (* ptr)(unsigned char))
{
	(* ptr)(n);
}


unsigned char Led_Open(unsigned char Open)
{
	unsigned char j;
	for(j = 0;j < Open;j++)
	{
		Led_Set(Open);
	}
	if(j != Open)
	{
		return LED_ERROR;
	}
	else
	{
		return LED_SUCCESS;
	}
	
}

unsigned char Led_Close(unsigned char Close)
{
	unsigned char z = 1;
	for(z = 1;z >  Close;z--)
	{
		Led_Set(Close);
	}
	if(z != Close)
	{
		return LED_ERROR;
	}
	else
	{
		return LED_SUCCESS;
	}
}


