/*
 * LEDIf_types.h
 *
 *  Created on: 11.02.2026
 *      Author: Mikel
 */

#ifndef HWABL_LEDIF_INC_LEDIF_TYPES_H_
#define HWABL_LEDIF_INC_LEDIF_TYPES_H_

typedef enum
{
    LED_OFF = 0u,
    LED_ON,
    LED_STATE_MAX
} LedIf_State_t;

typedef enum
{
    LED_GREEN = 0u,
    LED_YELLOW,
    LED_RED,
    LED_NUM
} LEDIf_Leds_ten;

#endif /* HWABL_LEDIF_INC_LEDIF_TYPES_H_ */
