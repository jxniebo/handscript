#include <stdio.h>
#include <stdlib.h>


struct {
  unsigned char a:4;
  unsigned char b:4;

}i;





#define FULLMASK 255
#define LMASK (FULLMASK << 4)
#define RMASK (FULLMASK >> 4)
#define LSET(bits, n) (bits = bits & RMASK | (n << 4))
#define RSET(bits, n) (bits = bits & LMASK | n)
#define LGET(bits) (bits >> 4)
#define RGET(bits) (bits & RMASK)


int main() {
  i.a = 15;

  unsigned char bits = 0;
  for(LSET(bits, 0); LGET(bits) < 9; LSET(bits, (LGET(bits) + 1))) {
    for(RSET(bits, 0); RGET(bits) < 9; RSET(bits, (RGET(bits) + 1))) {
      if(RGET(bits) % 3 != LGET(bits) % 3)
        printf("A: %d, B: %d\n", LGET(bits), RGET(bits));
    }
  }
}
