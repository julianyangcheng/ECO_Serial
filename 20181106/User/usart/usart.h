#ifndef USART_H
#define USART_H
#include "pbdata.h"

void AllUSART_Init(uint32_t rate1,uint32_t rate2,uint32_t rate3);

void USART_PutChar(USART_TypeDef* USARTx , uint8_t Data);
void USART_PutStr(USART_TypeDef* USARTx , char *str);
void UARTX_Sendbytes(USART_TypeDef* USARTx ,unsigned char* s,u16 n);

void USART_Rx(unsigned char Data,unsigned char HEAD,unsigned char START,unsigned char END);
unsigned char USART_Tx(USART_TypeDef* USARTx ,unsigned char BUF[],int LENTH,unsigned char HEAD,unsigned char START,unsigned char END);

unsigned char SumCheck(unsigned char *c,unsigned char n);

#define USART_BUF_LENTH 1024
typedef struct USART
{
	unsigned char RX_LENTH;
	unsigned int 	RX_RENUM;
	unsigned char RX_BUF[USART_BUF_LENTH];
	unsigned char RX_OK;
}USART;
extern USART USART_T;




#endif
