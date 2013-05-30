#ifndef _LIB_H
#define _LIB_H 1
int char_to_integer(char* string)
{
  if(string == NULL) {
    fprintf(stderr, "attempt converting empty string\n");
    exit(1);
  }

  int flag = 1;
  int value = 0;
  if(*string == '-' || *string == '+') {
    flag = *string == '-' ? flag * (-1) : flag;
    string++;
  }

  while(*string != '\0' && *string >= '0' && *string <= '9') {
    value = value * 10 + *string - '0';
    string++;
  }

  return value * flag;
}

#endif
