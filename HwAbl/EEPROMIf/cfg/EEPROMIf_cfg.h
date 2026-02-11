/*
 * EEPROM_cfg.h
 *
 *  Created on: 10.02.2026
 *      Author: Mikel
 */

#ifndef HWABL_EEPROMIF_CFG_EEPROMIF_CFG_H_
#define HWABL_EEPROMIF_CFG_EEPROMIF_CFG_H_

#include "EEPROMIf_types.h"



/* ===============================
 * EEPROM memory map
 * =============================== */

/* Hardware revision
 * 0 = Rev-A
 * 1 = Rev-B
 */
#define EEPROM_ADDR_HW_REV    (0u)
#define EEPROM_LEN_HW_REV     (1u)

/* Hardware serial number (ASCII, fixed length) */
#define EEPROM_ADDR_HW_SERIAL (1u)
#define EEPROM_LEN_HW_SERIAL  (7u)

/* ===============================
 * Default values
 * =============================== */

#define EEPROM_DEFAULT_HW_REV     (HW_REV_A) /* Rev-A */

#define EEPROM_DEFAULT_HW_SERIAL  { 'A','B','C','0','0','0','0' }


/* Total mock EEPROM size */
#define EEPROM_SIZE_BYTES     (EEPROM_LEN_HW_REV + EEPROM_LEN_HW_SERIAL)

#endif /* HWABL_EEPROMIF_CFG_EEPROMIF_CFG_H_ */
