#include <malloc.h>
#include <iostream>

#include "./headers/sortAlgorithm.h"
#include "./headers/util.h"

enum SortAlgorithmType {SORT_BUBBLE, SORT_SELECT, SORT_QUICK, SORT_MERGE, SORT_INSERT};


void algorithmSelector(int index, int* array, int length) {
	switch(index) {
		case SORT_BUBBLE:
			bubbleSort(array, length);
			break;
		case SORT_SELECT:
			selectSort(array, length);
			break;
		case SORT_QUICK:
			quickSortB(array, 0, length - 1);
			break;
		case SORT_MERGE:
			mergeSort(array, 0, length - 1);
			break;
		case SORT_INSERT:
			insertSort(array, length);	
			break;
		default:
			break; 	
	}
}

int main() {
	int* arrayWaitSort = (int*)malloc(120 * sizeof(int));	
	int length = 120;
	array_random_fill(arrayWaitSort, length);

	int* arrayClone = array_clone(arrayWaitSort, length);
	std::cout << "Below is merge sort" << std::endl;
	array_print(arrayClone, length);	
	algorithmSelector(SORT_MERGE, arrayClone, length); 
	array_print(arrayClone, length);
	free(arrayClone);
	

	arrayClone = array_clone(arrayWaitSort, length);
	std::cout << "Below is insert sort B" << std::endl;
	array_print(arrayClone, length);	
	algorithmSelector(SORT_INSERT, arrayClone, length); 
	array_print(arrayClone, length);
	free(arrayClone);

	return 0;
} 
