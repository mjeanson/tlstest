#include <stdlib.h>
#include <pthread.h>

struct mytls {
	unsigned long ctr;
	int32_t futex;
};

extern __thread struct mytls mytls;

void mylib_test(long add);
