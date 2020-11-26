#include "stm32l475xx.h"
#include "blinkled.h"

////////////////////////////////////////////////////////////////////////////////
//
// Description:  Delay function, like sleep
//       Input:  uiCount - while loop increment to uiCount
//      Output:  None
//      Return:  None
//
////////////////////////////////////////////////////////////////////////////////
void vDelay(uint32_t uiCount)
{
  uint32_t uiDelayCount = 0;
  
  while(uiDelayCount < uiCount)
  {
    uiDelayCount++;
  } 
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
  
  uint32_t iCount;
  iCount = 0;
  while (iCount < 10)
  {
    // turn on LED1
    GPIOA->ODR |= GPIO_ODR_OD5;
    vDelay(1000000);
    // turn off LED1
    GPIOA->ODR &= ~GPIO_ODR_OD5;
    vDelay(1000000);
    iCount++;
  }
  return 0;
}
