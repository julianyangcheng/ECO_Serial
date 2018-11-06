#include "pbdata.h"

USHORT   usRegInputStart = REG_INPUT_START;
USHORT   usRegInputBuf[REG_INPUT_NREGS];
USHORT   usRegHoldingStart = REG_HOLDING_START;
USHORT   usRegHoldingBuf[REG_HOLDING_NREGS];
UCHAR 	 ucRegCoilsBuf[REG_COILS_SIZE / 8]={0x80,0x08};
UCHAR 	 ucRegDiscBuf[REG_DISC_SIZE / 8]={0x66,0x66};

eMBErrorCode eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )      /*读 寄存器的值 	0X04*/
{
    eMBErrorCode    eStatus = MB_ENOERR;
    int             iRegIndex;
	
    if( ( usAddress >= REG_INPUT_START )
        && ( usAddress + usNRegs <= REG_INPUT_START + REG_INPUT_NREGS ) )
    {
        iRegIndex = ( int )( usAddress - usRegInputStart );
        while( usNRegs > 0 )
        {
            *pucRegBuffer++ =
                ( UCHAR )( usRegInputBuf[iRegIndex] >> 8 );
            *pucRegBuffer++ =
                ( UCHAR )( usRegInputBuf[iRegIndex] & 0xFF );
            iRegIndex++;
            usNRegs--;
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }

    return eStatus;
}

eMBErrorCode eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )			/*写单个寄存器的值--0X06，写多个寄存器--0X10，读寄存器的值--0X03，读写多个寄存器--0X17*/
{
		eMBErrorCode    eStatus = MB_ENOERR;
    int             iRegIndex;
	
    if( ( usAddress >= REG_HOLDING_START ) &&
        ( usAddress + usNRegs <= REG_HOLDING_START + REG_HOLDING_NREGS ) )
    {
        iRegIndex = ( int )( usAddress - usRegHoldingStart );
        switch ( eMode )
        {
            /* Pass current register values to the protocol stack. */
        case MB_REG_READ:
            while( usNRegs > 0 )
            {
                *pucRegBuffer++ = ( UCHAR ) ( usRegHoldingBuf[iRegIndex] >> 8 );
                *pucRegBuffer++ = ( UCHAR ) ( usRegHoldingBuf[iRegIndex] & 0xFF );
                iRegIndex++;
                usNRegs--;
            }
            break;

            /* Update current register values with new values from the
             * protocol stack. */
        case MB_REG_WRITE:
            while( usNRegs > 0 )
            {
                usRegHoldingBuf[iRegIndex] = *pucRegBuffer++ << 8;
                usRegHoldingBuf[iRegIndex] |= *pucRegBuffer++;
                iRegIndex++;
                usNRegs--;
            }
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }
		
    return eStatus;
}


eMBErrorCode eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode )			/*读线圈状态--0X01,写单个线圈--0X05，写多个线圈--0X0F*/
{
		eMBErrorCode    eStatus = MB_ENOERR;
    int             iNCoils = ( int )usNCoils;
    unsigned short  usBitOffset;

    /* Check if we have registers mapped at this block. */
    if( ( usAddress >= REG_COILS_START ) &&
        ( usAddress + usNCoils <= REG_COILS_START + REG_COILS_SIZE ) )
    {
        usBitOffset = ( USHORT )( usAddress - REG_COILS_START );
        switch ( eMode )
        {
                /* Read current values and pass to protocol stack. */
            case MB_REG_READ:
                while( iNCoils > 0 )
                {
                    *pucRegBuffer++ =
                        xMBUtilGetBits( ucRegCoilsBuf, usBitOffset,( UCHAR )( iNCoils >8 ? 8 :iNCoils ) );
                    iNCoils -= 8;
                    usBitOffset += 8;
                }
                break;

                /* Update current register values. */
            case MB_REG_WRITE:
                while( iNCoils > 0 )
                {
                    xMBUtilSetBits( ucRegCoilsBuf, usBitOffset,( UCHAR )( iNCoils > 8 ? 8 : iNCoils ),*pucRegBuffer++ );
                    iNCoils -= 8;
                    usBitOffset += 8;
                }
                break;
        }

    }
    else
    {
        eStatus = MB_ENOREG;
    }
    return eStatus;
}

eMBErrorCode eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )												/*读多个离散开关量	0X02*/
{
		eMBErrorCode    eStatus = MB_ENOERR;
    short           iNDiscrete = ( short )usNDiscrete;
    USHORT				  usBitOffset;

    /* Check if we have registers mapped at this block. */
    if( ( usAddress >= REG_DISC_START ) &&
        ( usAddress + usNDiscrete <= REG_DISC_START + REG_DISC_SIZE ) )
    {
        usBitOffset = ( USHORT )( usAddress - REG_DISC_START );
        while( iNDiscrete > 0 )
        {
            *pucRegBuffer++ = xMBUtilGetBits( ucRegDiscBuf, usBitOffset,( UCHAR )( iNDiscrete >8 ? 8 : iNDiscrete ) );
            iNDiscrete -= 8;
            usBitOffset += 8;
        }
    }
    else
    {
        eStatus = MB_ENOREG;
    }
    return eStatus;
}
