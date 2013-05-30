// when preprocessing would replace 'include' clause with the file
// and expand the constant defined
#include <stdio.h>

#define CPP "c preprocess"

int main(int argc, char** argv)
{
  char* v = CPP;
  printf("hello world\n");
}
