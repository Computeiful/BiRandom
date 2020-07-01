#include "BiRandom.h"
#include <stdio.h>
#include <time.h>

int main(void) {
	union Random a;
	a.seed = (uint64_t) time(NULL);

	for(int i = 0; i < 10; i++) {
		printf("%08X\n", (int) BiRandom(&a));
	}
}
