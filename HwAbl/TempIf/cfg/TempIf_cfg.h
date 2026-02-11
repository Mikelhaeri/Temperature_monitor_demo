/*
 * TempIf_cfg.h
 *
 *  Created on: 10.02.2026
 *      Author: Mikel
 */

#ifndef HWABL_TEMPIF_CFG_TEMPIF_CFG_H_
#define HWABL_TEMPIF_CFG_TEMPIF_CFG_H_

#define TEMPIF_INITVAL           (0)
#define TEMPIF_DFTVAL            ((int16_t)ADC_ERROR_VAL)

/* Target: 0.1°C per LSB */
#define TEMPIF_SCALE            (10)   /* 10 = 0.1°C */

/* Mock/Config values for Temp sensor (PC demo) */
#define TEMPIF_DEFAULT_TEMP_C    (250)    /* Default temp in °C for demo */

/* Rev-A: 1.0°C per ADC-LSB → *10 */
#define TEMPIF_REVA_MUL         (10)
#define TEMPIF_REVA_DIV         (1)

/* Rev-B: 0.1°C per ADC-LSB → *1 */
#define TEMPIF_REVB_MUL         (1)
#define TEMPIF_REVB_DIV         (1)

#endif /* HWABL_TEMPIF_CFG_TEMPIF_CFG_H_ */
