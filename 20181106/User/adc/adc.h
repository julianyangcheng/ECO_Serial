#ifndef __adc_h
#define __adc_h

#include "stm32f10x.h"

#define  ADC_GPIO_APBxCLOCK_FUN RCC_APB2PeriphClockCmd
#define ADC_GPIO_CLK RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOC
#define PA7_FOR_SETTING
/*PC1--->Vdis
  PC2--->Idis
	PB1--->Given
*/
/*Uo    ------>PC1   ADC123_IN11
  Io    ------>PC2   ADC123_IN12
	Given ------>PA7   ADC12_IN7
*/
#define ADC_PORT1 GPIOC
#define ADC_GPIO_PIN1 GPIO_Pin_1
#define ADCx_Channel1 ADC_Channel_11

#define ADC_PORT2 GPIOC
#define ADC_GPIO_PIN2 GPIO_Pin_2
#define ADCx_Channel2 ADC_Channel_12

#ifdef PA7_FOR_SETTING
#define ADC_PORT3 GPIOA
#define ADC_GPIO_PIN3 GPIO_Pin_7
#define ADCx_Channel3 ADC_Channel_7
#endif

#ifdef PB1_FOR_SETTING
#define ADC_PORT3 GPIOB
#define ADC_GPIO_PIN3 GPIO_Pin_1
#define ADCx_Channel3 ADC_Channel_9
#endif

#define ADC_APBxCLOCK_FUN RCC_APB2PeriphClockCmd
#define ADCx_CLK RCC_APB2Periph_ADC1


#define ADCx_MODE ADC_Mode_Independent
#define ADCx_DataAlign ADC_DataAlign_Right
#define ADCxTriggerMode ADC_ExternalTrigConv_None
#define ADCxCovNum 3
#define ADCx_Rank1 2
#define ADCx_Rank2 3
#define ADCx_Rank3 1
#define ADCx_SampHold_Cyc ADC_SampleTime_7Cycles5
#define ADC_x ADC1


#define ADC_Clk_Div RCC_PCLK2_Div8


void ADCx_Init(void);
#endif
