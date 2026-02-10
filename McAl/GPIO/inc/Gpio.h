/*
 * GPIO.h
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */

#ifndef MCAL_GPIO_INC_GPIO_H_
#define MCAL_GPIO_INC_GPIO_H_

#include "Gpio_Types.h"

/* Initialize GPIO module */
extern void Gpio_Init(void);

/* Write pin state */
extern void Gpio_WritePin(
    Gpio_Port_t Port,
    Gpio_Pin_t  Pin,
    Gpio_PinState_t State
);

/* Read pin state */
extern Gpio_PinState_t Gpio_ReadPin(
    Gpio_Port_t Port,
    Gpio_Pin_t  Pin
);

/* Set pin direction */
extern void Gpio_SetPinDirection(
    Gpio_Port_t Port,
    Gpio_Pin_t  Pin,
    Gpio_PinDirection_t Direction
);
#endif /* MCAL_GPIO_INC_GPIO_H_ */
