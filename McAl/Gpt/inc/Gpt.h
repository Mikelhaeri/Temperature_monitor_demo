/*
 * Gpt.h
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */

#ifndef MCAL_GPT_INC_GPT_H_
#define MCAL_GPT_INC_GPT_H_

#include <stdint.h>

extern void GPT_TimerInit(void);

extern void GPT_Timer_Start(void);

extern void GPT_Timer_Stop(void);

extern void GPT_ISR(void);

#endif /* MCAL_GPT_INC_GPT_H_ */
