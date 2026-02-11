/*
 * LEDIf_cfg.h
 *
 *  Created on: 10.02.2026
 *      Author: Mikel
 */

#ifndef HWABL_LEDIF_CFG_LEDIF_CFG_H_
#define HWABL_LEDIF_CFG_LEDIF_CFG_H_

#include "Gpio_types.h"

/* Number of LEDs in this demo */
#define LEDIF_NUM_LEDS   (3u)

/* Pin mapping (mock/demo only) */
#define LEDIF_PIN0       (0u)
#define LEDIF_PIN1       (1u)
#define LEDIF_PIN2       (2u)

/* Port mapping */
#define LEDIF_PORT       GPIO_PORT_A

#endif /* HWABL_LEDIF_CFG_LEDIF_CFG_H_ */
