/*
 * Gpt.c
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */

#include "Gpt.h"
#include "Gpt_Cfg.h"

/* Timer compare active register, if set to one timer compare will call interrupt */
static volatile uint8_t  GPT_NotifyEnabled_Reg;

/* Prescaler register */
static volatile uint16_t GPT_Prescale_Reg;

/* Timer compre register */
static volatile uint16_t GPT_TimerCmprReg;

/* Running timer register controlled by µC needed for compare register of timer counter with natural overflow */
static volatile uint16_t GPT_TimeCntReg; 



/* Init function of GPT module */
void GPT_TimerInit(void)
{
    GPT_NotifyEnabled_Reg = GPT_TIMER_DISABLE;
    
    GPT_Prescale_Reg  = GPT_TIMER_PRESCALER;
    
    GPT_TimerCmprReg  = GPT_INIT_VAL;
}


/* Start Timer, since the whole project only needs to calculate and compare temperature this is the only needed type
 * of timer setting needed
 */
void GPT_Timer_Start()
{
    GPT_TimerCmprReg = GPT_TimeCntReg + GPT_US_TO_TICKS(GPT_TIMER_PERIOD);
    
    GPT_NotifyEnabled_Reg = GPT_TIMER_ENABLE;
}

void GPT_Timer_Stop(void)
{
    GPT_NotifyEnabled_Reg = GPT_TIMER_DISABLE;
}

/* ISR Function inside main gpt.c not in gpt_isr.c to avoid global variable or extra private header, for this small 
 * project would two extra files be an overhead.
 */
void GPT_ISR(void)
{
    GPT_NotifyEnabled_Reg = GPT_TIMER_DISABLE;
    
    GPT_TimerCmprReg += GPT_US_TO_TICKS(GPT_TIMER_PERIOD);

    GPT_NOTIFICATION();
    
    GPT_NotifyEnabled_Reg = GPT_TIMER_ENABLE;
}
