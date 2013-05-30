#include <stdio.h>
#include <stdlib.h>



void str_trim(char* str) {
  char* copy = str;
  char* travel = str;
  //eat blank
  for(; *travel == ' '; travel++)
    ;
  while((*copy = *travel++) != '\0') {
    if(*copy == ' ') {
      switch(*travel) {
      case ' ':
      case '\n':
      case '\0':
        break;
      default:
        copy++;
      }
    }
    else {
      if(*copy == '\n') {
        for(;*travel == ' '; travel++)
          ;
      }
      copy++;
    }
  }
}

void str_exchange_print(char* string, char* offset, int size) {
  for(int i = 0; i < size; i++) {
    char tmp = *offset;
    *offset = *(offset + i);
    *(offset + i) = tmp;
    str_exchange_print(string, offset + 1, size - 1);
    if(size == 1) printf("%s\n", string);
    *(offset + i) = *offset;
    *offset = tmp;
  }
}

void str_exc_print(char* string, int begin, int size, int* array) {
  if(begin == size) {
    for(int i = 0; i < size; i++) {
      printf("%c", *(string + array[i]));
    }
    printf("\n");
    return;
  }

  for(int i = 0; i < size; i++) {
    int flag = 0;
    for(int j = 0; j < begin; j++) {
      if(array[j] == i) {
        flag = 1;
      }
    }
    if(flag == 1)
      continue;
    array[begin] = i;
    str_exc_print(string, begin + 1, size, array);
  }
}

int main() {
  /* char str[12] = {' ', ' ', 'a', ' ', '\n', ' ', 'b', ' ', '\n', ' ', ' ', '\0'}; */
  /* str_trim(str); */
  /* char* p = str; */
  /* int length = 0; */
  /* while(*p != '\0') { */
  /*   printf("%c", *p); */
  /*   p++; */
  /*   length++; */
  /* } */
  /* printf("\nlength is %d\n", length); */
  int array[4];
  char string[5] = {'a', 'b', 'c', 'd', '\0'};
  str_exchange_print(string, string, 4);
  //  str_exc_print(string, 0, 4, array);
}
