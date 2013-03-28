#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) ((x) > (y) ? (x) : (y))
typedef struct {
  int start;
  int end;
  long sum;
}SUB_SUM;

// would need one struct to store temporary max sum
// and another to store sum of currently traveled sum
// if current sum is blow 0, believe this item would not be included in max subarray
int find_max_subsum(int* array, int length) {
  int max_sum = *array, current_sum = 0;
  int* travel = array;
  for(int* travel = array; travel < array + length; travel++) {
    current_sum = current_sum < 0? *travel : *travel + current_sum;
    max_sum = MAX(max_sum, current_sum);
  }
  return max_sum;
  /*
  SUB_SUM already = {0, 0, *array}, current = {0, 0, 0};
  while(current.end < length) {
    current.sum = current.sum + *(array + current.end);
    if(current.sum > already.sum) {
      already = current;
    }
    current.end++;
    if(current.sum <= 0) {
      current.start = current.end;
      current.sum = 0;
    }
  }
  return already;*/
}



int main() {
  int array[10] = {-1, -2, -3, -3, -5, -4, -2, -3, -1, -2};
  int result = find_max_subsum(array, 10);
  printf("the subarray with max sum is %d:\n", result);
  /*  for(int i = result.start; i <= result.end; i++) {
    printf("%d ", array[i]);
  }
  printf("\nAnd the max sum is %ld\n", result.sum);
  */
  return 0;
}
