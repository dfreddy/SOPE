#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define BUF_LENGTH 256
#define MAX 8

int main(int argc, char* argv[])
{
  if(argc < 2) {
    printf("Usage: ./copy <source> <dest>");
    exit(3);
  }

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

  int i=0;
  fseek(src, 0, SEEK_END);
  i = ftell(src);
  rewind(src);

  char* s[i];
  fread(s, 1, i, src);

  fwrite(s, 1, i, dst);

  fclose(src);
  fclose(dst);

  exit(0);
}
