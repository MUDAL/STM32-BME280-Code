#include "stm32f10x.h"                  // Device header
#include <stdbool.h>
#include "clocks.h"
#include "gpio.h"
#include "systick.h"
#include "system.h"

void System_Init(void)
{
	/*
	Description:
	Initialize system settings and peripherals e.g. clocks,
	system timer, GPIO ports (to a known state).
	
	Parameters:
	None.
	
	Return:
	None.
	*/
	
	Clocks_Init();
	SysTick_Init();
	GPIO_Reset(GPIOB);
}

void System_Timer_DelayMs(uint32_t delayTime)
{
	/*
	Description:
	Delays the program for a specified time in milliseconds.
	
	Parameters:
	1.) delayTime: amount of time (in milliseconds) to wait.
	
	Return:
	None.
	*/
	
	SysTick_DelayMs(delayTime);
}
