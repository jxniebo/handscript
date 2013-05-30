// just draft, need much more improvement

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "../lib.h"

int structure_match(long int matcher)
{
  while(matcher) {
    short mod = matcher % 10;
    if(mod != 0 && mod != 1) return 0;
    matcher /= 10;
  }

  return 1;
}
long int get_match(int num)
{
  long int matcher = 1;
  while(matcher < INT_MAX) {
    if(structure_match(matcher) && matcher % num == 0)
      return matcher;
    matcher++;
  }
  return 0;
}

int main(int argc, char** argv)
{
  if(argc != 2) {
    fprintf(stderr, "not proper input, should have exactly one integer\n");
    exit(1);
  }

  unsigned int num = (unsigned)char_to_integer(argv[1]);
  printf("the min integer which match %d is %ld\n", num, get_match(num));

  return 0;
}
