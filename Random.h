#ifndef BIRANDOM_H
#define BIRANDOM_H

	#include <stdint.h>
	#include <assert.h>

	#ifndef __AES__
		#error // use -maes on gcc and clang
	#endif

	#include <wmmintrin.h>
	#include <emmintrin.h>

	union Random {
		uint64_t seed;
	};

	uint64_t BiRandom(union Random *a) {
		union {
			__m128i i;
			uint64_t U, L;
		} seed;
		seed.i = _mm_set1_epi64x((int64_t) a->seed);
		seed.i = _mm_aesenc_si128(seed.i, _mm_set1_epi32((int) 0xDEADBEEF));
		seed.i = _mm_aesenc_si128(seed.i, _mm_set1_epi32((int) 0xDEADBEEF));
		a->seed = seed.L;
		return a->seed;
	}

	uint64_t BiRandom_Range(union Random *a, uint64_t max) {
		assert(max > 0);
		uint64_t n = 0;

		for(;;) { // Better than modulus
			n = BiRandom(a);
			if(n < UINT64_MAX - (UINT64_MAX % max)) break;
		}

		return (n % max);
	}

	uint64_t BiRandom_Between(union Random *a, uint64_t min, uint64_t max) {
		assert(max > min);
		return BiRandom_Range(a, max - min) + min;
	}

	double BiRandom_Uniform(union Random *a) { // Value between 0.0 and 1.0, mean of 0.5
		union {
			uint64_t u64;
			double f64;
		} map;
		map.u64 = 0x3FF0000000000000ULL | (BiRandom(a) >> 12);
		return (map.f64 - 1.0);
	}

	double BiRandom_Gaussian(union Random *a) { // Normal value, mean of 0.0, s.d. of 1.0 (values cannot exceed 6.0 or -6.0)
		double n = 0.0;

		for(char i = 0; i < 12; i++) {
			n += BiRandom_Uniform(a);
		}
		n -= 6.0;

		return n;
	}

#endif
