#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

bool existsInArray(int superSet[], int num, int sizeOfSuperSet) {
	int i;
	for(i=0; i<sizeOfSuperSet; i++) {
		if(superSet[i] == num) {
			return true;
		}
	}
	return false;
}


void checkSubset(int superSet[], int subSet[], int sizeOfSuperSet, int sizeOfSubSet) {
	int i, j;
	for(j=0; j<sizeOfSubSet; j++) {
		if(!(existsInArray(superSet, subSet[j], sizeOfSuperSet))) {
			printf("\nThe setB is not the subSet of setA (superSet) \n");
			exit(0);
		}
	}
	printf("\nThe setB is the subSet of setA (superSet)");
}

int main() {
	int m, n, i, j;
	printf("Enter the number of elements for setA (SuperSet) : ");
	scanf("%d", &m);

	int setA[m];

	printf("Enter %d elements for setA (SuperSet) : ", m);
	for(i=0; i<m; i++) {
		scanf("%d", &setA[i]);
	}

	printf("Enter the number of elements for setB (subSet) : ");
	scanf("%d", &n);

	int setB[n];

	printf("Enter %d elements for setB (subSet) : ", n);
	for(i=0; i<n; i++) {
		scanf("%d", &setB[i]);
	}
	
	checkSubset(setA, setB, m, n);

	return 0;
}
