#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <ctype.h>
#define BUF_LENGTH 256

int main(int argc, char* argv[])
{
  if(argc != 3) {
    printf("Usage: ./exe <n1> <n2>");
    exit(1);
  }

  /* Intializes random number generator */
  time_t t;
  srand((unsigned) time(&t));

  int i=0, n, n1, n2;
  char *num1 = argv[1];
  char *num2 = argv[2];
  n1 = atoi(num1);
  n2 = atoi(num2);

  while(i < n1) {
    n = rand() % n1;
    printf("i: %d\tn: %d\n", i, n);

    if(n == n2) break;

    i++;
  }

  exit(0);
}
