/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
			

void delay(int counter) {
	int i;
	for(i = 0; i < counter * 10000; i++) {}
}


int main(void)
{
	GPIO_InitTypeDef gpio;


	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);


	GPIO_StructInit(&gpio);
	gpio.GPIO_Pin = GPIO_Pin_15;
	gpio.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_Init(GPIOD, &gpio);


	GPIO_SetBits(GPIOD, GPIO_Pin_15);


	for(;;) {
		GPIO_SetBits(GPIOD, GPIO_Pin_15);
		delay(400);
		GPIO_ResetBits(GPIOD, GPIO_Pin_15);
		delay(400);
	}
}
