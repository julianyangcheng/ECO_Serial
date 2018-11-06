#include "adc.h"
//#include "misc.h"

static void ADCx_GPIO_CONFIG(void)
{
	/*GPIO结构体声明*/
	GPIO_InitTypeDef GPIO_InitStruct;
	/*是能GPIO外设时钟*/
	ADC_GPIO_APBxCLOCK_FUN (ADC_GPIO_CLK, ENABLE);
	/*GPIO配置*/
	GPIO_InitStruct.GPIO_Pin = ADC_GPIO_PIN1;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN;            //模拟输入模式      //输入模式下不用配置GPIO速度
	GPIO_Init(ADC_PORT1, &GPIO_InitStruct); 
	
	GPIO_InitStruct.GPIO_Pin = ADC_GPIO_PIN2;
	GPIO_Init(ADC_PORT2, &GPIO_InitStruct);  
		

	/*初始化GPIO PA7*/
	GPIO_InitStruct.GPIO_Pin = ADC_GPIO_PIN3; 
	GPIO_Init(ADC_PORT3, &GPIO_InitStruct); 
		
}

static void ADC_Mode_Config(void)
{
	/*ADC结构体声明*/
	ADC_InitTypeDef ADC_InitStruct;
	/*打开ADC外设时钟*/
	ADC_APBxCLOCK_FUN (ADCx_CLK, ENABLE);
	/*ADC模式配置*/
	ADC_InitStruct.ADC_Mode = ADCx_MODE;   
	ADC_InitStruct.ADC_ScanConvMode = ENABLE ;	
	ADC_InitStruct.ADC_DataAlign = ADCx_DataAlign;
	
	ADC_InitStruct.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStruct.ADC_ExternalTrigConv = ADCxTriggerMode;
	ADC_InitStruct.ADC_NbrOfChannel = ADCxCovNum;
	/*初始化ADC外设*/
	ADC_Init(ADC_x, &ADC_InitStruct);
	/*ADC时钟分频设置*/
	RCC_ADCCLKConfig(ADC_Clk_Div);
	/*ADC组，通道，个数，采样保持时间设置*/
	ADC_RegularChannelConfig(ADC_x,ADCx_Channel1, ADCx_Rank1, ADCx_SampHold_Cyc);
	ADC_RegularChannelConfig(ADC_x,ADCx_Channel2, ADCx_Rank2, ADCx_SampHold_Cyc);
	ADC_RegularChannelConfig(ADC_x,ADCx_Channel3, ADCx_Rank3, ADCx_SampHold_Cyc);
	/*DMA使能*/
	ADC_DMACmd(ADC_x, ENABLE);
	/*ADC使能*/
	ADC_Cmd(ADC_x, ENABLE);
		// 初始化ADC 校准寄存器  
	ADC_ResetCalibration(ADC_x);
	// 等待校准寄存器初始化完成
	while(ADC_GetResetCalibrationStatus(ADC_x));
	/*ADC校准*/
	ADC_StartCalibration(ADC_x);
	while(ADC_GetCalibrationStatus(ADC_x));
	/*ADC软件触发使能*/
	ADC_SoftwareStartConvCmd(ADC_x, ENABLE);
	
}


void ADCx_Init(void)
{
	
	ADCx_GPIO_CONFIG();
	ADC_Mode_Config();
	
}
