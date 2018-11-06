#include "dac.h"

static void dac_config(void)
{
	DAC_InitTypeDef DAC_InitStruct;
	GPIO_InitTypeDef GPIO_InitStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_DAC, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = I_DAC_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode =DAC_GPIO_MODE ;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DAC_GPIO_GROUP,&GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = U_DAC_GPIO_PIN;
	GPIO_InitStruct.GPIO_Mode =DAC_GPIO_MODE ;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(DAC_GPIO_GROUP,&GPIO_InitStruct);	
	
	DAC_InitStruct.DAC_Trigger = DAC_TRIGGER;
	DAC_InitStruct.DAC_WaveGeneration = DAC_WAVE;
	DAC_InitStruct.DAC_OutputBuffer = DAC_OUTPUTBUFFER;
	
	DAC_Init(DAC_CHANNEL_I, &DAC_InitStruct);
	DAC_Init(DAC_CHANNEL_U, &DAC_InitStruct);
	
	DAC_Cmd(DAC_CHANNEL_I, ENABLE);
	DAC_Cmd(DAC_CHANNEL_U, ENABLE);
	
	DAC_SetDualChannelData(DAC_DATA_ALIGN, 0, 0);
}
static void DAC_TIM_Config(void)
{
	
	TIM_TimeBaseInitTypeDef    TIM_TimeBaseStructure;
	
	/* 使能TIM2时钟，TIM2CLK 为72M */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	
  /* TIM2基本定时器配置 */
 // TIM_TimeBaseStructInit(&TIM_TimeBaseStructure); 
  TIM_TimeBaseStructure.TIM_Period = (20-1);       									//定时周期 20  
  TIM_TimeBaseStructure.TIM_Prescaler = 0x0;       							//预分频，不分频 72M / (0+1) = 72M
  TIM_TimeBaseStructure.TIM_ClockDivision = 0x0;    						//时钟分频系数
  TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  	//向上计数模式
  TIM_TimeBaseInit(TIM2, &TIM_TimeBaseStructure);

  /* 配置TIM2触发源 */
  TIM_SelectOutputTrigger(TIM2, TIM_TRGOSource_Update);

	/* 使能TIM2 */
  TIM_Cmd(TIM2, ENABLE);

}

void DAC_Init_Config()
{
	dac_config();
	DAC_TIM_Config();

}
