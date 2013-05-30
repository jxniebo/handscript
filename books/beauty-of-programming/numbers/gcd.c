#include <stdio.h>
#include <stdlib.h>

#define ABS(x) ((x) < 0 ? (x) * (-1) : (x))

int gcd(int num1, int num2)
{
  num1 = ABS(num1);
  num2 = ABS(num2);
  if(num2 == 0) return num1;
  //as we switch num2 and num1 in next recursion no need to require num1 > num2
  return gcd(num2, num1 % num2);
}

int gcd_no_mod(int num1, int num2)
{
  num1 = ABS(num1);
  num2 = ABS(num2);
  if(num2 > num1) return gcd_no_mod(num2, num1);
  unsigned odd1 = num1 & 0x01;
  unsigned odd2 = num2 & 0x01;
  if(num2 == 0) return num1;
  if(!odd1 && !odd2) return gcd_no_mod(num1 >> 1, num2 >> 1) << 1;
  if(odd1 && odd2) return gcd_no_mod(num2, num1 - num2);
  return gcd_no_mod(num1 >> (odd1 ^ 0x01), num2 >> (odd2 ^ 0x01));
}

int char_to_int(char* string)
{
  if(string == NULL) {
    fprintf(stderr, "try converting empty pointer to integer\n");
    exit(1);
  }
  int flag = 1;
  int value = 0;

  if(*string == '-') {
    flag *= -1;
    string++;
  }
  while(*string != '\0') {
    if(*string >= '0' && *string <= '9') {
      value = value * 10 + *string - '0';
      string++;
    } else break;
  }

  return value * flag;
}

int main(int argc, char** argv)
{
  if(argc != 3) {
    fprintf(stderr, "not proper arguments, need two integers\n");
    exit(1);
  }

  int num1 = char_to_int(argv[1]);
  int num2 = char_to_int(argv[2]);
  printf("the gcd of %d and %d is %d\n", num1, num2, gcd(num1, num2));
  printf("the gcd of %d and %d is %d\n", num1, num2, gcd_no_mod(num1, num2));

  return 0;
}
