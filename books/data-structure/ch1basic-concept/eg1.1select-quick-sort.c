//Below is some kinds of sorting algorithm


#include <stdio.h>
// macro makes code smaller
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int array[10] ={123, 43, 234, 12, 5, 65, 642, 23, 6643, 23};

/* let's declare some useful operations over array first*/
void swap(int* p1, int* p2) {
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

void printArray(int* array, int length) {
  for(int i = 0; i < length; ++i) {
    printf("%d ", *(array + i));
  }
  printf("\n");
}
/* then let's declare some sort method*/
void selectSort(int* array, int length);
void quickSort(int* array, int length);
int binSearch(int* array, int key, int length);

int main() {
  int length = sizeof(array) / sizeof(int);
  printf("this length of array is %d\n", length);
  printArray(array, length);
  //  selectSort(array, length);
  quickSort(array, length);
  printArray(array, length);
  printf("binary search for 12 is %d\n", binSearch(array, 12, 10));
}

void selectSort (int* array, int length) {
  //travel array n times
  //each time choose a min value of the rest un-sorted elements
  //swap the min value and the first un-sorted elements
  for(int index = 0; index < length; ++index) {
    int traveler = index;
    int min = traveler;
    int tmp;
    for(; traveler < length; ++traveler) {
      if(array[traveler] < array[min]) {
        min = traveler;
      }
    }
    //    swap(array + minPosition, array + index);
    // another way to swap is use macro
    SWAP(array[min], array[index], tmp);
  }
}

// the algorithm for quick sort
// use two pointers to record travel position and swap position
// when traveler reach the last element, which we choose as partition
// we swap the values which exchange pointer and partition pointer point
// then we divide array elements into two parts
// determine if these two parts still need partition
void partition(int* array, int head, int tail) {
  if(head >= tail) {
    return;
  }
  int traveler = head, exchange = head;
  for(; traveler < tail; ++traveler) {
    if(array[traveler] < array[tail]) {
      swap(array + exchange++, array + traveler);
    }
  }
  swap(array + exchange, array + tail);
  partition(array, head, exchange - 1);
  partition(array, exchange + 1, tail);
}

void quickSort(int* array, int length) {
  partition(array, 0, length - 1);
}


int binSearch(int* array, int key, int length) {
  int head = 0, tail = length -1;
  while(head <= tail) {
    int mid = (head + tail) / 2;
    if(array[mid] == key) return mid;
    if(array[mid] < key) head = mid + 1;
    else tail = mid - 1;
  }
  return -1;
}
