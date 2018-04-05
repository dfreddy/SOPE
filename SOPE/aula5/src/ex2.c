#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

#define READ 0
#define WRITE 1

int main(void) {
  int p[2];
  int r[1];
  pipe(p);
  pipe(r);

  pid_t pid, w_pid;
  int status = 0;
  pid=fork();

  if (pid > 0){
    // PARENT
    struct parent{
      int x;
      int y;
    } a;

    printf("First number: "); scanf("%d", &(a.x));
    printf("Second number: "); scanf("%d", &(a.y));

    close(p[READ]);
    write(p[WRITE], &a, sizeof(struct parent));
    close(p[WRITE]);

    while((w_pid = wait(&status)) > 0);

    // access pipe r
    int dd;
    close(r[WRITE]);
    read(r[READ], &dd, sizeof(int));
    close(r[READ]);

    switch(dd) {
      case -1:
      printf("Result is invalid\n");
      break;
      case 0:
      printf("Result is an integer\n");
      break;
      case 1:
      printf("Result is a float\n");
      break;
      default:
      printf("ERROR\n");
      break;
    }

  }

  else {
    // CHILD
    struct child{
      int x;
      int y;
    } b;
    close(p[WRITE]);
    read(p[READ], &b, sizeof(struct child));
    close(p[READ]);

    int d;
    float f = b.x / (float)b.y;
    if(b.y == 0) d = -1;
    else {
      if(roundf(f) == f) d = 0;
      else d = 1;
    }

    close(r[READ]);
    write(r[WRITE], &d, sizeof(int));
    close(r[WRITE]);


    printf("%d + %d = %d\n", b.x, b.y, b.x + b.y);
    printf("%d - %d = %d\n", b.x, b.y, b.x - b.y);
    printf("%d * %d = %.2f\n", b.x, b.y, b.x * (float)b.y);
    printf("%d / %d = %.2f\n", b.x, b.y, f);

  }

  exit(0);
}
