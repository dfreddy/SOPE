#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]) {
  if(argc < 2) {
    printf("Usage: ./read <file> <dup_file(optional)>");
    exit(3);
  }

  FILE *src;
  char buf[BUF_LENGTH];
  char *infile;

  infile = argv[1];

  if((src = fopen(infile, "r")) == NULL) {
    printf("Error number %d - no infile\n", errno);
    exit(1);
  }

  int i=0;
  fseek(src, 0, SEEK_END);
  i = ftell(src);
  rewind(src);

  char* s[i];
  fread(s, 1, i, src);

  if(argc == 3) {
    FILE *dst;
    char *outfile;
    outfile = argv[2];

    if((dst = fopen(outfile, "w")) == NULL) {
      printf("Error number %d - no outfile\n", errno);
      exit(2);
    }

    fwrite(s, 1, i, dst);

    printf("Duplicated\n");
    fclose(dst);
  }
  else {
    printf(s);
  }

  fclose(src);

  exit(0);
}
