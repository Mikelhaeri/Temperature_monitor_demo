/*
 * Adc_cfg.h
 *
 *  Created on: 09.02.2026
 *      Author: Mikel
 */

#ifndef MCAL_ADC_INC_ADC_CFG_H_
#define MCAL_ADC_INC_ADC_CFG_H_

#define ADC_RESOLUTION_BITS    (12u)
#define ADC_MAX_VALUE          (4095u)

#define ADC_TIMEOUT            (100u)
#define ADC_DEFAULTVAL         ADC_ERROR_VAL

#define ADC_STARTCONV          (1u)
#define ADC_CONVFINISHED       (1u)
/* Mock values for PC demo */
#define ADC_MOCK_MIN           (0u)
#define ADC_MOCK_MAX           (4095u)

#endif /* MCAL_ADC_INC_ADC_CFG_H_ */
