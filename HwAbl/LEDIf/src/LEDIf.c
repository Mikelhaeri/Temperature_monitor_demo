/*
 * LEDIf.c
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */
#include "LEDIf.h"
#include "LEDIf_cfg.h"

/* Initialize LED interface */
void LEDIf_Init(void)
{
    uint8_t i_u8;
    
    for(i_u8 = LEDIF_PIN0; i_u8 < LEDIF_NUM_LEDS; i_u8++)
    {
        Gpio_SetPinDirection(LEDIF_PORT, i_u8, GPIO_DIR_OUTPUT);
        Gpio_WritePin(LEDIF_PORT, i_u8, LED_ON); /* Set all to on to see they work */
    }
}

/* Set LED state */
void LEDIf_Set(uint8_t LedNr, LedIf_State_t State)
{
    if( (LedNr < LEDIF_NUM_LEDS) && (State < LED_STATE_MAX) )
    {
        Gpio_WritePin(LEDIF_PORT, (Gpio_Pin_t)LedNr, (Gpio_PinState_t)State);
    }
    else
    {
        /* In case of wrong input do nothing */
    }
}

/* Toggle LED state */
void LEDIf_Toggle(uint8_t LedNr)
{
    Gpio_PinState_t PinState_t;
    
    if(LedNr < LEDIF_NUM_LEDS)
    {
        PinState_t = (GPIO_PIN_LOW == Gpio_ReadPin(LEDIF_PORT, (Gpio_Pin_t)LedNr) ? GPIO_PIN_HIGH : GPIO_PIN_LOW);
        
        Gpio_WritePin(LEDIF_PORT, (Gpio_Pin_t)LedNr, PinState_t);
    }
    else
    {
        /* In case of wrong input do nothing */
    }
    
}
