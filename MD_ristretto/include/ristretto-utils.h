// This file is part of ristretto-donna.
// Copyright (c) 2019 isis lovecruft
// See LICENSE for licensing information.
//
// Authors:
// - isis agora lovecruft <isis@patternsinthevoid.net>

#ifndef RISTRETTO_UTILS_H
#define RISTRETTO_UTILS_H

#include <stdlib.h>

#if defined(__cplusplus)
extern "C" {
#endif

#ifdef DEBUGGING
#define PRINT(x, ...)                                    \
  printf(x, ##__VA_ARGS__);                              \
  printf("\n");
#else
#define PRINT(x, ...) do {} while (0)
#endif

#ifdef __GNUC__
#define FREE(p)                                          \
  typeof(&(p)) tmpvar = &(p);                            \
  free(*tmpvar);                                         \
  *tmpvar=NULL;
#else
#define FREE(p)                                          \
  free(p);                                               \
  (p)=NULL;
#endif

void fe_print(const bignum25519 fe);
void fe_print(const bignum25519 fe)
{
  PRINT("{%lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu, %lu}",
        fe[0], fe[1], fe[2], fe[3], fe[4],
        fe[5], fe[6], fe[7], fe[8], fe[9]);
}

#if defined(__cplusplus)
}
#endif

#endif // RISTRETTO_UTILS_H
