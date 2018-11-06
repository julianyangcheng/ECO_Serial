#include "stm32f10x.h"   // 相当于51单片机中的  #include <reg51.h>
#include "nvic.h"
#include "led.h"
#include "adc.h"
#include "dma.h"
#include "dac.h"
#include "control.h"
#include "usart.h"
#include "time.h"
#include "pbdata.h"
#include "myrtu.h"




void RCC_Configuration(void)
{
  SystemInit();//72m
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);	
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);

}
int fputc(int ch,FILE *f)
{
	USART_SendData(USART1,(u8)ch);
	while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)==RESET);
	return ch;
}

//#include "usart_dma.h"

extern __IO uint16_t ADC_temp;
extern __IO uint16_t ADC_Filted_Value;
extern __IO uint8_t Loc_Remo_Flag;

USHORT Flag   = 0x0000;
USHORT Status = 0x0000;
USHORT Given  = 0x0000;
USHORT Io     = 0x0000;
USHORT Uo     = 0x0000;
USHORT Alarm  = 0x0000;


uint8_t Test = 0;
uint8_t TestRun = 0 ;
int main(void)
{
	RCC_Configuration();	//系统时钟初始化
	status_led_gpio_config();
	EXTI_Key_Config();
	ADC_DMA_CONFIG();
	
	ADCx_Init();
	
	DAC_Init_Config();

  eMBErrorCode eStatus;
	
	
	
	eStatus = eMBInit(MB_RTU,0X01,0,9600,MB_PAR_NONE);
	eStatus = eMBEnable();



	GET_Loc_GPIO();
	
	while(1)
	{
		(void)eMBPoll();
		control(Loc_Remo_Flag);		
		Test = GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_3);
		TestRun = GPIO_ReadInputDataBit(KEY1_INT_GPIO_PORT,KEY1_INT_GPIO_PIN);
		

	
	}

}

	





