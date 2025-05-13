#include <stdio.h>
#include <conio.h>

int i, j;

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
	
	// To print the cartesian product here
	printf("The cartesian product of setA and setB is as follows : ");
	printf("{");
	
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++) {
			printf(" (%d, %d) ", setA[i], setB[j]);
		}
	}
	
	printf("}");
	
	return 0;
}
