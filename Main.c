#include "Random.h"
#include <stdio.h>
#include <time.h>

int main(void) {
	union Random a;
	a.seed = (uint64_t) time(NULL);
	printf("%08X\n", (int) Random_Consume(&a));
}
