#ifndef __piloteTIMER_h
#define __piloteTIMER_h

#include "stm32f10x.h"

void TimerConf(TIM_TypeDef *tim, uint32_t psc,  uint32_t arr);
void TimerStart(TIM_TypeDef *tim);
void TimerStop(TIM_TypeDef *tim);

void activeIT(TIM_TypeDef *tim, uint8_t prio);

#endif