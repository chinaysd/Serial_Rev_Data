#include "bsp_key.h"

KEY_PARA_T Key_Para[KEY_NUM];

unsigned char Key_Init(unsigned char ID)
{
	if(ID == 0)
	{
		P2CON &= ~0X01;
		P2PH  |= 0X01;
	}
	else if(ID == 1)
	{
		P2CON &= ~0X02;
		P2PH  |= 0X02;
	}
	else if(ID == 2)
	{
		P2CON &= ~0X10;
		P2PH  |= 0X10;
	}
	else if(ID == 3)
	{
		P2CON &= ~0X20;
		P2PH  |= 0X20;
	}
	else if(ID == 4)
	{
		P2CON &= ~0X40;
		P2PH  |= 0X40;
	}
	else if(ID == 5)
	{
		P1CON &= ~0X10;
		P1PH  |= 0X10;
	}
	else if(ID == 6)
	{
		P1CON &= ~0X20;
		P1PH  |= 0X20;
	}
	else
	{
		return 0;
	}
	return 1;
}

unsigned char Key_App_Init(KEY_PARA_T *p)
{
	unsigned char Key_Init(unsigned char ID);
	return Key_Init(p->ID);
}

unsigned char Key1_Status(void)
{
	if(KEY1_PIN == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned char Key2_Status(void)
{
	if(KEY2_PIN == 0)
	{
	  return 1;
	}
	else
	{
		return 0;
	}
}

unsigned char Key3_Status(void)
{
	if(KEY3_PIN == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned char Key4_Status(void)
{
	if(KEY4_PIN == 0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

unsigned char Key5_Status(void)
{
	if(KEY5_PIN == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned char Key6_Status(void)
{
	if(KEY6_PIN == 0)
	{
		return 1;
	}
	else
	{
		return 0 ;
	}
}

unsigned char Key7_Status(void)
{
	if(KEY7_PIN == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



