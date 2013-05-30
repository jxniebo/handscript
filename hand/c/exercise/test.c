#include <stdio.h>


int main(int argc, char** argv)
{

  int sec_array[10][10];
  for(int i = 0; i < 10; i++) {
    for(int j = 0; j < 10; j++) {
      sec_array[i][j] = i * 10 + j;
    }
  }
  int* a = NULL;
  char* b = "abc";
  //  *b = 'c';
  return 0;
}
