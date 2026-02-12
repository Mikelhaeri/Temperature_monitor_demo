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
    /* Nothing to do for PC mock else set values for ADC measurement*/
}

uint16_t Adc_Read(void)
{
    uint16_t RetVal_u16 = ADC_DEFAULTVAL;
    
    if(ADC_CONVFINISHED != Adc_Finished_Reg) 
    {
        RetVal_u16 = Adc_MockRead_Reg;
    }
    
    return RetVal_u16;
}

void ADC_Trigger(void)
{
    Adc_ConvStart_Reg = ADC_STARTCONV;
}
