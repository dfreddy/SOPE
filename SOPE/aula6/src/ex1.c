#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2
#define NUMITER 2000

void * thrfunc(void * arg) {
  int i;
  fprintf(stderr, "\nStarting thread %s\n", (char *) arg);
  for (i = 1; i <= NUMITER; i++) write(STDERR,arg,1);
  printf("\n");

  return NULL;
}

int main() {
  pthread_t ta, tb;
  char * a = "1", *b = "2";
  pthread_create(&ta, NULL, thrfunc, a);
  pthread_create(&tb, NULL, thrfunc, b);
  pthread_join(ta, NULL);
  pthread_join(tb, NULL);

  return 0;
}
