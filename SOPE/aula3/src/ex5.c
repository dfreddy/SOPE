#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define MAX 50000

int main(void) {
  int i;
  pid_t pid, wpid, cpid;
  char str[10];
  pid=fork();

  switch (pid) {

    case -1:
      perror("fork");
      break;

    case  0: //filho
      cpid = fork();
      if(cpid == 0)
        printf(" friends!\n");
      else
        printf(" my");
      break;

    default: //pai
      printf("Hello");
  }

  return 0;
}
