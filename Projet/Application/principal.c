#include "stm32f10x.h"
#include "Pilote_GPIO.h"
#include "Pilote_Timer.h"


void TIM2_IRQHandler(void)
	{	
		if((TIM2->SR & 0x1) == 1)
			{
			ToggleBroche(GPIOA, 5);
			TIM2->SR &= ~(0x01<<0);
			}	
	}
void InitTim1PWMCH3(void)
{
	TIM1 -> CCR3 |= (0x1<<15);
	TIM1 -> BDTR |= (0x1<<15);
}
int main ( void )
{
	//Config Diode
	InitGPIO(GPIOA, 5, OUTPUTPUSHPULL);
	TimerConf(TIM2, 3599, 9999);
	TimerStart(TIM2);
	activeIT(TIM2, 0);

	while (1)
	{
	
	}
}
