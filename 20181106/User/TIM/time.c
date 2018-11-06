#include "pbdata.h"

timer_t Timer2_T;
timer_t Timer3_T;

/*RTU 的工程模板中，TIME2 用作 数据结束的检测*/
void TIME2_Init(u16 prd,u16 psc)
{
	NVIC_InitTypeDef    NVIC_InitStruct;
	TIM_TimeBaseInitTypeDef     TIM_TimeBaseInitStruct;	 	
	
	TIM_TimeBaseInitStruct.TIM_Period=prd;
	TIM_TimeBaseInitStruct.TIM_Prescaler=psc; 
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_InitStruct.NVIC_IRQChannel=TIM2_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStruct);

//	TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
//	TIM_Cmd(TIM2, ENABLE);
}

void TIME3_Init(u16 prd,u16 psc)
{
	NVIC_InitTypeDef    NVIC_InitStruct;
	TIM_TimeBaseInitTypeDef     TIM_TimeBaseInitStruct;	 

	TIM_TimeBaseInitStruct.TIM_Period=prd;
	TIM_TimeBaseInitStruct.TIM_Prescaler=psc; 
	TIM_TimeBaseInitStruct.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitStruct.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStruct);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

	NVIC_InitStruct.NVIC_IRQChannel=TIM3_IRQn;
	NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=0;
	NVIC_InitStruct.NVIC_IRQChannelSubPriority=1;
	NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
	NVIC_Init(&NVIC_InitStruct);

	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	TIM_Cmd(TIM3, ENABLE);
}

