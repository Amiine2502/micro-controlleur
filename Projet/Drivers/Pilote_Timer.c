#include "Pilote_Timer.h"
#include "Pilote_GPIO.h"


void TimerConf(TIM_TypeDef *tim, uint32_t psc,  uint32_t arr){
	if(tim == TIM1){
		RCC -> APB2ENR |= RCC_APB2ENR_TIM1EN;
		tim -> PSC = psc;
		tim -> ARR = arr;
	}
	if(tim == TIM2){
		RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;
		tim -> PSC = psc;
		tim -> ARR = arr;
	}
	if(tim == TIM3){
		RCC -> APB1ENR |= RCC_APB1ENR_TIM3EN;
		tim -> PSC = psc;
		tim -> ARR = arr;
	}
	if(tim == TIM4){
		RCC -> APB1ENR |= RCC_APB1ENR_TIM4EN;
		tim -> PSC = psc;
		tim -> ARR = arr;
	}			
	
}

void TimerStart(TIM_TypeDef *tim){
	tim -> CR1 |= (0x01);
}

void TimerStop(TIM_TypeDef *tim){
	tim -> CR1 &= ~(0x01);
}

void activeIT(TIM_TypeDef *tim, uint8_t prio){
	//activer le premier bit de DIER pour autoriser la generation d'une interuption	
	tim -> DIER |= 0x01;
	if(tim == TIM1){
		NVIC_SetPriority(TIM1_UP_IRQn,prio);
		NVIC_EnableIRQ(TIM1_UP_IRQn);
	}
	if(tim == TIM2){
		NVIC_SetPriority(TIM2_IRQn,prio);
		NVIC_EnableIRQ(TIM2_IRQn);
	}
	if(tim == TIM3){
		NVIC_SetPriority(TIM3_IRQn,prio);
		NVIC_EnableIRQ(TIM3_IRQn);
	}
	if(tim == TIM4){
		NVIC_SetPriority(TIM4_IRQn,prio);
		NVIC_EnableIRQ(TIM4_IRQn);
	}
}
