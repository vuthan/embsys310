#include "stm32l475xx.h"
#include "blinkled.h"
#include "systick.h"

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Delay function, like sleep
//       Input:  uiDelayInMillisec - in millisecond
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vDelay(uint32_t uiDelayInMillisec)
{
  g_uiMillisecondsCountDown = uiDelayInMillisec;
  
  while(g_uiMillisecondsCountDown);

}

// program start
int main()
{
  // enable GPIOA port clock
  RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
  // set GPIOA pin5 mode to output, LED1 is tied to GPIOA pin5
  // Output mode is 01 
  GPIOA->MODER |= GPIO_MODER_MODE5_0;
  GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
  
  // Initialize and enable SysTick
  SysTickInitialize();
    
  uint32_t iCount;
  iCount = 0;
  while (iCount < 20)
  {
    // turn on LED1 for 1second
    GPIOA->ODR |= GPIO_ODR_OD5;
    vDelay(1000);
    // turn off LED1 for 1second
    GPIOA->ODR &= ~GPIO_ODR_OD5;
    vDelay(1000);
    iCount++;
  }
  
  return 0;
}

////////////////////////////////////////////////////////////////////////////////
//
// Description:  SysTick_Handler() - SysTick Interrupt Handler to handle systick 
//               interrupt, count down global variable g_uiMillisecondsCountDown 
//               if set
//       Input:  None
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void SysTick_Handler(void)
{
  __disable_irq();
  
  if (g_uiMillisecondsCountDown > 0)
  {
    g_uiMillisecondsCountDown -= 1;
  }
  __enable_irq();
  
}

////////////////////////////////////////////////////////////////////////////////
//
// Description:  SysTickInitialize() - Initialize SysTick Registers so SysTick
//               generates SysTick interrupt every 1 millisecond.
//       Input:  None
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void SysTickInitialize(void)
{
  SysTick->LOAD = SYSTICK_1MS_COUNTDOWN - 1;    // Count down from 4000
  SysTick->VAL = 0x0;
  SysTick->CTRL = SysTick_CTRL_ENABLE_Msk |     // Enable SysTick
                  SysTick_CTRL_TICKINT_Msk |    // Enable SysTick Interrupt
                  SysTick_CTRL_CLKSOURCE_Msk;   // Use Processor clock (AHB) source
}

