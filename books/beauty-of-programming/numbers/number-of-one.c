#include <stdio.h>
#include <stdlib.h>


void find_one_in_binary(int number);
void find_zero_in_factorial(int number);

int main(int argc, char** argv)
{
  int count = 0, number = 0;
  if(argc > 1) {
    char* string = argv[1];
    while(*string != '\0') {
      if(*string > '9' || * string < '0') {
        fprintf(stderr, "not proper input, should be unsigned integers\n");
        exit(1);
      } else {
        number = number * 10 + (*string++ - '0');
      }
    }
  }


  //  find_one_in_binary(number);
  find_zero_in_factorial(number);
}




void find_one_in_binary(int number)
{
  int count = 0;
  //i & i - 1 would eliminate the last 1 in binary code
  for(int i = number; i; i &= i - 1) {
    count++;
  }
  printf("the number of 1 in %d would be %d\n", number, count);
}


void find_zero_in_factorial(int number)
{
  long factor = 1;
  int count = 0;
  while(number) {
    factor *= number;
    for(int i = number; i % 5 == 0; i /= 5) {
      count++;
    }

    number--;
  }
  printf("%ld has %d of 0\n", factor, count);
}
