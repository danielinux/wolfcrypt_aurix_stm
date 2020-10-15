/* user_settings.h
 *
 * Custom configuration for wolfCrypt/wolfSSL.
 * Enabled via WOLFSSL_USER_SETTINGS.
 *
 *
 * Copyright (C) 2020 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

#ifndef H_USER_SETTINGS_
#define H_USER_SETTINGS_
#include <stdio.h>
#include <stdint.h>

/* System */
#define WOLFSSL_GENERAL_ALIGNMENT 4
#define SINGLE_THREADED
#define WOLFCRYPT_ONLY
#define SIZEOF_LONG_LONG 8
#define BENCH_EMBEDDED
#define NO_WOLFSSL_MEMORY

unsigned long time_ms(void);

static inline int cust_rand_generate_block(unsigned char *rndb, unsigned sz)
{
    int i;
    for (i = 0; i < sz; i++)
        rndb[i]=4;
    return sz;
}

/* Prototype for strncasecmp used in ecc.c */
int strncasecmp(const char *s1, const char *s2, size_t n);

#define CUSTOM_RAND_GENERATE_BLOCK cust_rand_generate_block

#define NO_WOLFSSL_DIR
#define WOLFSSL_NO_CURRDIR

#define HAVE_ED25519
#define ED25519_SMALL
#define WOLFSSL_SHA512

#define HAVE_ECC
#define ECC_TIMING_RESISTANT
#undef USE_FAST_MATH
#define WOLFSSL_HAVE_SP_ECC



/* SP MATH */
#define WOLFSSL_SP
#define WOLFSSL_SP_MATH
#define WOLFSSL_SP_SMALL
#define SP_WORD_SIZE 32

/* Curve */
#   define HAVE_ECC256

#define HAVE_RSA
#define RSA_LOW_MEM
#define WOLFSSL_HAVE_SP_RSA
#define WOLFSSL_SP
#define WOLFSSL_SP_SMALL
#define WOLFSSL_SP_MATH
#define SP_WORD_SIZE 32
#define WC_RSA_BLINDING

#define WOLFSSL_SHA3

#define HAVE_CHACHA
#define HAVE_AESGCM
#define HAVE_AES_ECB
#define WOLFSSL_AES_DIRECT
#define HAVE_PWDBASED
#define HAVE_POLY1035

/* Disables - For minimum wolfCrypt build */
#define WOLFSSL_NO_PEM
#define NO_RC4
#define NO_DSA
#define NO_MD4
#define NO_DH
#define NO_RABBIT
#define NO_SIG_WRAPPER
#define NO_CERT
#define NO_SESSION_CACHE
#define NO_HC128
#define NO_DES3
#define WC_NO_HASHDRBG
#define NO_WRITEV
#define NO_DEV_RANDOM
#define NO_FILESYSTEM
#define NO_MAIN_DRIVER
#define NO_OLD_RNGNAME
#define NO_WOLFSSL_DIR
#define WOLFSSL_NO_SOCK
#define WOLFSSL_IGNORE_FILE_WARN
#define NO_ERROR_STRINGS


#define WOLFSSL_USER_CURRTIME
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "Bsp.h"
static inline double aurix_current_time(int reset)
{
    uint64 t = IfxStm_get(&MODULE_STM0);
    double div = IfxStm_getFrequency(&MODULE_STM0) * 1.0;
    (void)reset;
    return t / div;
}
#define WOLFSSL_CURRTIME_REMAP aurix_current_time

#define BENCH_EMBEDDED
#define XPRINTF printf

#endif /* !H_USER_SETTINGS_ */
