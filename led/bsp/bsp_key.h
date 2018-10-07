#ifndef _BSP_KEY_H_
#define _BSP_KEY_H_

#include "sc92f837x_c.h"

#define KEY_NUM        7

#define KEY_ENABLE     1
#define KEY_DISABLE    0

#if KEY_ENABLE

#define KEY1_PORT      P2
#define KEY1_PIN       P20

#define KEY2_PORT      P2
#define KEY2_PIN       P21

#define KEY3_PORT      P2
#define KEY3_PIN       P24

#define KEY4_PORT      P2
#define KEY4_PIN       P25

#define KEY5_PORT      P2
#define KEY5_PIN       P26

#define KEY6_PORT      P1
#define KEY6_PIN       P14

#define KEY7_PORT      P1
#define KEY7_PIN       P15

#endif

typedef struct
{
	unsigned char ID;
}
KEY_PARA_T;

unsigned char Key_App_Init(KEY_PARA_T *p);

unsigned char Key1_Status(void);
unsigned char Key2_Status(void);

unsigned char Key3_Status(void);
unsigned char Key4_Status(void);

unsigned char Key5_Status(void);
unsigned char Key6_Status(void);

unsigned char Key7_Status(void);

	

#endif


