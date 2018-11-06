#ifndef __CONTROL_H
#define __CONTROL_H

#include "stm32f10x.h"
#include "dma.h"


#define Bit_run_stop             (0x0001<<0)
#define Bit_cc_cv                (0x0001<<1)
#define Bit_Loc_Remo             (0x0001<<0)

extern __IO uint16_t Run_Status;
extern __IO uint16_t Loc_Run_Status;
extern      uint16_t Remo_Run_Status;
extern __IO uint16_t Loc_Flag;
extern __IO uint16_t Remo_Flag;
extern __IO uint16_t Giv_Loc_Flag;
extern __IO uint16_t Giv_Remo_Flag;
extern __IO uint16_t U_giv;
extern __IO uint16_t Loc_Giv ;
extern __IO uint16_t Remo_Giv;

void control(uint16_t Loc_Remo_Flag);
void GET_Loc_GPIO(void);
#endif //__CONTROL_H
