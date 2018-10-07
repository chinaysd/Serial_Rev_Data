#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include "sc92f837x_c.h"
#include "bsp_led.h"
#include "bsp_key.h"
#include "bsp_uart.h"
#include "TimeOut.h"
#include "bsp_timer.h"
#include "string.h"



#define OnLine_Time      100


void System_Init(void);
void System_Handle(void);





#endif