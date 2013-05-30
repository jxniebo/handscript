#include <stdio.h>
#include <stdlib.h>
#include "../lib.h"



long int efficient_fib(int n) {
  if(n <= 0) return 0;
  if(n == 1) return 1;
  long int record[] = {0, 1};
  long int fib_value = 0;
  while(n-- >= 2) {
    fib_value = record[0] + record[1];
    record[0] = record[1];
    record[1] = fib_value;
  }

  return fib_value;
}

int main(int argc, char** argv)
{
  if(argc != 2) {
    fprintf(stderr, "not proper input, should contains exactly one integer\n");
    exit(1);
  }

  int num = char_to_integer(argv[1]);
  printf("fib_value of %d would be %ld\n", num, efficient_fib(num));

  return 0;
}
