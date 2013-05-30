#include <stdio.h>
#include <stdlib.h>

#define INDEX 9

typedef struct pos {
  int row;
  int col;
} POS;


int cube[INDEX][INDEX] = {0};
void cube_print() {
  for(int i = 0; i < INDEX; i++) {
    for(int j = 0; j < INDEX; j++) {
      printf("%d\t", cube[i][j]);
    }
    printf("\n");
  }
}

int main() {
  cube[3][3] = 9;
  cube[3][4] = 8;
  cube_print();
  void fill_cube_iterate();
  int fill_cube();
  //  fill_cube();
  fill_cube_iterate();
  printf("over\n");
  cube_print();

  return 0;
}

void choose_blank(POS* pos) {
  int i, j;
  for(i = 0; i < INDEX; i++) {
    for(j = 0; j < INDEX; j++) {
      if(cube[i][j] == 0) {
        break;
      }
    }
    if(j < INDEX) {
      break;
    }
  }
  pos->row = i;
  pos->col = j;
}

int can_try(const POS* pos, const int value) {
  int row = pos->row;
  for(int i = 0; i < INDEX; i++) {
    if(cube[row][i] == value)
      return 0;
  }
  int col = pos->col;
  for(int j = 0; j < INDEX; j++) {
    if(cube[j][col] == value)
      return 0;
  }

  int cube_row = row / 3 * 3;
  int cube_col = col / 3 * 3;
  for(int i = cube_row; i < cube_row + 3; i++) {
    for(int j = cube_col; j < cube_col + 3; j++) {
      if(cube[i][j] == value)
        return 0;
    }
  }
  return 1;
}

typedef struct pos_stack {
  int row;
  int col;
  struct pos_stack* prev;
}STACK;

STACK* stack;
int is_stack_empty() {
  return stack->prev == NULL;
}

void stack_push(POS* pos) {
  STACK* prev = stack;
  stack = (STACK*)malloc(sizeof(STACK));
  stack->row = pos->row;
  stack->col = pos->col;
  stack->prev = prev;
}
STACK* stack_pop() {
  STACK* item = stack;
  stack = stack->prev;
  return item;
}
void stack_initial() {
  while(stack) {
    STACK* prev = stack->prev;
    free(stack);
    stack = prev;
  }
  stack = (STACK*)malloc(sizeof(STACK));
  stack->prev = NULL;
}
void fill_cube_iterate() {
  stack_initial();
  POS* pos = (POS*)malloc(sizeof(POS));
  pos->row = 0;
  pos->col = 0;
  //if position in range, continue
  //for each position, if can try value,
  //then push the position in stack, change the cube value, continue
  //if no value can try, pop position back, rest cube value
  int value = 1;
  while(pos->row < INDEX && pos->col < INDEX) {
    for(; value <= INDEX; value++) {
      if(can_try(pos, value)) {
        stack_push(pos);
        cube[pos->row][pos->col] = value;
        choose_blank(pos);
        value = 1;
        break;
      }
    }
    if(value == INDEX + 1) {
      STACK* item = stack_pop();
      pos->row = item->row;
      pos->col = item->col;
      free(item);
      value = cube[pos->row][pos->col] + 1;
      cube[pos->row][pos->col] = 0;
    }

  }
}

//if cube has been filled, return 1;
//if cube cannot be filled anymore, return 0;
//Given choose_blank
//Given can_try
int fill_cube() {
  POS* pos = (POS*)malloc(sizeof(POS));
  choose_blank(pos);
  if(pos->row == INDEX) {
    free(pos);
    return 1;
  }
  for(int value = 1; value < INDEX + 1; value++) {
    if(can_try(pos, value)) {
      cube[pos->row][pos->col] = value;
      if(fill_cube()) {
        free(pos);
        return 1;
      } else {
        cube[pos->row][pos->col] = 0;
      }
    }
  }
  free(pos);
  return 0;
}
