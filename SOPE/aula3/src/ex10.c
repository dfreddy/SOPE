#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

// BUGGED

int main(int argc, char *argv[], char *envp[]) {
  unsigned char buffer[BUFFER_SIZE];
  pid_t pid;
  int status=0;
  int out=0;
  FILE *file;

  if (argc < 2) {
    printf("usage: %s <dirname> <output_file(optional)>\n",argv[0]);
    exit(1);
  }

  if(argc == 3) out=1;

  pid=fork();

  if(out==1) {

    if((file = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, 0644) == -1) {
      perror(argv[2]);
      close(file);
      exit(2);
    }
  }

  if (pid > 0) {
    wait(0);
    waitpid(-1, &status, WNOHANG);
    printf("Exit code: %d\n", status);

    if(WIFEXITED(&status)) printf("Success\n");
    else if(WIFSIGNALED(&status)) printf("Error\n");

    if(out==1) close(file);
  }

  else if (pid == 0) {
    if(out==1) {
      close(1); // close stdout
      dup(file);
    }

    execlp(argv[1], argv[1], "-laR", NULL);
    printf("Command not executed !\n");
    exit(3);
  }

  exit(0);
}
