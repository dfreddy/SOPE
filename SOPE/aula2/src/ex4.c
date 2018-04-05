#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#define BUF_LENGTH 256
#define MAX 8

int main(int argc, char* argv[])
{
  if(argc != 2) {
    printf("Usage: ./write <file>");
    exit(3);
  }

  FILE *src;
  char buf[BUF_LENGTH];
  char *file;

  file = argv[1];

  if((src = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644)) == -1) {
    printf("Error number %d - no file\n", errno);
    exit(1);
  }

// unfinished



  close(src);

  exit(0);
}
