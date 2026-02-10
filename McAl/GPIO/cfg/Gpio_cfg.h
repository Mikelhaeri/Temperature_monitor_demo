/*
 * GPIO_cfg.h
 *
 *  Created on: 09.02.2026
 *      Author: Mikel
 */

#ifndef MCAL_GPIO_CFG_GPIO_CFG_H_
#define MCAL_GPIO_CFG_GPIO_CFG_H_

#include "stdint_mock.h"
#include "Gpio_types.h"

/* Number of pins per port */
#define GPIO_PINS_PER_PORT   (8u)

/* Mock register definitions (PC demo only) */
extern volatile uint8_t GPIO_PORTA_DATA_REG;
extern volatile uint8_t GPIO_PORTA_DIR_REG;

extern volatile uint8_t GPIO_PORTB_DATA_REG;
extern volatile uint8_t GPIO_PORTB_DIR_REG;

/* Initial pin configuration */
#define GPIO_INIT_STATE           (GPIO_PIN_LOW)    /* all low */
#define GPIO_PORTA_INIT_DIRECTION (GPIO_DIR_OUTPUT) /* Pin direction output */
#define GPIO_PORTB_INIT_DIRECTION (GPIO_DIR_OUTPUT) /* Not used therefore output and pull down */

#endif /* MCAL_GPIO_CFG_GPIO_CFG_H_ */
