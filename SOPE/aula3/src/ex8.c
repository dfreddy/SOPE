#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {
  pid_t pid;
  int status=0;

  if (argc != 2) {
    printf("usage: %s dirname\n",argv[0]);
    exit(1);
  }

  pid=fork();

  if (pid > 0) {
    wait(0);
    waitpid(-1, &status, WNOHANG);
    printf("Exit code: %d\n", status);

    if(WIFEXITED(&status)) printf("Success\n");
    else if(WIFSIGNALED(&status)) printf("Error\n");
  }

  else if (pid == 0) {
    execlp(argv[1], argv[1], "-laR", NULL);
    printf("Command not executed !\n");
    exit(1);
  }

  exit(0);
}
