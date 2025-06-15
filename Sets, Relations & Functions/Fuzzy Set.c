// Fuzzy sets operation implementations
#include <stdio.h>
#include <conio.h>

void getArrayInput(int size, float arr[size]) {
	int i, count = 0;
	float num;
	do {
		printf("Enter value for [%d] place : ", count);
		scanf("%f", &num);
		if(num >= 0 && num <= 1) {
			arr[count++] = num;
		} else {
			printf("Fuzzy set must contains the value between 0 and 1.\n");
		}
	} while(count != size);
}

void printArray(int size, float arr[size]) {
	int i;
	for(i=0; i<size; i++) {
		printf(" %.2f ", arr[i]);
	}
}

void Intersection(int s1, float arr1[s1], float arr2[s1]) {
	float intersection[s1];
	int i, count = 0;
	for(i=0; i<s1; i++) {
		// min between two arrays
		intersection[i] = (arr1[i] < arr2[i]) ? arr1[i] : arr2[i];
	}
	printf("\nThe intersection of the elements of fuzzy sets are : \n");
	printArray(s1, intersection);
	printf("\n");
}

void Union(int s1, float arr1[s1], float arr2[s1]) {
	float union_array[s1];
	int i, count = 0;
	for(i=0; i<s1; i++) {
		// max between two arrays
		union_array[i] = (arr1[i] > arr2[i]) ? arr1[i] : arr2[i];
	}
	printf("\nThe union of the elements of fuzzy sets are : \n");
	printArray(s1, union_array);
	printf("\n");
}


void Complement(int s1, float arr1[s1], float arr2[s1]) {
    float complement1[s1], complement2[s1];
    int i;

    for (i = 0; i < s1; i++) {
        complement1[i] = 1.0 - arr1[i];
    }

    for (i = 0; i < s1; i++) {
        complement2[i] = 1.0 - arr2[i];
    }

    printf("\nThe complement of fuzzy set 1 is:\n");
    printArray(s1, complement1);

    printf("\nThe complement of fuzzy set 2 is:\n");
    printArray(s1, complement2);
    
    printf("\n");
}

void Difference(int s1, float arr1[s1], float arr2[s1]) {
	float difference[s1];
	int i;
    for (i = 0; i < s1; i++) {
        float comp_b = 1.0 - arr2[i];
        difference[i] = (arr1[i] < comp_b) ? arr1[i] : comp_b;
    }
    printf("\nThe difference (A - B) of the fuzzy sets is : \n");
    printArray(s1, difference);
    printf("\n");
}


int main() {
	int s1, choice;
	printf("Enter the size of the sets : ");
	scanf("%d", &s1);
	float arr1[s1];
	printf("\nEnter the elements for the first array : \n");
	getArrayInput(s1, arr1);
	
	float arr2[s1];
	printf("\nEnter the elements for the second array : \n");
	getArrayInput(s1, arr2);
	
	do {
		printf("\nEnter your choice for fuzzy set operations : \n");
		printf("\t 1. Intersection\n");
		printf("\t 2. Union\n");
		printf("\t 3. Complement\n");
		printf("\t 4. Difference\n");
		printf("\t 5. Exit\n");
		
		scanf("%d", &choice);
		switch(choice) {
			case 1:
				Intersection(s1, arr1, arr2);
				break;
			case 2:
				Union(s1, arr1, arr2);
				break;
			case 3:
				Complement(s1, arr1, arr2);
				break;
			case 4:
				Difference(s1, arr1, arr2);
				break;
			case 5:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice.\n");
		}
		
	} while (choice != 5);
	
	return 0;
}
