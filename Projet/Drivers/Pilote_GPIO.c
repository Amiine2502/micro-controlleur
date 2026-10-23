#include "Pilote_GPIO.h"

void InitGPIO(GPIO_TypeDef *PORT, char BROCHE, char CONFIG){
	if(PORT == GPIOA){
		RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	}
	if(PORT == GPIOB){
		RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	}
	if(PORT == GPIOC){
		RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	}
	if(PORT == GPIOD){
		RCC->APB2ENR |= RCC_APB2ENR_IOPDEN;
	}
	if(BROCHE < 8){
		if(CONFIG == OUTPUTPUSHPULL){
			PORT -> CRL &= ~(0xF<<4*BROCHE);
			PORT -> CRL |= 0x1<<4*BROCHE;
		}
		if(CONFIG == OUTPUTALTERNATEPUSHPULL){
			PORT -> CRL &= ~(0xF<<4*BROCHE);
			PORT -> CRL |= 0x9<<4*BROCHE;
		}
		if(CONFIG == INPOUTFLOATING){
			PORT -> CRL &= ~(0xF<<4*BROCHE);
			PORT -> CRL |= 0x4<<4*BROCHE;
		}
		if(CONFIG == INPOUTANALOG){
			PORT -> CRL &= ~(0xF<<4*BROCHE);
			PORT -> CRL |= 0x0<<4*BROCHE;
		}	
	}
	
	if(BROCHE < 16){
		if(CONFIG == OUTPUTPUSHPULL){
			PORT -> CRH &= ~(0xF<<4*BROCHE);
			PORT -> CRH |= 0x1<<4*BROCHE;
		}
		if(CONFIG == OUTPUTALTERNATEPUSHPULL){
			PORT -> CRH &= ~(0xF<<4*BROCHE);
			PORT -> CRH |= 0x9<<4*BROCHE;
		}
		if(CONFIG == INPOUTFLOATING){
			PORT -> CRH &= ~(0xF<<4*BROCHE);
			PORT -> CRH |= 0x4<<4*BROCHE;
		}
		if(CONFIG == INPOUTANALOG){
			PORT -> CRH &= ~(0xF<<4*BROCHE);
			PORT -> CRH |= 0x0<<4*BROCHE;
		}	
	}
}


char LireBroche(GPIO_TypeDef *PORT, char BROCHE){
	if((PORT -> IDR & (1<<BROCHE)) == 0){
		return 0;
	}
	else{
		return 1;
	}
}


void SetBroche(GPIO_TypeDef *PORT, char BROCHE){
	PORT -> ODR |= (1 << BROCHE);
}

void ResetBroche(GPIO_TypeDef *PORT, char BROCHE){
	PORT -> ODR &= ~(1 << BROCHE);
}

void ToggleBroche(GPIO_TypeDef *PORT, char BROCHE){
	PORT -> ODR ^= (1 << BROCHE);	
}



