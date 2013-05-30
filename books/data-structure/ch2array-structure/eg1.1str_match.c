#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pmatch(char* s, char* p, int* f);
int main(int argc, char** argv) {
  char* s = "finsdinafsddflfindfasdffindfifindfindfisdficnfialfindfinabcfcsdfisasadllsdashdsjfltern\n";
  char* p;
  printf("%s", s);

  if(argc > 1) p = argv[1];
  else p = "find";
  printf("%s\n", p);
  //findfinabc
  int failure[] = {0, 0, 0, 0, 0, 0, 3, 0, 0};
  int location;
  if((location = pmatch(s, p, failure)) >= 0)
    printf("pattern has been located as %s", s + location);
  else printf("failure in matching patter\n");
}

int pmatch(char* s, char* p, int* f) {
  int location;
  int i = 0;
  int j = 0;
  while(i < strlen(s) && j < strlen(p)) {
    if(*(s + i) == *(p + j)) {
      i++;
      j++;
    } else if(j > 0) {
      j = f[j - 1];
    } else i++;
  }
  location = (j == strlen(p)) ? i - strlen(p) : -1;
  return location;
}
