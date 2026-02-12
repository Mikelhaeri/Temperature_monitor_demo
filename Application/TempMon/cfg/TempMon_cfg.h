/*
 * TempMon_cfg.h
 *
 *  Created on: 11.02.2026
 *      Author: Mikel
 */

#ifndef APPLICATION_TEMPMON_CFG_TEMPMON_CFG_H_
#define APPLICATION_TEMPMON_CFG_TEMPMON_CFG_H_

#include "LEDIf.h"

/* LED Nummern für Temperaturanzeige */
#define TEMPMON_LED_LOW      LEDIF_PIN0
#define TEMPMON_LED_HIGH     LEDIF_PIN1

/* Temperaturgrenzen in 0.1°C */
#define TEMPMON_TEMP_MIN     ((int16_t)50)    /* Minimum temperature below is critical 5°C       */
#define TEMPMON_TEMP_HIGH    ((int16_t)1050)  /* MAximum temperature above is critical 105°C     */
#define TEMPMON_TEMP_WARNING ((int16_t)850)   /* temperature threshold above warnig range begins */

/* Delay for time of all LEDs ON after start up to be longer than just a few µs */
#define TEMPMON_INITDELAY    (MAXUINT16)      

#endif /* APPLICATION_TEMPMON_CFG_TEMPMON_CFG_H_ */
