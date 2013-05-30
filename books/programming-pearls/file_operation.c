#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define IN "data/rand_numbers.txt"
#define TMP1 "data/tmp1.txt"
#define TMP2 "data/tmp2.txt"
#define OUT "data/result.txt"
#define BUFFER_SIZE 102400

void swap(int* p1, int* p2) {
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

FILE* get_new_file(char* file_path, char* mode) {
  FILE* file;
  if((file = fopen(file_path, "r")) != NULL) {
    remove(file_path);
  }
  if((file = fopen(file_path, mode)) != NULL) {
    return file;
  }
  printf("open file error\n");
  return NULL;
}

void quick_sort(int* head, int* tail) {
  if(head >= tail) return;
  int* travel = head;
  int* exchange = head;
  while(travel < tail) {
    if(*travel < *tail) {
      swap(travel, exchange++);
    }
    travel++;
  }

  swap(exchange, tail);
  quick_sort(head, exchange - 1);
  quick_sort(exchange + 1, tail);
}

void buffer_print(int* buffer, int count) {
  for(int i = 0; i < count; i++) {
    printf("%d\t", *(buffer + i));
    if((i + 1) % 14 == 0)
      printf("\n");
  }
  printf("%s", count % 20 == 0 ? "" : "\n");
}

void merge_number(int* buffer, int size, char* read, char* write) {
  FILE* fr = fopen(read, "r");
  FILE* fw = get_new_file(write, "a");
  int integer[BUFFER_SIZE];
  unsigned int count = fread(integer, sizeof(int), BUFFER_SIZE, fr);
  int buffer_index = 0;
  while(count > 0) {
    int integer_index = 0;
    while(buffer_index < size && integer_index < count) {
      if(buffer[buffer_index] < integer[integer_index]) {
        fwrite(&buffer[buffer_index++], sizeof(int), 1, fw);
      } else {
        fwrite(&integer[integer_index++], sizeof(int), 1, fw);
      }
    }
    fwrite(&integer[integer_index++], sizeof(int), count - integer_index, fw);
    count = fread(integer, sizeof(int), BUFFER_SIZE, fr);
  }
  fwrite(&buffer[buffer_index], sizeof(int), size - buffer_index, fw);

  fclose(fw);
  fclose(fr);
}

int main(void) {
  int start_t = time(0);

  int buffer[BUFFER_SIZE];
  FILE* fin = fopen(IN, "r");
  char* read = TMP1;
  char* write = TMP2;
  FILE* tmp = get_new_file(TMP1, "a");
  fclose(tmp);
  tmp = get_new_file(TMP2, "a");
  fclose(tmp);


  int count;
  while((count = fread(buffer, sizeof(int), BUFFER_SIZE, fin)) > 0) {
    quick_sort(buffer, buffer + count -1);
    merge_number(buffer, count, read, write);
    char* tmp = read;
    read = write;
    write = tmp;
  }
  fclose(fin);

  long int end_t = time(0);
  printf("has been %d seconds\n", (int)(end_t - start_t));

  FILE* print = fopen(write, "r");
  while(fread(buffer, sizeof(int), BUFFER_SIZE, print))
        buffer_print(buffer, BUFFER_SIZE);
}
