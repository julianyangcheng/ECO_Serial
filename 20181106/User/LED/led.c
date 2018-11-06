#include "led.h"

void status_led_gpio_config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | 
	                       RCC_APB2Periph_GPIOC |
	                       RCC_APB2Periph_GPIOD, ENABLE);
	
	
	GPIO_InitStruct.GPIO_Pin = run_status_led_gpio_pin;
	GPIO_InitStruct.GPIO_Mode = run_status_led_gpio_mode;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(run_status_led_gpio_port, &GPIO_InitStruct);
	

	
	//GPIO_SetBits(run_status_led_gpio_port, run_status_led_gpio_pin); 

}


/*********************************************END OF FILE**********************/
