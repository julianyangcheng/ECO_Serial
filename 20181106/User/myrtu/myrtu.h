#ifndef MYRTU_H
#define MYRTU_H

#include "pbdata.h"

#define REG_INPUT_START 	1000
#define REG_INPUT_NREGS 	7
#define REG_HOLDING_START 1000
#define REG_HOLDING_NREGS 7
#define REG_COILS_START   1000
#define REG_COILS_SIZE    16
#define REG_DISC_START    1000
#define REG_DISC_SIZE     16


/* ----------------------- Static variables ---------------------------------*/
extern USHORT   usRegInputStart;
extern USHORT   usRegInputBuf[REG_INPUT_NREGS];
extern USHORT   usRegHoldingStart;
extern USHORT   usRegHoldingBuf[REG_HOLDING_NREGS];
extern UCHAR ucRegCoilsBuf[REG_COILS_SIZE / 8];
extern UCHAR ucRegDiscBuf[REG_DISC_SIZE / 8];

eMBErrorCode eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs );
eMBErrorCode eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode );
eMBErrorCode eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode );
eMBErrorCode eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete );

#endif
