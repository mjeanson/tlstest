#include <stdio.h>
#include <assert.h>
#include "mylib.h"

__thread struct mytls mytls;

void mylib_test(long add) {
	printf("t%ld ctr init: %lu\n", add, mytls.ctr);
	assert(mytls.ctr == 0);
	mytls.ctr = add;
	printf("t%ld ctr add : %lu\n", add, mytls.ctr);
}
