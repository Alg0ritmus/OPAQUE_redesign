#include "ed25519-donna-portable-identify.h"

#define mul32x32_64(a,b) (((uint64_t)(a))*(b))

/* platform */
#if defined(COMPILER_MSVC)
	#include <intrin.h>
	#if !defined(_DEBUG)
		#undef mul32x32_64		
		#define mul32x32_64(a,b) __emulu(a,b)
	#endif
	#undef inline
	#define inline __forceinline
	#define DONNA_INLINE __forceinline
	#define DONNA_NOINLINE __declspec(noinline)
	#define ALIGN(x) __declspec(align(x))
	#define ROTL32(a,b) _rotl(a,b)
	#define ROTR32(a,b) _rotr(a,b)
#else
	#include <sys/param.h>
	#define DONNA_INLINE inline __attribute__((always_inline))
	#define DONNA_NOINLINE __attribute__((noinline))
	#define ALIGN(x) __attribute__((aligned(x)))
	#define ROTL32(a,b) (((a) << (b)) | ((a) >> (32 - b)))
	#define ROTR32(a,b) (((a) >> (b)) | ((a) << (32 - b)))
#endif

#include <stdlib.h>
#include <string.h>


