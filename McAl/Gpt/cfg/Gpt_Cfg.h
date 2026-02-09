/*
 * Gpt_Cfg.h
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */

#ifndef MCAL_GPT_CFG_GPT_CFG_H_
#define MCAL_GPT_CFG_GPT_CFG_H_

#define GPT_TIMER_ENABLE    (1u)

#define GPT_TIMER_DISABLE   (0u)

#define GPT_INIT_VAL        (0u)

#define GPT_TIMER_PERIOD    (100u) /* This is µs */

/* Assumption:
 * GPT timer clock derived from fixed system clock.
 * Timing accuracy is not relevant for PC-based demo.
 */


#define GPT_TIMER_CLK_HZ    (16000000u)

#define GPT_TIMER_PRESCALER (16u)

#define GPT_TIMER_TICK_HZ   (GPT_TIMER_CLK_HZ / GPT_TIMER_PRESCALER)

#define GPT_US_TO_TICKS(us) ((uint16_t)(((uint32_t)(us) * GPT_TIMER_TICK_HZ) / 1000000u))




#define GPT_NOTIFICATION 

#endif /* MCAL_GPT_CFG_GPT_CFG_H_ */
