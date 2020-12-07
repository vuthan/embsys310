#ifndef _SYSTICK_H_
#define _SYSTICK_H_

// SysTick Interrupt handling prototypes
#define SYSTICK_1MS_COUNTDOWN 4000 // 1 millisecond on 4MHz clock (1 sec 4M cycles) 
uint16_t g_uiSysTick;
void SysTickInitialize(void);
void SysTick_Handler(void);


#endif