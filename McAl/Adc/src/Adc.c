/*
 * Adc.c
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */
#include "Adc.h"

#include "Adc_cfg.h"

static volatile uint16_t Adc_MockRead_Reg;

static volatile uint8_t Adc_ConvStart_Reg;

static volatile uint8_t Adc_Finished_Reg;

void Adc_Init(void)
{
    /* Nothing to do for PC mock */
}

uint16_t Adc_Read(void)
{
    uint8_t  Timeout_u8 = ADC_TIMEOUT;
    uint16_t RetVal_u16 = ADC_DEFAULTVAL;
    
    Adc_ConvStart_Reg = ADC_STARTCONV;
    
    while((ADC_CONVFINISHED != Adc_Finished_Reg) && (Timeout_u8 > 0))
    {
        /* wait for Conversion to be finished */
        /* PC mock:
         * In real hardware, Adc_Finished_Reg is set by ADC peripheral.
         * In this mock, no ISR exists, so timeout will expire.
         */

        Timeout_u8--;
    }
    
    if(Timeout_u8 > 0u)
    {
        RetVal_u16 = Adc_MockRead_Reg;
    }
    
    return RetVal_u16;
}
