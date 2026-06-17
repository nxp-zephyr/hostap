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
#define PSA_WANT_ALG_SHA_256                    1
#define PSA_WANT_ALG_SHA_384                    1
#define PSA_WANT_ALG_SHA_512                    1

/** Key derivation — WPA2-PSK (PBKDF2) and WPA3 (HKDF) */
#define PSA_WANT_ALG_PBKDF2_HMAC                1
#define PSA_WANT_ALG_HKDF_EXPAND                1

/** TLS 1.3 required PSA algorithms in Secure World */
#define PSA_WANT_ALG_HKDF_EXTRACT               1
#define PSA_WANT_ALG_ECDH                       1
#define PSA_WANT_ALG_ECDSA                      1
#define PSA_WANT_ALG_GCM                        1
#define PSA_WANT_KEY_TYPE_AES                   1
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_GENERATE  1
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_IMPORT    1
#define PSA_WANT_KEY_TYPE_ECC_KEY_PAIR_EXPORT    1
#define PSA_WANT_ECC_SECP_R1_256                1
#define PSA_WANT_ECC_SECP_R1_384                1

#define PSA_WANT_ALG_RSA_PSS                     1
#define PSA_WANT_ALG_RSA_PKCS1V15_SIGN          1
#define PSA_WANT_KEY_TYPE_RSA_KEY_PAIR_IMPORT     1

#endif /* MBEDTLS_USER_CONFIG_H */
