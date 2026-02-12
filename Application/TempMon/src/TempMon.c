/*
 * TempMon.c
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */

#include "TempMon.h"
#include "TempMon_cfg.h"
#include "TempMon_types.h"
#include "LEDIf.h"
#include "TempIf.h"

static TempMon_State_ten TempMon_CurrState_en;

void TempMon__Init(void)
{
    uint8_t           i_u8;
    volatile uint16_t i_u16 = TEMPMON_INITDELAY;
    
    TempMon_CurrState_en = TEMPMON_STATE_INIT;
    
    /*Delay on time of LED before disabling them */
    while(i_u16 > 0)
    {
        i_u16--;
    }
    for(i_u8 = (uint8_t)LED_GREEN; i_u8 < (uint8_t)LED_NUM; i_u8++)
    {
        LEDIf_Set(i_u16, LED_OFF);
    }
}

static uint8_t TempMon_GetPin(TempMon_State_ten State_en)
{
    uint8_t Led_u8;
    
    switch(State_en)
    {
        case TEMPMON_STATE_NORMAL:
        {
            Led_u8 = LED_GREEN;
        }
        break;
        case TEMPMON_STATE_WARNING:
        {
            Led_u8 = LED_YELLOW;
        }
        break;
        case TEMPMON_STATE_CRITICAL:
        {
            Led_u8 = LED_RED;
        }
        break;
        default:
        {
            Led_u8 = LED_RED;
        }
    }
    
    return Led_u8;
}

static void TempMon_StateHndl(TempMon_State_ten State_en)
{

    if(State_en != TempMon_CurrState_en)
    {
        if(TEMPMON_STATE_ERROR != TempMon_CurrState_en)
        {
            /* INIT state: no LED active.
             * First state transition may switch off LED_RED implicitly.
             * This is intentional and harmless.
             */
            LEDIf_Set(TempMon_GetPin(TempMon_CurrState_en), LED_OFF);
        }
        else
        {
            LEDIf_Set(LED_YELLOW, LED_OFF);
            LEDIf_Set(LED_RED, LED_OFF);
        }
        
        if(TEMPMON_STATE_ERROR != State_en)
        {
            LEDIf_Set(TempMon_GetPin(State_en), LED_ON);
        }
        else
        {
            /* ERROR: sensor failure → YELLOW + RED */
            LEDIf_Set(LED_YELLOW, LED_ON);
            LEDIf_Set(LED_RED, LED_ON);
        }
        
        TempMon_CurrState_en = State_en;
    }
}

void TempMon_Proc(void)
{
    
    int16_t           Temp_s16    = TempIf_Read();
    TempMon_State_ten NewState_en;
    
    if(Temp_s16 == TEMPIF_ERROR_VAL) 
    {
        NewState_en = TEMPMON_STATE_ERROR;
    }
    else if( (Temp_s16 < TEMPMON_TEMP_MIN) || (Temp_s16 > TEMPMON_TEMP_HIGH) )
    {
        NewState_en = TEMPMON_STATE_CRITICAL;
    }
    else if(Temp_s16 > TEMPMON_TEMP_WARNING) 
    {
        NewState_en = TEMPMON_STATE_WARNING;
    }
    else 
    {
        NewState_en = TEMPMON_STATE_NORMAL;
    }
    
    TempMon_StateHndl(NewState_en);
    
}
