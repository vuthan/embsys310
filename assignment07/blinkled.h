#ifndef _BLINKLED_H_
#define _BLINKLED_H_

// Global variable for milliseconds count down in SysTickHandler
uint32_t g_uiMillisecondsCountDown = 0;

void vDelay(uint32_t uiDelayInMillisec);


#endif
