#ifndef _SYSTICK_H_
#define _SYSTICK_H_

// SysTick Interrupt handling prototypes
#define SYSTICK_1MS_COUNTDOWN 4000 // 1 millisecond on 4MHz clock (1 sec 4M cycles) 
void SysTickInitialize(void);
void SysTick_Handler(void);


#endif