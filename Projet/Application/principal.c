#include "stm32f10x.h"
#include "Pilote_GPIO.h"
#include "Pilote_Timer.h"


// Fréquences des notes (en Hz) - de DO4 à DO5
#define DO4   262
#define RE4   294
#define MI4   330
#define FA4   349
#define SOL4  392
#define LA4   440
#define SI4   494
#define DO5   523

/*
void TIM2_IRQHandler(void)
	{	
		// Vérifier le flag d'interruption
		if((TIM2->SR & 0x1) == 1)
			{
			ToggleBroche(GPIOA, 5);
			TIM2->SR &= ~(0x01<<0);
			}	
	}
	*/
void TIM2_IRQHandler(void)
	{	
		float duty = 0.0;
		float step = 0.01;
		// Vérifier le flag d'interruption
		if((TIM2->SR & 0x1) == 1)
			{
				duty += step;
				if(duty >= 1.0){
				}
				else if(){
				}
			SetDutyCycleTim2CH3(0.2);
			TIM2->SR &= ~(0x01<<0);
			}	
	}

int main ( void )
{
	InitGPIO(GPIOB, 5, OUTPUTALTERNATEPUSHPULL);//Activer l'horloge du la broche PA2
	TimerConf(TIM3, 71,  19999);
	TimerStart(TIM3);
	InitTim2IT();
	InitTimPWM(TIM3);
	SetDutyCycleTim2CH3(0.2);
	
	//Config Diode
	/*InitGPIO(GPIOA, 5, OUTPUTPUSHPULL);
	TimerConf(TIM2, 3599, 9999);
	TimerStart(TIM2);
	activeIT(TIM2, 0);
*/
	
	
	while (1)
	{
	
	}
}
