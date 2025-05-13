#include <stdio.h>
#include "helpers.h"
#include <conio.h>
#include <stdbool.h>

int i, j;

void findComplement(int universalSet[], int set[], int sizeOfU, int sizeOfSet) {
    int complementSet[sizeOfU];
	int track = 0;
	
	for(i=0; i<sizeOfU; i++) {
		for(j=0; j<sizeOfSet; j++) {
			if (!existsInArray(set, universalSet[i], sizeOfSet)) {
				complementSet[track++] = universalSet[i];
				break;
			}
		}
	}

    printf("The complement set of the given set is: \n{ ");
    printArray(complementSet, track);
    printf(" }\n");
}



int main() {
	int m, n;

	printf("Enter the number of elements of universal set : ");
	scanf("%d", &m);
	int universalSet[m];

	printf("Enter %d elements of Universal set U : ", m);
	for(i=0; i<m; i++) {
		scanf("%d", &universalSet[i]);
	}

	printf("Enter the number of elements of setA : ");
	scanf("%d", &n);
	int setA[n];

	printf("Enter %d elements of setA : ", n);
	for(i=0; i<n; i++) {
		scanf("%d", &setA[i]);
	}

	findComplement(universalSet, setA, m, n);
	return 0;
}
