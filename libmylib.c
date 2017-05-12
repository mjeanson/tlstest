#include <stdio.h>
#include "mylib.h"

__thread struct mytls mytls;

void mylib_test(long add) {
	printf("t%ld ctr init: %lu\n", add, mytls.ctr);
	mytls.ctr = add;
	printf("t%ld ctr add : %lu\n", add, mytls.ctr);
}
