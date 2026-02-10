/*
 * Adc.h
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */

#ifndef MCAL_ADC_INC_ADC_H_
#define MCAL_ADC_INC_ADC_H_

#include "stdint_mock.h"

extern void ADC_Init(void);

extern uint16_t ADC_Read(void);

#endif /* MCAL_ADC_INC_ADC_H_ */
