#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOOL enum{true, false}
#define OUT "rand_numbers.txt"
#define BUFFER_SIZE 1024
#define AMMOUNT 10000000

FILE* get_new_file(char* file_path, char* mode) {
  FILE* file;
  if((file = fopen(file_path, "r")) != NULL) {
    printf("file exist, processing delete\n");
    remove(file_path);
  }
  if((file = fopen(file_path, mode)) != NULL) {
    return file;
  }
  printf("open file error\n");
  return NULL;
}

void main(int argc, char** argv) {
  int num = 0;
  if(argc >= 2) {
    char* ammount = *(++argv);
    while(*ammount)
      num = num * 10 + *(ammount++) - '0';
    printf("would generate %d random integers\n", num);
  } else num = AMMOUNT;

  unsigned int buffer[BUFFER_SIZE];
  FILE* file;

  if((file = get_new_file(OUT, "a")) != NULL) {
    srand((unsigned)time(NULL));
    unsigned int count = 0;
    int buffer_index = 0;
    while(count++ < num) {
      if(buffer_index == BUFFER_SIZE) {
        fwrite(buffer, sizeof(int), BUFFER_SIZE, file);
        buffer_index = 0;
      }
      buffer[buffer_index++] = rand() % num;
    }
    fwrite(buffer, sizeof(int), buffer_index, file);
    printf("finish generate random numbers\n");
  }
}
