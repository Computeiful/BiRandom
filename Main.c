#include "BiRandom.h"
#include <stdio.h>
#include <time.h>

/*
This is free and unencumbered software released into the public domain.
Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.
In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
For more information, please refer to <http://unlicense.org/>
*/

void check(union BiRandom *a) { 
	// Check the header for the expected values and bounds of each call

	for(uint64_t i = 0; i < 1000; i++) {
		const uint64_t n = BiRandom_Range(a, i + 1);
		assert(n <= i + 1);
	}

	for(int i = 0; i < 1000; i++) {
		uint64_t n = BiRandom_Between(a, 10, 1000);
		assert(n >= 10 && n < 1000);
	}

	for(int i = 0; i < 1000; i++) {
		double n = BiRandom_Uniform(a);
		assert(n >= 0 && n <= 1);
	}

	for(int i = 0; i < 1000; i++) {
		double n = BiRandom_Gaussian(a);
		assert(n >= -6 && n <= 6);
	}
}

int main(void) {
	union BiRandom a;
	a.seed = (uint64_t) time(NULL);

	for(int i = 0; i < 10; i++) {
		printf("%08X\n", (int) BiRandom(&a));
	}

	check(&a); // Test
}

/*


	This padding exists so that GitHub views this project as a C project rather than a C++ project,
	because it sees .h files as C++ files, which is so dumb.


*/