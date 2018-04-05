#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int inc = 1;

void sig_handler(int sig) {
  if(sig == SIGUSR1) {
    inc = 1;
  }
  else if(sig == SIGUSR2) {
    inc = -1;
  }
}

int main(void) {
  int v = 0;

  struct sigaction action;

  action.sa_handler = sig_handler;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;

  if (sigaction(SIGUSR1,&action,NULL) < 0) {
    fprintf(stderr,"Unable to install SIGUSR1 handler\n");
    exit(1);
  }

  printf("ok\n");

  if (sigaction(SIGUSR2,&action,NULL) < 0) {
    fprintf(stderr,"Unable to install SIGUSR2 handler\n");
    exit(2);
  }

  printf("ok\n");

  while(1) {
    printf("v: %d\n", v);
    v += inc;
    sleep(1);
  }

  exit(0);
}
