#include "dma.h"
#include "adc.h"

__IO uint16_t ADC_Converter_Value[3*BuffSize];	
uint8_t s = 0;
__IO uint16_t ADC_temp=0;
__IO uint16_t ADC_Filted_Value = 0;
float ADC_ConvertedValue = 0;

uint32_t Given_temp=0;
uint32_t Io_Temp=0;
uint32_t Uo_Temp=0;
uint16_t Given_value = 0;
uint16_t Io_value = 0;
uint16_t Uo_value = 0;

void ADC_Converter_Init(void)
{
	for(uint8_t i = 0; i< 3*BuffSize;i++)
		ADC_Converter_Value[i]=0;
}	
																			 

void ADC_DMA_CONFIG()
{
	ADC_Converter_Init();
	DMA_InitTypeDef DMA_InitStruct;
	
	RCC_AHBPeriphClockCmd(DMA1_CLK_FUN, ENABLE);
	
	DMA_DeInit(DMA_x);
	
	DMA_InitStruct.DMA_PeripheralBaseAddr = (uint32_t)(&(ADC1->DR));
	DMA_InitStruct.DMA_MemoryBaseAddr = (uint32_t)ADC_Converter_Value;
	DMA_InitStruct.DMA_DIR = DMA1_DIR;
	
	
	DMA_InitStruct.DMA_BufferSize = 3*BuffSize ;
	
	DMA_InitStruct.DMA_PeripheralInc = DMA_PeripheralInc_Disable;
	DMA_InitStruct.DMA_PeripheralDataSize = DMA1_Periphere_DataSize;
	
	DMA_InitStruct.DMA_MemoryInc = DMA_MemoryInc_Enable ;
	DMA_InitStruct.DMA_MemoryDataSize = DMA1_Memory_DataSize; 
	
	DMA_InitStruct.DMA_Mode = DMA1_Mode;
	DMA_InitStruct.DMA_Priority = DMA1_Priority ;
	DMA_InitStruct.DMA_M2M = DMA1_M2M ;
	
	DMA_Init(DMA_x, &DMA_InitStruct);
	DMA_Cmd(DMA_x, ENABLE);
}




void ADC_Value_Converter()
{
		for(uint8_t j=0; j<BuffSize;j++)
		{
			Given_temp+=ADC_Converter_Value[3*j];
			Uo_Temp+=ADC_Converter_Value[3*j+1];
			Io_Temp+=ADC_Converter_Value[3*j+2];
		}
		Io_value = (Io_Temp/BuffSize);
		Given_value= 4095-(Given_temp/BuffSize)-ADC_Given_Offset;
		Uo_value = Uo_Temp/BuffSize;

		Io_Temp = 0;
		Given_temp = 0;
		Uo_Temp = 0;		
	
}
