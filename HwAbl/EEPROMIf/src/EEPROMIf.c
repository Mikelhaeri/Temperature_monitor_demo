/*
 * EEPROMIf.c
 *
 *  Created on: 11.02.2026
 *      Author: Mikel
 */

#include "EEPROMIf.h"
#include "EEPROMIf_cfg.h"

uint8_t EEPROMIf_HwRev_u8;
uint8_t EEPROMIf_HwSerial[EEPROM_LEN_HW_SERIAL];

static const uint8_t EEPROM_Mock_au8[EEPROM_SIZE_BYTES] = {
    EEPROM_DEFAULT_HW_REV,           /* example: 0 = Rev-A */
    'A','B','C','1','2','3','4'      /* Serial als ASCII */
};

void EEPROMIf_Init(void)
{
    EEPROMIf_Read(EEPROM_ADDR_HW_REV, &EEPROMIf_HwRev_u8, EEPROM_LEN_HW_REV);
    
    EEPROMIf_Read(EEPROM_ADDR_HW_SERIAL, EEPROMIf_HwSerial, EEPROM_LEN_HW_SERIAL);
    
}

void EEPROMIf_Read(uint16_t Addr_u16, uint8_t* Data_pu8, uint16_t Len_u16)
{
    uint16_t i_u16;
    
    if( (Addr_u16 < EEPROM_SIZE_BYTES) && ((Addr_u16 + Len_u16) <= EEPROM_SIZE_BYTES) )
    {
        for(i_u16 = 0u; i_u16 < Len_u16; i_u16++)
        {
            Data_pu8[i_u16] = EEPROM_Mock_au8[Addr_u16 + i_u16];
        }
    }
}
