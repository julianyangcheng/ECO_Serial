#ifndef __DAC_H
#define __DAC_H

#include "stm32f10x.h"

#define DAC_GPIO_GROUP GPIOA
#define I_DAC_GPIO_PIN GPIO_Pin_4
#define U_DAC_GPIO_PIN GPIO_Pin_5
#define DAC_GPIO_MODE GPIO_Mode_AIN

#define DAC_TRIGGER DAC_Trigger_None
#define DAC_WAVE DAC_WaveGeneration_None
#define DAC_OUTPUTBUFFER DAC_OutputBuffer_Enable
#define DAC_CHANNEL_I DAC_Channel_1
#define DAC_CHANNEL_U DAC_Channel_2

#define DAC_DATA_ALIGN DAC_Align_12b_R
 
void DAC_Init_Config(void);
#endif
