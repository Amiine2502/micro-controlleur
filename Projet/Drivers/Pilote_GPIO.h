#ifndef __piloteGPIO_h
#define __piloteGPIO_h

#include "stm32f10x.h"

#define OUTPUTPUSHPULL           0x1
#define OUTPUTALTERNATEPUSHPULL  0x9
#define INPOUTFLOATING           0x4
#define INPOUTANALOG             0x0

void InitGPIO(GPIO_TypeDef *PORT, char BROCHE, char CONFIG);
char LireBroche(GPIO_TypeDef *PORT, char BROCHE);
void SetBroche(GPIO_TypeDef *PORT, char BROCHE);
void ResetBroche(GPIO_TypeDef *PORT, char BROCHE);
void ToggleBroche(GPIO_TypeDef *PORT, char BROCHE);

#endif