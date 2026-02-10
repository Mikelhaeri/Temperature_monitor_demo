/*
 * GPIO.c
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */
/*
 * GPIO abstraction deliberately avoids struct-based port models.
 * Real microcontroller GPIOs are bit-addressed registers.
 * This implementation uses pin mask lookup tables to avoid:
 *  - runtime shifts
 *  - switch-cases
 *  - misleading array semantics
 */


#include <Gpio.h>

#include "../cfg/Gpio_cfg.h"


/* Pin mask lookup table
 * Index = Pin number
 * Value = Bit mask
 */
static const uint8_t Gpio_PinMask[GPIO_PINS_PER_PORT] =
{
    0x01u,  /* Pin 0 */
    0x02u,  /* Pin 1 */
    0x04u,  /* Pin 2 */
    0x08u,  /* Pin 3 */
    0x10u,  /* Pin 4 */
    0x20u,  /* Pin 5 */
    0x40u,  /* Pin 6 */
    0x80u   /* Pin 7 */
};

void Gpio_Init(void)
{
    GPIO_PORTA_DATA_REG = GPIO_INIT_STATE;
    GPIO_PORTA_DIR_REG  = GPIO_PORTA_INIT_DIRECTION;
    
    GPIO_PORTB_DATA_REG = GPIO_INIT_STATE;
    GPIO_PORTB_DIR_REG  = GPIO_PORTB_INIT_DIRECTION;
}


void Gpio_WritePin(Gpio_Port_t Port, Gpio_Pin_t  Pin, Gpio_PinState_t State)
{
    if(Pin < GPIO_PINS_PER_PORT)
    {
        if(GPIO_PIN_LOW == State)
        {
            if(GPIO_PORT_A == Port)
            {
                GPIO_PORTA_DATA_REG &= ~Gpio_PinMask[Pin];
            }
            else if(GPIO_PORT_B == Port)
            {
                GPIO_PORTB_DATA_REG &= ~Gpio_PinMask[Pin];
            }
            else
            {
                /* Misra else */
            }
        }
        else
        {
            if(GPIO_PORT_A == Port)
            {
                GPIO_PORTA_DATA_REG |= Gpio_PinMask[Pin];
            }
            else if(GPIO_PORT_B == Port)
            {
                GPIO_PORTB_DATA_REG |= Gpio_PinMask[Pin];
            }
            else
            {
                /* Misra else */
            }
        }
    }
    else
    {
        /* No error handling here */
    }
}

Gpio_PinState_t Gpio_ReadPin(Gpio_Port_t Port, Gpio_Pin_t  Pin)
{
    uint8_t PinVal_u8 = GPIO_PIN_LOW;
    
    if(Pin < GPIO_PINS_PER_PORT)
    {
        if(GPIO_PORT_A == Port)
        {
            PinVal_u8 = GPIO_PORTA_DATA_REG & Gpio_PinMask[Pin];
        }
        else /* no else if, since just read */
        {
            PinVal_u8 = GPIO_PORTB_DATA_REG & Gpio_PinMask[Pin];
        }
    }
    else
    {
        /* No error handling here */
    }
    
    if(GPIO_PIN_LOW != PinVal_u8)
    {
        /* set to high */
        PinVal_u8 = GPIO_PIN_HIGH;
    }
    
    return PinVal_u8;
}

void Gpio_SetPinDirection(Gpio_Port_t Port, Gpio_Pin_t  Pin, Gpio_PinDirection_t Direction)
{
    if(Pin < GPIO_PINS_PER_PORT)
    {
        if(GPIO_DIR_INPUT == Direction)
        {
            if(GPIO_PORT_A == Port)
            {
                GPIO_PORTA_DIR_REG &= ~Gpio_PinMask[Pin];
            }
            else if(GPIO_PORT_B == Port)
            {
                GPIO_PORTB_DIR_REG &= ~Gpio_PinMask[Pin];
            }
            else
            {
                /* Misra else */
            }
        }
        else
        {
            if(GPIO_PORT_A == Port)
            {
                GPIO_PORTA_DIR_REG |= Gpio_PinMask[Pin];
            }
            else if(GPIO_PORT_B == Port)
            {
                GPIO_PORTB_DIR_REG |= Gpio_PinMask[Pin];
            }
            else
            {
                /* Misra else */
            }
        }
    }
    else
    {
        /* No error handling here */
    }
}
