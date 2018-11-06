#include "pbdata.h"

USART USART_T;

void USART_GPIO_Configuration(void)
{
  GPIO_InitTypeDef GPIO_InitStructure;	
	
	//usart1 
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_9;//TX
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOA,&GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//RX
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
//	//usart2 
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;//TX
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
//	GPIO_Init(GPIOA,&GPIO_InitStructure);

//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;//RX
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
//	GPIO_Init(GPIOA,&GPIO_InitStructure);
//	
//	//usart3 
//	
//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;//TX
//	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
//	GPIO_Init(GPIOB,&GPIO_InitStructure);

//	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_11;//RX
//	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN_FLOATING;
//	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
}

//usart priority
void USART_NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure; 

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 

	NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn; 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0; 
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
	NVIC_Init(&NVIC_InitStructure);
	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 
//	
//	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn; 
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; 
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
//	NVIC_Init(&NVIC_InitStructure);
//	
//	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1); 
//	
//	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn; 
//	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0; 
//	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2; 
//	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; 
//	NVIC_Init(&NVIC_InitStructure);
}

//usart1 set
void USART_Configuration(uint32_t rate1,uint32_t rate2,uint32_t rate3)
{
  USART_InitTypeDef  USART_InitStructure;

	USART_InitStructure.USART_BaudRate=9600;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;

	//usart1 init
	USART_Init(USART1,&USART_InitStructure);
	USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);
	USART_Cmd(USART1,ENABLE);
	USART_ClearFlag(USART1,USART_FLAG_TC);
	
	
//	USART_InitStructure.USART_BaudRate=rate2;
//	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
//	USART_InitStructure.USART_StopBits=USART_StopBits_1;
//	USART_InitStructure.USART_Parity=USART_Parity_No;
//	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
//	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
//	//usart2 init
//	USART_Init(USART2,&USART_InitStructure);
//	USART_ITConfig(USART2,USART_IT_RXNE,ENABLE);
//	USART_Cmd(USART2,ENABLE);
//	USART_ClearFlag(USART2,USART_FLAG_TC);
//	
//	
//	USART_InitStructure.USART_BaudRate=rate3;
//	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
//	USART_InitStructure.USART_StopBits=USART_StopBits_1;
//	USART_InitStructure.USART_Parity=USART_Parity_No;
//	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
//	USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
//	//usart3 init
//	USART_Init(USART3,&USART_InitStructure);
//	USART_ITConfig(USART3,USART_IT_RXNE,ENABLE);
//	USART_Cmd(USART3,ENABLE);
//	USART_ClearFlag(USART3,USART_FLAG_TC);
}

void AllUSART_Init(uint32_t rate1,uint32_t rate2,uint32_t rate3)
{
	USART_GPIO_Configuration();
	USART_Configuration(rate1,rate2,rate3);
	USART_NVIC_Configuration();
}


/*usartx send char*/
void USART_PutChar(USART_TypeDef* USARTx , uint8_t Data)
{
	USART_SendData(USARTx,Data);
	while(USART_GetFlagStatus(USARTx,USART_FLAG_TC) == RESET);
}

/*usartx send string*/
void USART_PutStr(USART_TypeDef* USARTx , char *str)
{
	while(*str != NULL)
	{
		USART_PutChar(USARTx,*str);
		str++;
	}
}

/*sum check*/
unsigned char SumCheck(unsigned char *c,unsigned char n)
{
	unsigned char    sub_c=c[0];
	unsigned char    i;

	for(i=1;i<n;i++)
	{
		sub_c+=c[i];
	}
	return (sub_c);
}

/*recieve usart data*/
void USART_Rx(unsigned char Data,unsigned char HEAD,unsigned char START,unsigned char END)
{
	unsigned char h,t;
	if (USART_T.RX_RENUM<USART_BUF_LENTH)
	{
		h=USART_T.RX_RENUM;
		t=Data;
		USART_T.RX_BUF[h]=t;
		USART_T.RX_RENUM=h+1;

		t=0;

		if ((h==0)&&(USART_T.RX_BUF[0]!=HEAD)) t=1;
		if ((h==1)&&(USART_T.RX_BUF[1]!=START)) t=1;
		if (t==1) 
		{
			USART_T.RX_RENUM=0;				
		}
		
		if((h > 2)&&(USART_T.RX_RENUM>=USART_T.RX_BUF[2])&&(USART_T.RX_BUF[h-1]==END))
		{
				USART_T.RX_RENUM=0;
				USART_T.RX_OK=1;
//			if(SumCheck(USART_T.RX_BUF,USART_T.RX_BUF[2]-1) == USART_T.RX_BUF[h])
//			{
//				USART_T.RX_RENUM=0;
//				USART_T.RX_OK=1;
//			}

		}
		
	}
	else
	{
			USART_T.RX_RENUM=0;			
	}
}

/*send buf*/
unsigned char USART_Tx(USART_TypeDef* USARTx ,unsigned char BUF[],int LENTH,unsigned char HEAD,unsigned char START,unsigned char END)
{
	unsigned int i;
	unsigned char Check=0;
	
	USART_PutChar(USARTx,HEAD);
	Check+=HEAD;
	USART_PutChar(USARTx,START);
	Check+=START;
	USART_PutChar(USARTx,LENTH+5);
	Check+=(LENTH+5);
	
	for(i=0;i<LENTH;i++)
	{
		USART_PutChar(USARTx,BUF[i]);
		Check+=BUF[i];
	}
	
	USART_PutChar(USARTx,END);
	Check+=END;
	
	USART_PutChar(USARTx,Check);
	
	return 1;
}

void UARTX_Sendbytes(USART_TypeDef* USARTx ,unsigned char* s,u16 n)
{
	while(n--)//¼ì²â×Ö·û´®½áÊø·û
	{
		while(USART_GetFlagStatus(USARTx, USART_FLAG_TC)==RESET); 
		USART_SendData(USARTx ,*s++);//·¢ËÍµ±Ç°×Ö·û
	}
	while(USART_GetFlagStatus(USARTx, USART_FLAG_TC)==RESET); 
}











