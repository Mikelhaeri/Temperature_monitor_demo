/*
 * stdint_mock.h
 *
 *  Created on: 10.02.2026
 *      Author: Mikel
 */

/* stdint_mock.h - nur für PC-Mock / kleine Demo */

#ifndef STDINT_MOCK_H
#define STDINT_MOCK_H

typedef unsigned char      uint8_t;
typedef signed char        int8_t;

typedef unsigned short     uint16_t;
typedef signed short       int16_t;

typedef unsigned int       uint32_t;
typedef signed int         int32_t;

typedef unsigned long long uint64_t;
typedef signed long long   int64_t;


#define MAXSINT16          (0x7fff)
#define MINSINT16          (0x1000)

#define MAXUINT16          (0xffffu)
#define MAXUINT8           (0xffu)

#endif /* STDINT_MOCK_H */
