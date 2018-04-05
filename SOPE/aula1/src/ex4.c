#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void printName(int l, char* name[]) {
  printf("Hello ");
  int i;
  for(i=1; i < l; i++) {
    printf(name[i]); printf(" ");
  }
  printf("!\n");
}

int main(int argc, char *argv[]) {
  if(argc > 1) {
    char* last = argv[argc-1];

    if(isdigit(last[0])) {
      int nr = atoi(last);
      while(nr > 0) {
        printName(argc-1, argv);
        nr--;
      }
    }
    else
      printName(argc, argv);
  }
  //else printf("Hello %s !\n", getenv("USER"));
  /*
  set | grep USER_NAME

  USER_NAME="Frederico"

  export USER_NAME
  */
  else printf("Hello %s !\n", getenv("USER_NAME"));

  return 21;
}
