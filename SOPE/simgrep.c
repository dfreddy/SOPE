#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#define BUF_LENGTH 256
#define MAX 8

int isDir(const char* name) {
  DIR* directory = opendir(name);

  if(directory != NULL) {
    closedir(directory);
    return 0;
  }

  return 1;
}

char** searchFileFor(FILE file, char* pattern) {
  char** arrayOfLines;
  int array_counter = 0;
  int file_line=1; // this is one of the options

  char * line = NULL;
  size_t len = 0;
  ssize_t read;

  while ((read = getline(&line, &len, src)) != -1) {
        char* tmp = strstr(line, pattern))
      if(tmp != NULL) {
arrayOfLines[array_counter] = line;
array_counter++;
}
file_line++;
    }

return arrayOfLines;
}

void main(int argc, char* argv[]) {

  if(argc < 3) {
    perror("ERROR: wrong arguments input. Try [options] <pattern> <file/dir>\n");
    exit(2);
  }

  char* pattern = argv[argc-2];

  FILE *src;
  char buf[BUF_LENGTH];
  char *file = argv[argc-1];


// TODO - implement directory option later
  if(isDir(file) == 0) {
    perror("Directory search not working yet\n");
    exit(3);
  }

// open file
  if((src = fopen(file, "r")) == NULL) {
    printf("Error number %d - no such file\n", errno);
    exit(4);
  }

  // TODO -read line by line
  char** arrayOfLines = searchFileFor(src, pattern);

  exit(1);
}
