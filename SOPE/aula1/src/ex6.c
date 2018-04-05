#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define BUF_LENGTH 256
#define MAX 8

void handler1() {
  printf("Executing exit handler 1\n");
}

void handler2() {
  printf("Executing exit handler 2\n");
}

int main(int argc, char* argv[])
{
  if(argc < 2) {
    printf("Usage: ./exe <infile.txt> <outfile.txt>");
    exit(3);
  }

  atexit(handler1);
  atexit(handler2);

  FILE *src, *dst;
  char buf[BUF_LENGTH];
  char *infile, *outfile;

  infile = argv[1];
  outfile = argv[2];

  if((src = fopen(infile, "r")) == NULL) {
    printf("Error number %d - no infile\n", errno);
    exit(1);
  }
  if((dst = fopen(outfile, "w")) == NULL) {
    printf("Error number %d - no outfile\n", errno);
    exit(2);
  }

  while((fgets( buf, MAX, src)) != NULL) {
    fputs( buf, dst );
  }

  fclose( src );
  fclose( dst );

  printf("Main done\n");
  exit(0);  // zero é geralmente indicativo de "sucesso"
}
