/*
 * EEPROMIf.h
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */

#ifndef HWABL_EEPROMIF_INC_EEPROMIF_H_
#define HWABL_EEPROMIF_INC_EEPROMIF_H_

#include "stdint_mock.h"
#include "EEPROMIf_types.h"

/* Init mock EEPROM */
extern void EEPROMIf_Init(void);

extern       uint8_t EEPROMIf_GetHwRevision(void);

extern const uint8_t* EEPROMIf_GetHwSerial(void);

#endif /* HWABL_EEPROMIF_INC_EEPROMIF_H_ */
