#include "key.h"

void key_gpio_config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = key0_gpio_pin | key1_gpio_pin;
	GPIO_InitStruct.GPIO_Mode = key0_1_gpio_mode;
	GPIO_InitStruct.GPIO_Speed = key0_1_gpio_speed;
	GPIO_Init(key0_1_gpio_proup, &GPIO_InitStruct);
}
