#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include "mylib.h"

#define NUM_THREADS 4

__thread long ctr;

void *pthreadhello(void *threadid) {
   ctr = (long) threadid;
   //printf("Hello World! It's me, thread #%ld!\n", ctr);
   mylib_test((long) threadid);
   pthread_exit(NULL);
}

void toto(void) {

  pthread_t threads[NUM_THREADS];
  int rc;

  for (long t=0; t<NUM_THREADS; t++) {
    printf("In main: creating thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, pthreadhello, (void *)t);
    if (rc) {
      printf("ERROR; return code from pthread_create() is %d\n", rc);
      exit(1);
    }
  }

  for (long t=0; t<NUM_THREADS; t++) {
    pthread_join(threads[t], NULL);
  }
}


int main(int argc, const char* argv[]) {

  for (int i=0; i<10000; i++) {
	  toto();
  }
  return 0;
}
