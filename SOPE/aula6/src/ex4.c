#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 10

void *Sleep(void *threadnum) {
  sleep(1);
  printf("Hello from thread w id %ld!\n", (long) pthread_self());

  pthread_exit(NULL);
}

int main(){
  pthread_t threads[NUM_THREADS];
  int t;

  for(t=0; t< NUM_THREADS; t++){
    printf("Creating thread %d\n", t);
    pthread_create(&threads[t], NULL, Sleep, (void *)t);
  }

  pthread_exit(0);
}
