#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Length 27

int main() {
  char* string = (char*)malloc(Length*sizeof(char));
  for(int i = 0; i < Length -1; i++) {
    *(string + i) = 'a' + i;
  }
  *(string + Length - 1) = '\0';
  printf("%s\n", string);

  void string_shift(char* string, char* shift, char* tail);
  void string_updown(char* string, char* shift, char* tail);
  srand(time(NULL));
  int shift_num = rand() % (Length - 1);
  string_shift(string, string + shift_num, string + Length - 2);
  printf("After shift %d position would be %s\n", shift_num, string);
  string_updown(string, string + (Length - 1 - shift_num), string + Length - 2);
  printf("Another check use upside down be %s\n", string);
 }

void swap_string(char* s1, char* s2, int num) {
  while(--num >= 0) {
    char tmp = *(s1 + num);
    *(s1 + num) = *(s2 + num);
    *(s2 + num) = tmp;
  }
}


void string_shift(char* head, char* shift, char* tail) {
  if(head >= shift || shift > tail) return;
  if(shift - head <= tail - shift + 1) {
    swap_string(head, shift, shift - head);
    string_shift(shift, shift + (shift - head), tail);
  } else {
    swap_string(head, shift, tail - shift + 1);
    string_shift(head + (tail - shift) + 1, shift, tail);
  }
}

void upsidedown(char* down, char* up) {
  int swap = (up - down) / 2;
  while(swap-- >= 0) {
    char tmp = *down;
    *(down++) = *up;
    *(up--) = tmp;
  }
}

void string_updown(char* head, char*shift, char*tail) {
  if(head>=shift || shift > tail) return;
  printf("check %s\n", head);
  upsidedown(head, shift - 1);
  printf("check %s\n", head);
  upsidedown(shift, tail);
  printf("check %s\n", head);
  upsidedown(head, tail);
}
