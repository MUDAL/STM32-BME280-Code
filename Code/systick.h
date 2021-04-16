#ifndef _SYSTICK_H
#define _SYSTICK_H

//Initializes the systick timer on the stm32f103
extern void SysTick_Init(void);
//Creates a delay in milliseconds
extern void SysTick_DelayMs(uint32_t delayTime);

#endif //_SYSTICK_H
