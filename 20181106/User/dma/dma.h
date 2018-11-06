#ifndef __dma_h
#define __dma_h

#include "stm32f10x.h"

//DAC DHR12RD寄存器，12位、右对齐、双通道
#define DAC_DHR12RD_ADDRESS      (DAC_BASE+0x20) 
//#define BuffSize 1
#define BuffSize 50
#define DMA_x DMA1_Channel1

#define DMA1_CLK_FUN RCC_AHBPeriph_DMA1
#define DMA1_DIR  DMA_DIR_PeripheralSRC
#define DMA1_Periphere_DataSize DMA_PeripheralDataSize_HalfWord  
#define DMA1_Memory_DataSize DMA_MemoryDataSize_HalfWord

//#define DMA1_Mode DMA_Mode_Normal
#define DMA1_Mode DMA_Mode_Circular 

#define DMA1_Priority DMA_Priority_High
#define DMA1_M2M DMA_M2M_Disable

#define ADC_Given_Offset 20

void ADC_DMA_CONFIG(void);
void ADC_Value_Converter(void);
#endif


