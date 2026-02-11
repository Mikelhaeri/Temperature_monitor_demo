/*
 * TempIf.h
 *
 *  Created on: 08.02.2026
 *      Author: Mikel
 */

#ifndef HWABL_TEMPIF_INC_TEMPIF_H_
#define HWABL_TEMPIF_INC_TEMPIF_H_

#include "stdint_mock.h"

#define TEMPIF_ERROR_VAL MAXSINT16

/* Init function for Temp sensor interface */
void TempIf_Init(void);

/* Read temperature in °C (mock or real) */
int16_t TempIf_Read(void);

#endif /* HWABL_TEMPIF_INC_TEMPIF_H_ */
