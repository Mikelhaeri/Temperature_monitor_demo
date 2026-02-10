/*
 * Gpio_types.h
 *
 *  Created on: 09.02.2026
 *      Author: Mikel
 */

#ifndef MCAL_GPIO_INC_GPIO_TYPES_H_
#define MCAL_GPIO_INC_GPIO_TYPES_H_

#include "stdint_mock.h"

/* Logical pin state */
typedef enum
{
    GPIO_PIN_LOW  = 0u,
    GPIO_PIN_HIGH = 1u
} Gpio_PinState_t;

/* Pin direction */
typedef enum
{
    GPIO_DIR_INPUT  = 0u,
    GPIO_DIR_OUTPUT = 1u
} Gpio_PinDirection_t;

/* GPIO pin number (0..7) */
typedef uint8_t Gpio_Pin_t;

/* GPIO port identifier (mocked, extendable) */
typedef enum
{
    GPIO_PORT_A = 0u,
    GPIO_PORT_B = 1u
} Gpio_Port_t;

#endif /* MCAL_GPIO_INC_GPIO_TYPES_H_ */
