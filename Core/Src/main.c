#include "stm32f4xx.h"

// SET BIT 0 IN RCC_AHB1ENR TO 1
#define GPIOA_EN (1<<0) // 0B 0000 0000 0000 0000 0000 0000 0000 0001

// SET BIT 10 TO 1 IN GPIOA_MODER
// SET BIT 11 TO 0 IN GPIOA_MODER
#define MODER_5_OUT (1<<10) // // 0B 0000 0000 0000 0000 0000 0100 0000 0000

// WRITE 1 TO GPIOA_ODR BIT 5 TO SET PA5 ON
#define ODR_5_SET (1<<5)
#define ODR_5_RESET (0<<5)

#define LED_PIN (1<<5)

// WRITE 0 TO SET IT OFF
int main(void)
{
	RCC->AHB1ENR |= GPIOA_EN;
	GPIOA->MODER |= MODER_5_OUT;

	while(1)
	{
		GPIOA->ODR ^= ODR_5_SET;
	}
}
