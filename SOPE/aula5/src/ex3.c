#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

#define READ 0
#define WRITE 1
#define BUF 1024

int main(int argc, char *argv[]) {

  if(argc != 2) {
    printf("Error: usage is %s <filename>\n", argv[0]);
    exit(1);
  }

  FILE *file = fopen(argv[1], "r");
  if (file == 0) {
    fprintf(stderr, "%s: failed to open file '%s'\n", argv[0], argv[1]);
    exit(1);
  }

  char buf[BUF];
  int p[2];
  pipe(p);

  int bytes_read = fread(buf, 1, sizeof(buf), file);
  if (bytes_read <= 0) {
    fprintf(stderr, "%s: no data in file '%s'\n", argv[0], argv[1]);
    exit(2);
  }
  fclose(file);

  close(p[READ]);
  write(p[WRITE], buf, bytes_read);
  close(p[WRITE]);

  dup2(p[READ], STDIN_FILENO);
  close(p[READ]);

  execlp("sort", "sort",(char *)0);
  fprintf(stderr, "%s: failed to exec 'sort'\n", argv[0]);

  exit(3);
}
