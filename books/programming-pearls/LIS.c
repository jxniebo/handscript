#include <stdio.h>
#include <stdlib.h>








//find longest common sequece
void find_lcs(int* source_array, int* target_array, int* result_array) {
  if()

}



//create an array which contains from min to max
//so transform problem from las to lcs
int fill_dummy_array(int* array, int max, int min) {
  int len = max - min + 1;
  for(int i = 0; i < len; i++) {
    array[i] = min + i;
  }
}


int main() {
  int* source_array {3, 32, 21, 1, 4, 12, 23, 26, 2, 6, 4, 5, 8, 21, 4, 12, 12, 56};

  int max array[0], min = array[0];
  int* dummy_array, result_array;
  for(int i = 0; i < 17; i++) {
    if(array[i] > max)
      max = array[i];
    else if(array[i] < min)
      min = array[i];
  }
  dummy_array = (int*)malloc(sizeof(int)*(max-min-1));
  result_array = (int*)malloc(sizeof(int)*(max-min-1));
  fill_dummy_array(dummy_array, max, min);

  int num = find_lcs(source_array, dummy_array, result_array);

  return 0;
}
