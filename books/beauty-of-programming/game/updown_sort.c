#include <stdio.h>
#include <stdlib.h>


#define SWAP(x, y) do{int tmp = *(x); *(x) = *(y); *(y) = tmp;} while(0)

//upside down the array from index 0 to index bottom
void updown(int* array, int bottom)
{
  int mid = bottom / 2;
  for(int i = 0; i <= mid; i++) {
    SWAP(array + i, array + bottom - i);
  }
}

//sort an array by upside down part of it several times
//input would be an array and its length
//no return values as it would sort by SWAP
void updown_sort_upbottom(int* array, int length)
{
  for(int i = 1; i < length; i++) {
    int key = array[i];
    if(key >= array[i - 1]) {
      //key at right position
      continue;
    } else if(key < array[0]) {
      //key should be first
      updown(array, i - 1);
      updown(array, i);
    } else {
      //key should be inserted into those sorted elements
      int from = 0, to = i - 1, pos;
      while(from <= to) {
        pos = from + (to - from) / 2;
        if(array[pos] > key && array[pos - 1] <= key) {
          break;
        } else if(array[pos] > key) {
          to = pos - 1;
        } else from = pos + 1;
      }

      updown(array, i);
      updown(array, i - pos);
      updown(array, i - pos - 1);
      updown(array, i);
    }
  }
}


void updown_sort_bottomup(int* array, int length)
{
  for(int i = length - 1; i >= 1; i--) {
    int max = 0;
    for(int j = 1; j <= i; j++) {
      if(array[j] > array[max]) {
        max = j;
      }
    }
    updown(array, max);
    updown(array, i);
  }
}






#define LEN 10
int arrayub[LEN] = {2, 3, 5, 32, 23, 1, 3, 9, 5};
int arraybu[LEN] = {2, 3, 5, 32, 23, 1, 3, 9, 5};

void array_print(int* array, int len) {
  printf("print array:\n");
  for(int i = 0; i < len; i++) {
    printf("%d ", array[i]);
    if((i + 1) % 10 == 0) printf("\n");
  }
  printf("\n");
}

int main(int argv, char** argc) {

  FILE* file = NULL;
  
  updown_sort_bottomup(arraybu, LEN);
  array_print(array, LEN);
  return 0;
}
