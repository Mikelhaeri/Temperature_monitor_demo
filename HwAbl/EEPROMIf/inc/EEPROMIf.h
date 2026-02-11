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
void EEPROMIf_Init(void);

/* Read bytes from EEPROM */
void EEPROMIf_Read(uint16_t Addr_u16, uint8_t* Data_pu8, uint16_t Len_u16);

#endif /* HWABL_EEPROMIF_INC_EEPROMIF_H_ */
