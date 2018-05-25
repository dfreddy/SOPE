#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#define STDERR 2
#define NUMITER 2000
#define MAX_N 5000

static int n = MAX_N;

void * thrfunc(void * arg) {
  int i, c=0;
  fprintf(stderr, "\nStarting thread %s\n", (char *) arg);

  for (; n > 0; --n) {
    write(STDERR,arg, (char*) arg);
    c++;
  }

  printf("\n");

  //return (void*) c;
  pthread_exit(c);
}

int main() {
  pthread_t ta, tb;
  void *a_status, *b_status;
  char *a = "1", *b = "2";

  pthread_create(&ta, NULL, thrfunc, a);
  pthread_create(&tb, NULL, thrfunc, b);
  pthread_join(ta, &a_status);
  pthread_join(tb, &b_status);

  printf("Thread a did %d\n", (int)a_status);
  printf("Thread b did %d\n", (int)b_status);

  return 0;
}
