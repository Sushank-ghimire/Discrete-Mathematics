#include <stdio.h>
#include <conio.h>
#include <stdbool.h>


void bubbleSort(int size, int array[size], bool isAscending) {
	int i, j;
	for(i=0; i<size-1; i++) {
		for(j=i+1; j<size; j++) {
			if(isAscending) {
				if(array[i] > array[j]) {
					int temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			} else {
				if(array[i] < array[j]) {
					int temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}
	}
}


void printArray(int size, int array[size]) {
	int i, j;
	for(i=0; i<size; i++) {
		printf(" %d ", array[i]);
	}
}

int main() {
	int size, i;
	printf("Enter the size of the array : ");
	scanf("%d", &size);
	
	int array[size];
	
	printf("Enter %d elements of the array : ", size);
	for(i=0; i<size; i++) {
		scanf("%d", &array[i]);
	}
	
	bubbleSort(size, array, true);
	
	printf("Array in ascending order is : \n");
	printArray(size, array);
	
	printf("\nArray in descending order is : \n");
	bubbleSort(size, array, false);
	printArray(size, array);
	return 0;
}
