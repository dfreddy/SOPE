#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX_PASSWD_LEN 20

int global=1;

int main(void) {
  printf("1\n");
 //write(STDOUT_FILENO,"1",1);

 if(fork() > 0) {
   printf("2");
   printf("3");
   //write(STDOUT_FILENO,"2",1);
   //write(STDOUT_FILENO,"3",1);
 }
 else {
   printf("4");
   printf("5");
   //write(STDOUT_FILENO,"4",1);
   //write(STDOUT_FILENO,"5",1);
 }
 printf("\n");
 //write(STDOUT_FILENO,"\n",1);

 return 0;
}
