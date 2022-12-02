// This file is part of ristretto-donna.
// Copyright (c) 2019 isis lovecruft
// See LICENSE for licensing information.
//
// Authors:
// - isis agora lovecruft <isis@patternsinthevoid.net>

#ifndef RISTRETTO_DONNA_H
#define RISTRETTO_DONNA_H

#include "ed25519-donna.h"
#include "ristretto-utils.h"

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * A `ristretto_point_t` internally holds an Edwards point in extended twisted
 * Edwards coordinates.
 */
typedef struct ristretto_point_s {
    ge25519 point;
} ristretto_point_t;

/**
 * Edwards `d` value from the curve equation, equal to `-121665/121666 (mod p)`.
 */
const bignum25519 EDWARDS_D = {
    56195235, 13857412, 51736253,  6949390,   114729,
    24766616, 60832955, 30306712, 48412415, 21499315,
};

/**
 * Precomputed value of one of the square roots of -1 (mod p)
 */
const bignum25519 SQRT_M1 = {
    34513072, 25610706,  9377949, 3500415, 12389472,
    33281959, 41962654, 31548777,  326685, 11406482,
};

const bignum25519 one = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const bignum25519 negative_one = {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const bignum25519 INVSQRT_A_MINUS_D = {
  6111466,  4156064, 39310137, 12243467, 41204824,
  120896, 20826367, 26493656,  6093567, 31568420,
};

/**
 * The Ristretto basepoint in compressed form.
 */
const unsigned char RISTRETTO_BASEPOINT_COMPRESSED[32] = {
        0xe2, 0xf2, 0xae, 0x0a, 0x6a, 0xbc, 0x4e, 0x71,
        0xa8, 0x84, 0xa9, 0x61, 0xc5, 0x00, 0x51, 0x5f,
        0x58, 0xe3, 0x0b, 0x6a, 0xa5, 0x82, 0xdd, 0x8d,
        0xb6, 0xa6, 0x59, 0x45, 0xe0, 0x8d, 0x2d, 0x76,
};

int ristretto_decode(ristretto_point_t *element, const unsigned char bytes[32]);

void ristretto_encode(unsigned char bytes[32], const ristretto_point_t *element);

int ristretto_ct_eq(const ristretto_point_t *a, const ristretto_point_t *b);

#ifdef RISTRETTO_DONNA_PRIVATE

uint8_t curve25519_invsqrt(bignum25519 out, const bignum25519 v);

uint8_t uint8_32_ct_eq(const unsigned char a[32], const unsigned char b[32]);

uint8_t bignum25519_ct_eq(const bignum25519 a, const bignum25519 b);

#endif // RISTRETTO_DONNA_PRIVATE

#if defined(__cplusplus)
}
#endif

#endif // RISTRETTO_DONNA_H
