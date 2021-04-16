#include "stm32f10x.h"                  // Device header
#include "clocks.h"

void Clocks_Init(void)
{
	/*
	Description:
	Initializes all required peripheral clocks.
	
	Parameters:
	None.
	
	Return:
	None.
	*/
	
	while( (RCC->CR & RCC_CR_HSIRDY) != RCC_CR_HSIRDY ); //wait for internal oscillator to be stable
	RCC->CFGR &= ~RCC_CFGR_SW; //use internal oscillator as system clock
	RCC->CFGR &= ~RCC_CFGR_PPRE1; //No APB1 prescaler, run it at 8MHz
	RCC->CR &= ~RCC_CR_PLLON;	//disable PLL
	RCC->CR &= ~RCC_CR_HSEON; //disable external oscillator
	//enable clock access for GPIOB
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	//enable clock for I2C1
	RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
}
