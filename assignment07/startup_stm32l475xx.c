#include "stm32l4xx_it.h"

#pragma section="CSTACK"

void __iar_program_start(void);
void NotUsedHandler(void);


int const __vector_table[] @ ".intvec" = {
    (int) __section_end("CSTACK"),      // initial sp value
    (int) __iar_program_start,          // Reset Handler
    (int)NMI_Handler,                   // Non-Maskable Interrupt Handler
    (int)HardFault_Handler,             // HardFault Handler
    (int)MemManage_Handler,             // Memory Management Fault Handler
    (int)BusFault_Handler,              // Bus Fault Handler
    (int)UsageFault_Handler,            // Usage Fault Handler
    0,          // Reserved
    0,          // Reserved
    0,          // Reserved
    0,          // Reserved
    (int)&SVC_Handler,                   // SVCall Handler
    (int)&DebugMon_Handler,              // Debug Monitor Handler
    0,          // Reserved
    (int)&PendSV_Handler,                // Pending SV Handler
    (int)&SysTick_Handler                // SysTick Interrupt Handler
};

void NotUsedHandler(void)
{
  while(1);
}

void NMI_Handler(void)
{
  NotUsedHandler();
}
void HardFault_Handler(void)
{
  NotUsedHandler();
}
void MemManage_Handler(void)
{
  NotUsedHandler();
}
void BusFault_Handler(void)
{
  NotUsedHandler();
}
void UsageFault_Handler(void)
{
  NotUsedHandler();
}
#pragma weak SVC_Handler=NotUsedHandler
#pragma weak DebugMon_Handler=NotUsedHandler
#pragma weak PendSV_Handler=NotUsedHandler

