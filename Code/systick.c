#include "stm32f10x.h"                  // Device header
#include "systick.h"

static volatile uint32_t numberOfTicks = 0;

void SysTick_Init(void)
{
	//Systick default clock source = AHB/8 = 1MHz
	SysTick->LOAD = 1000 - 1; //1ms timebase
	SysTick->VAL = 0;
	//Enable systick interrupt and systick timer
	SysTick->CTRL |= (SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk); 
}

/**
@brief Gets current ticks or number of clock cycles counted by the systick timer.
The tick is equal to the value of the 'numberOfTicks' variable which
is increment by the systick interrupt service routine.

@param None

@return Current tick
*/
uint32_t SysTick_GetTick(void)
{
	return numberOfTicks;
}

/**
@brief Creates a delay in milliseconds  

@param delayTime: time in milliseconds through which the delay
lasts.

@return None
*/
void SysTick_DelayMs(uint32_t delayTime)
{
	uint32_t startTick = numberOfTicks;
	while((numberOfTicks - startTick) < delayTime){}
}

void SysTick_Handler(void)
{
	numberOfTicks++;
}
