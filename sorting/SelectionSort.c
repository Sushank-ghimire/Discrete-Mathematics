#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include "helpers.c"


void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}


void selectionSort(int size, int array[size], bool isAscending) {
	int i, j;
	for(i=0; i<size-1; i++) {
		int min_index = i;
		for(j=i+1; j<size; j++) {
			if(isAscending) {
				if(array[j] < array[min_index]) {
					min_index = j;
				}
			} else {
				if(array[j] > array[min_index]) {
					min_index = j;
				}
			}
		}
		swap(&array[min_index], &array[i]);
	}
}


int main() {
	
	int size, i;
	printf("Enter the size of the array : ");
	scanf("%d", &size);
	
	int array[size];
	
	printf("Enter %d elements of the array : ", size);
	getArray(size, array);
	
	selectionSort(size, array, true);
	printf("The sorting in ascending order is : \n");
	printArray(size, array);
	
	
	selectionSort(size, array, false);
	printf("\nThe sorting in descending order is : \n");
	printArray(size, array);
	return 0;
}
