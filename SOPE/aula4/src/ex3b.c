#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int inc = 1;

void sig_handler(int sig) {
  if(sig == SIGUSR1) {
    printf("SIGUSR1\n");
    inc = 1;
  }
  else if(sig == SIGUSR2) {
    printf("SIGUSR2\n");
    inc = -1;
  }
}

int main(void) {
  int v = 0;
  srand(time(NULL));
  struct sigaction action;

  action.sa_handler = sig_handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;

  if (sigaction(SIGUSR1,&action,NULL) < 0) {
    fprintf(stderr,"Unable to install SIGUSR1 handler\n");
    exit(1);
  }

  if (sigaction(SIGUSR2,&action,NULL) < 0) {
    fprintf(stderr,"Unable to install SIGUSR2 handler\n");
    exit(2);
  }

  int j;
  pid_t pid = fork();

  if(pid == 0) {
    for(j=0; j < 20; j++) {
      printf("v: %d\n", v);
      v += inc;
      sleep(1);
    }
  }
  if(pid > 1) {
    for(j=0; j < 20; j++) {
      sleep(1);
      int r = rand() % 100;
      if(r < 15) kill(pid, SIGUSR1);
      else if (r < 30) kill(pid, SIGUSR2);
    }
  }


exit(0);
}
