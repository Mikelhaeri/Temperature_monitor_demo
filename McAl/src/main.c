/*
 * main.c
 *
 *  Created on: 12.02.2026
 *      Author: Mikel
 */
#include "Gpio.h"
#include "Gpt.h"
#include "Adc.h"
#include "EEPROMIf.h"
#include "TempIf.h"
#include "LEDIf.h"
#include "TempMon.h"

int main(void)
{
    Gpio_Init();
    Gpt_Init();
    EEPROMIf_Init();
    Adc_Init();
    TempIf_Init();
    LEDIf_Init();

    TempMon_Init();
    
    Adc_Trigger();

    GPT_Timer_Start();

    for(;;)
    {
        /* optional: sleep / idle */
    }
}
