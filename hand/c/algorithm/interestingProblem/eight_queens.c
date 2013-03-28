#include <stdio.h>
#include <stdlib.h>

#define INDEX 8
typedef struct pos{
  int line;
  int col;
}POS;
void panel_print();
void locate_queen_by_line(int line_num);
int amount = 0;
int panel[INDEX][INDEX];

int main() {
  locate_queen_by_line(0);
  return 0;
}

void panel_print() {
  printf("\n find possible location NO. %d\n", amount);
  /* for(int i = 0; i < INDEX; i++) { */
  /*   for(int j = 0; j < INDEX; j++) { */
  /*     printf("%d ", panel[i][j]); */
  /*   } */
  /*   printf("\n"); */
  /* } */
}



int pos[INDEX];

int no_collision(int line, int col) {
  for(int i = 0; i < line; i++) {
    if(pos[i] == col || abs(pos[i] - col) == line - i)
      return 0;
  }
  return 1;
}
//should find all the possible location for eight queens
//when i found one position, print panel
//define this function to find the location in line line number
//need an array to store the location of queens
//need a procedure to determine if location is collision with previous queens



void locate_queen_by_line(int line_num) {
  for(int col = 0; col < INDEX; col++) {
    if(no_collision(line_num, col)) {
      pos[line_num] = col;
      if(line_num == INDEX - 1) {
        for(int i = 0; i < INDEX; i++) {
          for(int j = 0; j < INDEX; j++) {
            panel[i][j] = pos[i] == j ? 1 : 0;
          }
        }
        amount++;
                panel_print();
        break;
      } else {
        locate_queen_by_line(line_num + 1);
      }
    }
  }
  return;
}
