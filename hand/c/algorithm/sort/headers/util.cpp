#include <iostream>

#include <stdio.h>
#include <stdlib.h>

#include "util.h"

using namespace std;

void swap(int* array, int i, int j) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void array_print(int* array, int length) {
	for(int i = 0; i < length; i++)
		cout << (i % 8 == 0 ? "\n" : "\t") << array[i];
	cout << endl << "-------------------------------------" << endl;
}

int* array_clone(int* array, int length) {
	int* clone = (int*)malloc(length * sizeof(int));

	if(!clone) {
		cout << "allocate memory fail"  << endl;
	} else {
		while(--length >= 0)
			clone[length] = array[length];
	}

	return clone;
}

void array_random_fill(int* array, int length) {
	while(--length >= 0)
		array[length] = rand() % 1000;
}
