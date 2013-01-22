#include <cstdlib>

#include "util.h"
#include "sortAlgorithm.h"


int externalTest = 123;

void bubbleSort(int* array, int length) {
	for(int i = 0; i < length; ++i) {
		for(int j = 0; j < length - i - 1; ++j) {
			if(array[j] > array[j + 1])
				swap(array, j, j + 1);	
		}
	}
}

void selectSort(int* array, int length) {
	for(int i = 1; i < length; ++i) {
		int max = 0;

		for(int j = 0; j <= length - i; ++j)
			max = array[j] >= array[max] ? j : max; 	

		swap(array, max, length - i);
	}
}

void quickSort(int* array, int head, int tail) {
	if(tail > head) {
		int splitPoint = head;
		int travelPoint = head;

		while(travelPoint < tail) {
			if(array[travelPoint] <= array[tail]) {
				swap(array, splitPoint++, travelPoint);
			}
			++travelPoint;
		}

		swap(array, splitPoint, tail);
		quickSort(array, head, splitPoint - 1);
		quickSort(array, splitPoint + 1, tail);
	}
}

void quickSortB(int* array, int head, int tail) {
	if(tail > head) {
		int leftPoint = head;
		int rightPoint = tail;

		while(leftPoint != rightPoint) {
			if(array[leftPoint] <= array[tail]) {
				++leftPoint;
			} else if(array[rightPoint] > array[tail]) {
				--rightPoint;
			} else { swap(array, leftPoint, rightPoint); }
		}
		
		swap(array, leftPoint, tail);	
		quickSortB(array, head, leftPoint - 1);
		quickSortB(array, leftPoint + 1, tail);
	}
} 

void mergeSort(int* array, int head, int tail) {
	if(tail - head <= 0) return;

	int middle = (tail - head) / 2 + head;
	mergeSort(array, head, middle);
	mergeSort(array, middle + 1, tail);
	
	int length1 = middle - head + 1;
	int length2 = tail - middle;
	int* clone1 = array_clone(array + head, length1);
	int* clone2 = array_clone(array + middle + 1, length2);
	int i = 0, j = 0;

	while(i < length1 && j < length2)
		array[head++] = clone2[j] < clone1[i] ? clone2[j++] : clone1[i++];
	while(i < length1) array[head++] = clone1[i++];
	while(j < length2) array[head++] = clone2[j++];

	free(clone1);
	free(clone2);
}

void insertSort(int* array, int length) {
	for(int i = 0; i < length; i++) {
		int value = array[i];
		int j = i;

		while(j-- > 0) {
			if(array[j] > value) {
				array[j + 1] = array[j];	
			} else break;
		}
			
		array[j + 1] = value; 
	}
}
