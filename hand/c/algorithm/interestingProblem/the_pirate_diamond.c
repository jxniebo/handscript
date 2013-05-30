#include <stdio.h>
#include <stdlib.h>

#define NUM  10
#define AMMOUNT 100

int scheme[NUM];

void scheme_print() {
  printf("the scheme would be:\n");
  for(int i = 0; i < NUM; i++) {
    printf("%d ", scheme[i]);
  }
  printf("\n");
}

int select_max(int begin_with) {
  int max = begin_with;
  for(int i = begin_with; i < NUM; i++) {
    if(scheme[i] > scheme[max])
       max = i;
  }
  return max;
}
void allocate_diamond(int scheme_num) {
  if(scheme_num >= NUM) return;
  //let left pirates allocate first
  allocate_diamond(scheme_num + 1);
  int pirate_left = NUM - scheme_num - 1;
  int pirate_persuade = (pirate_left + 1) / 2;
  int pirate_derive = pirate_left - pirate_persuade;
  //derive pirate doesn't need persuade to -1
  for(int i = 0; i < pirate_derive; i++) {
    int derive_num = select_max(scheme_num + 1);
    scheme[derive_num] = -1;
  }
  //persuade left
  int diamond_left = AMMOUNT;
  for(int i = scheme_num + 1; i < NUM; i++) {
    scheme[i]++;
    diamond_left -= scheme[i];
  }
  // if not enough diamond to persuade, use others' scheme
  if(diamond_left <= 0) {
    allocate_diamond(scheme_num + 1);
    scheme[scheme_num] = 0;
  }
  else scheme[scheme_num] = diamond_left;
}



int main() {
  allocate_diamond(NUM - 1);
  scheme_print();


}
