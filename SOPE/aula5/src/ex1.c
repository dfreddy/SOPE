#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define READ 0
#define WRITE 1

int main(void) {
  int p[2];
  pipe(p);

  pid_t pid;
  pid=fork();

  if (pid > 0){
    // PARENT
    struct parent{
      int x;
      int y;
    } a;

    printf("First number: "); scanf("%d", &(a.x));
    printf("Second number: "); scanf("%d", &(a.y));

    if(a.y == 0) {
      printf("Second number can't be 0");
      exit(1);
    }

    close(p[READ]);
    write(p[WRITE], &a, sizeof(struct parent));
    close(p[WRITE]);
  }

  else {
    // CHILD
    struct child{
      int x;
      int y;
    } b;
    close(p[WRITE]);
    read(p[READ], &b, sizeof(struct child));

    if(b.y == 0) {
      exit(1);
    }

    printf("%d + %d = %d\n", b.x, b.y, b.x + b.y);
    printf("%d - %d = %d\n", b.x, b.y, b.x - b.y);
    printf("%d * %d = %.2f\n", b.x, b.y, b.x * (float)b.y);
    printf("%d / %d = %.2f\n", b.x, b.y, b.x / (float)b.y);

    close(p[READ]);
  }

  exit(0);
}
