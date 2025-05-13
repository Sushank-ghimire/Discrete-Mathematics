#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include "helpers.h"

int i, j;

void printIntersection(int setA[], int setB[], int sizeOfA, int sizeOfB) {
	int intersection[sizeOfA+sizeOfB];
	
	int count = 0;
	
	for(i=0; i<sizeOfA; i++) {
		for(j=0; j<sizeOfB; j++) {
			if(setA[i] == setB[j] && !existsInArray(intersection, setA[i], count)) {
				intersection[count++] = setA[i];
				break;
			}
		}
	}
	
	// Printing the intersection set
	printf("The InterSeciton set of setA and setB is as follows : \n");
	printf("{ ");
	for(j=0; j<count; j++) {
		printf(" %d ,", intersection[j]);
	}
	printf(" }");
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

	printIntersection(setA, setB, m, n);

	return 0;
}

