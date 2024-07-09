/*
 *  Copyright 2024 NXP
 *
 *  SPDX-License-Identifier: BSD-3-Clause
 *
 *  Configure Mbedtls options in Secure World
 */

#ifndef MBEDTLS_USER_CONFIG_H
#define MBEDTLS_USER_CONFIG_H

/** Options we need in Secure World */
#define PSA_WANT_ALG_MD5        1
#define PSA_WANT_ALG_SHA_1      1

#endif /* MBEDTLS_USER_CONFIG_H */
