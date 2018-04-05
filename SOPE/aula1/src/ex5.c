#include <stdio.h>
#include <ctype.h>

void printArgs(int l, char* name[]) {
  printf("Args:");
  int i;
  for(i=1; i < l; i++) {
    printf(" "); printf(name[i]);
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  if(argc > 1) {
    printArgs(argc, argv);
  }

  return 22;
}
