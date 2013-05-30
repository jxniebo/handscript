#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../lib.h"

#define MIN(x, y, z) (x > y ? (y < z ? y : z) : (x > z ? z : x))

int similar_compare(char* s1, char* s2)
{
  int similarity = 0;
  if(s1 == NULL || s2 ==NULL) {
    fprintf(stderr, "attempt compare empty string\n");
    exit(1);
  }

  //when return?
  int len1 = strlen(s1), len2 = strlen(s2);
  while(*s1 == *s2 && *s1 != '\0') {
    s1++;
    s2++;
  }
  if(*s1 == *s2) return 0;
  if(*s1 == '\0') return len2 - len1;
  if(*s2 == '\0') return len1 - len2;

  //when recursion?
  int sim_del_s1 = 1 + similar_compare(s1 + 1, s2);
  int sim_del_s2 = 1 + similar_compare(s1, s2 + 1);
  int sim_up = 1 + similar_compare(s1 + 1, s2 + 1);

  return MIN(sim_del_s1, sim_del_s2, sim_up);
}


int main(int argc, char** argv)
{
  if(argc != 3) {
    fprintf(stderr, "should input exactly two string\n");
    exit(1);
  }

  char* s1 = argv[1];
  char* s2 = argv[2];

  int similarity = similar_compare(s1, s2);
  printf("the similarity is 1 / %d\n", similarity + 1);
  return 0;
}
