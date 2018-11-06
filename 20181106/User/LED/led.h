#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

#define run_status_led_gpio_port GPIOC
#define run_status_led_gpio_pin GPIO_Pin_3
#define run_status_led_gpio_mode GPIO_Mode_Out_PP

#define mode_status_led_gpio_port GPIOC
#define mode_status_led_gpio_pin GPIO_Pin_1
#define mode_status_led_gpio_mode GPIO_Mode_Out_PP

/* 直接操作寄存器的方法控制IO */
#define	digitalHi(p,i)		 {p->BSRR=i;}	 //输出为高电平		
#define digitalLo(p,i)		 {p->BRR=i;}	 //输出低电平
#define digitalToggle(p,i) {p->ODR ^=i;} //输出反转状态

/* 定义控制IO的宏 */
#define run_status_led_TOGGLE		 digitalToggle(run_status_led_gpio_port,run_status_led_gpio_pin)
#define run_status_led_OFF		   digitalHi(run_status_led_gpio_port,run_status_led_gpio_pin)
#define run_status_led_ON			   digitalLo(run_status_led_gpio_port,run_status_led_gpio_pin)

#define mode_status_led_TOGGLE		 digitalToggle(mode_status_led_gpio_port,mode_status_led_gpio_pin)
#define mode_status_led_OFF		     digitalHi(mode_status_led_gpio_port,mode_status_led_gpio_pin)
#define mode_status_led_ON			   digitalLo(mode_status_led_gpio_port,mode_status_led_gpio_pin)

void status_led_gpio_config(void);
#endif //__LED_H
