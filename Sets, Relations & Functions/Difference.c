#include <stdio.h>
#include <conio.h>
#include <stdbool.h>

bool existsInArray(int superSet[], int num, int sizeOfSuperSet)
{
  int i;
  for (i = 0; i < sizeOfSuperSet; i++)
  {
    if (superSet[i] == num)
    {
      return true;
    }
  }
  return false;
}


void checkDifferenceSet(int setA[], int setB[], int sizeOfSetA, int sizeOfSetB) {
	int differenceSet[sizeOfSetA];
	int count = 0, i, j;


	for(i=0; i<sizeOfSetA; i++) {
		if(!(existsInArray(setB, setA[i], sizeOfSetB))) {
			differenceSet[count++] = setA[i];
		}
	}

	printf("The difference set A-B is as below : \n");
	for(i=0; i<count; i++) {
		printf(" %d ", differenceSet[i]);
	}


}


int main() {
	int m, n, i, j;
	printf("Enter the number of elements for setA (SuperSet whose difference will be extracted ) : ");
	scanf("%d", &m);

	int setA[m];

	printf("Enter %d elements for setA (SuperSet) : ", m);
	for(i=0; i<m; i++) {
		scanf("%d", &setA[i]);
	}

	printf("Enter the number of elements for setB (subSet to check the difference) : ");
	scanf("%d", &n);

	int setB[n];

	printf("Enter %d elements for setB (subSet) : ", n);
	for(i=0; i<n; i++) {
		scanf("%d", &setB[i]);
	}

	checkDifferenceSet(setA, setB, m, n);
	return 0;
}
