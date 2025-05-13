#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include "helpers.h"

int i;

int printUnion(int setA[], int setB[], int sizeOfA, int sizeOfB) {
	int unionSet[sizeOfA+sizeOfB];
	int count = 0;

	// Adding only unique elements of setA to the unionSet
	for(i=0; i<sizeOfA; i++) {
    if (!existsInArray(unionSet, setA[i], count))
    {
      unionSet[count++] = setA[i];
    }
  }

	// Adding only unique elements of setB to the unionSet
	for(i=0; i<sizeOfB; i++) {
    if (!existsInArray(unionSet, setB[i], count))
    {
      unionSet[count++] = setB[i];
    }
  }

	// Printing the Unions of the setA & setB
	printf("\nThe union of the setA and setB is given as : \n");
	for(i=0; i<count; i++) {
		printf(" %d ", unionSet[i]);
	}
}

int main() {
	int m, n;
	printf("Enter the number of elements for setA : ");
	scanf("%d", &m);

	int setA[m];

	printf("Enter %d elements for setA : ", m);
	for(i=0; i<m; i++) {
		scanf("%d", &setA[i]);
	}

	printf("Enter the number of elements for setB : ");
	scanf("%d", &n);

	int setB[n];

	printf("Enter %d elements for setB : ", n);
	for(i=0; i<n; i++) {
		scanf("%d", &setB[i]);
	}

	printUnion(setA, setB, m, n);
	return 0;

}
