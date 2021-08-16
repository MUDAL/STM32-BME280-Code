#include "stm32f10x.h"                  // Device header
#include <stdbool.h>
#include "clocks.h"
#include "gpio.h"
#include "systick.h"
#include "system.h"

/**
@brief Initializes all necessary peripherals of the microcontroller
*/
void System_Init(void)
{
	Clocks_Init();
	SysTick_Init();
	GPIO_Reset();
}

void System_TimerDelayMs(uint32_t delayTime)
{
	SysTick_DelayMs(delayTime);
}
