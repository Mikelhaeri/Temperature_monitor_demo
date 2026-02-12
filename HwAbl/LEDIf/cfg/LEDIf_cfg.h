/*
 * LEDIf_cfg.h
 *
 *  Created on: 10.02.2026
 *      Author: Mikel
 */

#ifndef HWABL_LEDIF_CFG_LEDIF_CFG_H_
#define HWABL_LEDIF_CFG_LEDIF_CFG_H_

#include "Gpio_types.h"
#include "LEDIf_types.h"

/* Number of LEDs in this demo */
#define LEDIF_NUM_LEDS   ((uint8_t)LED_NUM)

/* Pin mapping (mock/demo only) */
#define LEDIF_PIN0       ((uint8_t)LED_GREEN)
#define LEDIF_PIN1       ((uint8_t)LED_YELLOW)
#define LEDIF_PIN2       ((uint8_t)LED_RED)

/* Port mapping */
#define LEDIF_PORT       GPIO_PORT_A

#endif /* HWABL_LEDIF_CFG_LEDIF_CFG_H_ */
