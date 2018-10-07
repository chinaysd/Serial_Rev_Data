#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "sc92f837x_c.h"

#define LED_NUM           1
#define LED_STATUS_OPEN   1
#define LED_STATUS_CLOSE  0

#define LED_ENABLE        1
#define LED_DISABLE       0

#define LED_ERROR         0
#define LED_SUCCESS       1

#if     LED_ENABLE
#define LED_PORT          P0
#define LED_PIN           P00
#define Led_Set(x)        ((x)?(LED_PIN=1):(LED_PIN=0))
#endif


unsigned char Led_Init(unsigned char sum);
unsigned char Led_Open(unsigned char Open);
unsigned char Led_Close(unsigned char Close);
void BackCall_Led_Init(unsigned char n,unsigned char (* ptr)(unsigned char));



#endif