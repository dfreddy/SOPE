#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NUM_THREADS 4

struct Nums {
  int a, b, tnum;
};

void *Maths(void *t) {
  struct Nums *nums = (struct Nums*) t;

  double f = (double)(*nums).a / (double)(*nums).b;

  if((*nums).tnum == 0) printf("Sum = %d\n", (*nums).a + (*nums).b);
  if((*nums).tnum == 1) printf("Sub = %d\n", (*nums).a - (*nums).b);
  if((*nums).tnum == 2) printf("Mult = %.2f\n", (float)(*nums).a * (*nums).b);
  if((*nums).tnum == 3) printf("Div = %.2f\n", f);

  pthread_exit(NULL);
}

int main(){
  pthread_t threads[NUM_THREADS];
  int i, a , b;

  printf("Input numbers <a> then <b>\n");
  scanf("%d", &a); scanf("%d", &b );

  for(i=0; i< NUM_THREADS; i++){
    struct Nums *nums;
    nums = malloc(sizeof(struct Nums));
    (*nums).tnum = i;
    (*nums).a = a;
    (*nums).b = b;
    printf("Creating thread %d\n", (*nums).tnum);
    pthread_create(&threads[i], NULL, Maths, (void *) nums);
  }

  pthread_exit(0);
}
