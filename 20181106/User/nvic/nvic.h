#ifndef __NVIC_H
#define __NVIC_H

#include "stm32f10x.h"
#include "misc.h"

extern __IO uint8_t run_status;
extern __IO uint8_t mode_status;

/*
stop/run   ------------> PA0
CC/CV      ------------> PA3
Local/Remote ----------> PC4
Timer      ------------> PB2

*/

#define KEY3_INT_GPIO_PORT         GPIOA
#define KEY3_INT_GPIO_CLK          (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)
#define KEY3_INT_GPIO_PIN          GPIO_Pin_0
#define KEY3_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOA
#define KEY3_INT_EXTI_PINSOURCE    GPIO_PinSource0
#define KEY3_INT_EXTI_LINE         EXTI_Line0
#define KEY3_INT_EXTI_IRQ          EXTI0_IRQn

#define KEY3_IRQHandler            EXTI0_IRQHandler

#define KEY4_INT_GPIO_PORT         GPIOA
#define KEY4_INT_GPIO_CLK          (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)
#define KEY4_INT_GPIO_PIN          GPIO_Pin_1
#define KEY4_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOA
#define KEY4_INT_EXTI_PINSOURCE    GPIO_PinSource1
#define KEY4_INT_EXTI_LINE         EXTI_Line1
#define KEY4_INT_EXTI_IRQ          EXTI1_IRQn

#define KEY4_IRQHandler            EXTI1_IRQHandler

#define KEY0_INT_GPIO_PORT         GPIOA
#define KEY0_INT_GPIO_CLK          (RCC_APB2Periph_GPIOA|RCC_APB2Periph_AFIO)
#define KEY0_INT_GPIO_PIN          GPIO_Pin_3
#define KEY0_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOA
#define KEY0_INT_EXTI_PINSOURCE    GPIO_PinSource3
#define KEY0_INT_EXTI_LINE         EXTI_Line3
#define KEY0_INT_EXTI_IRQ          EXTI3_IRQn

#define KEY0_IRQHandler            EXTI3_IRQHandler


#define KEY1_INT_GPIO_PORT         GPIOC
#define KEY1_INT_GPIO_CLK          (RCC_APB2Periph_GPIOC|RCC_APB2Periph_AFIO)
#define KEY1_INT_GPIO_PIN          GPIO_Pin_4
#define KEY1_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOC
#define KEY1_INT_EXTI_PINSOURCE    GPIO_PinSource4
#define KEY1_INT_EXTI_LINE         EXTI_Line4
#define KEY1_INT_EXTI_IRQ          EXTI4_IRQn

#define KEY1_IRQHandler            EXTI4_IRQHandler

#define KEY2_INT_GPIO_PORT         GPIOB
#define KEY2_INT_GPIO_CLK          (RCC_APB2Periph_GPIOB|RCC_APB2Periph_AFIO)
#define KEY2_INT_GPIO_PIN          GPIO_Pin_2
#define KEY2_INT_EXTI_PORTSOURCE   GPIO_PortSourceGPIOB
#define KEY2_INT_EXTI_PINSOURCE    GPIO_PinSource2
#define KEY2_INT_EXTI_LINE         EXTI_Line2
#define KEY2_INT_EXTI_IRQ          EXTI2_IRQn

#define KEY2_IRQHandler            EXTI2_IRQHandler




void EXTI_Key_Config(void);
#endif //__NVIC_H
