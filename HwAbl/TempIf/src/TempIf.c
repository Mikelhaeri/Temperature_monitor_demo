/*
 * TempIf.c
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */

#include "TempIf.h"
#include "TempIf_cfg.h"
#include "Adc.h"
#include "EEPROMIf.h"

static uint16_t TempIf_TempRawVal_u16;
static int16_t  TempIf_TempVal_s16;
static uint16_t TempIf_Mul_u16;
static uint16_t TempIf_Div_u16;

void TempIf_Init(void)
{
    TempIf_TempRawVal_u16 = TEMPIF_INITVAL;
    TempIf_TempVal_s16    = TEMPIF_INITVAL;
    
    /* Use Rev-A parameters unless explicitly Rev-B */
    if(HW_REV_B != EEPROMIf_GetHwRevision())
    {
        TempIf_Mul_u16 = TEMPIF_REVB_MUL;
        TempIf_Div_u16 = TEMPIF_REVB_DIV;
    }
    else
    {
        TempIf_Mul_u16 = TEMPIF_REVA_MUL;
        TempIf_Div_u16 = TEMPIF_REVA_DIV;
    }
}

int16_t TempIf_Read(void)
{
    int32_t Temp_s32;
    
    TempIf_TempRawVal_u16 = Adc_Read();
    
    if((ADC_ERROR_VAL != TempIf_TempRawVal_u16) || (0u != TempIf_Div_u16) )
    {
        Temp_s32 = (int32_t)TempIf_TempRawVal_u16 * TempIf_Mul_u16 / TempIf_Div_u16;
        
        if(Temp_s32 > MAXSINT16)
        {
            TempIf_TempVal_s16 = MAXSINT16;
        }
        else if(Temp_s32 < MINSINT16)
        {
            TempIf_TempVal_s16 = MINSINT16;
        }
        else
        {
            TempIf_TempVal_s16 = (int16_t)Temp_s32;
        }
    }
    else
    {
        TempIf_TempVal_s16 = TEMPIF_DFTVAL;
    }
    
    return(TempIf_TempVal_s16);
}
