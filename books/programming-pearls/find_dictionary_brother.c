#include <stdio.h>
#include <stdlib.h>

#define WORD "azbcde"

int main() {
  int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
                  73, 79, 83, 89, 97, 101};
  char* dictionary[] = {"azbced", "abcdefg", "xyzadf", "zabcde", "sdflsdasdfsdf", "edcbz", "edbcaz"};

  char* target = WORD;
  int prime_product = 1;
  while(*target) {
    prime_product *= primes[*(target++) - 'a'];
  }
  printf("%d\n", prime_product);
  int dic_length = sizeof(dictionary) / sizeof(char*);

  char* word;
  for(int i = 0; i < dic_length; i++) {
    word = dictionary[i];
    int product = prime_product;
    while(*word) {
      if(product % primes[*word - 'a'] == 0) {
        product /= primes[*(word++) - 'a'];
      } else {
        // printf("%s does not match, left prime %d", dictionary[i], product);
        break;
      }
    }
    if(!*word && product == 1) printf("%s\n", dictionary[i]);
  }
}
