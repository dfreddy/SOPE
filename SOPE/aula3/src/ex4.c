#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX 50000

int main(void) {
  int i;
  pid_t pid, wpid;
  char str[10];
  pid=fork();

  switch (pid) {

    case -1:
      perror("fork");
      break;

    case  0: //filho
      //printf(" world !\n");
      printf("Hello");
      break;

    default: //pai
      //printf("Hello");
      while(wpid = wait(0) > 0);
      printf(" world !\n");
  }

  return 0;
}
