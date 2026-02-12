/*
 * LEDIf.h
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */

#ifndef HWABL_LEDIF_INC_LEDIF_H_
#define HWABL_LEDIF_INC_LEDIF_H_

#include "stdint_mock.h"
#include "LEDIf_types.h"

/* Initialize LED interface */
extern void LEDIf_Init(void);

/* Set LED state */
extern void LEDIf_Set(uint8_t LedNr, Gpio_PinState_t State);

#endif /* HWABL_LEDIF_INC_LEDIF_H_ */
