#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int factorial(int n) {
    int fact = 1, i;
    for(i = 2; i <= n; i++)
        fact *= i;
    return fact;
}

int nPr(int n, int r) {
    return factorial(n) / factorial(n - r);
}

int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

// Generate permutations using backtracking
void permute(char *str, int l, int r) {
	int i;
    if (l == r)
        printf("%s\n", str);
    else {
        for (i = l; i <= r; i++) {
            swap((str + l), (str + i));
            permute(str, l + 1, r);
            swap((str + l), (str + i)); // backtrack
        }
    }
}

// Generate combinations of r characters from the string
void combineUtil(char *str, char *data, int start, int end, int index, int r) {
    if (index == r) {
        data[r] = '\0';
        printf("%s\n", data);
        return;
    }
    int i;

    for ( i = start; i <= end && end - i + 1 >= r - index; i++) {
        data[index] = str[i];
        combineUtil(str, data, i + 1, end, index + 1, r);
    }
}

void generateCombinations(char *str, int r) {
    int n = strlen(str);
    char *data = (char *)malloc((r + 1) * sizeof(char));
    combineUtil(str, data, 0, n - 1, 0, r);
    free(data);
}

int main() {
    int choice, n, r;
    char str[100];

    while (1) {
        printf("\n===== Menu =====\n");
        printf("1. Calculate nPr (Permutation)\n");
        printf("2. Calculate nCr (Combination)\n");
        printf("3. Generate all permutations of a string\n");
        printf("4. Generate combinations from a string\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter n and r: ");
                scanf("%d %d", &n, &r);
                if (n >= r)
                    printf("nPr = %d\n", nPr(n, r));
                else
                    printf("Invalid input: n should be >= r\n");
                break;

            case 2:
                printf("Enter n and r: ");
                scanf("%d %d", &n, &r);
                if (n >= r)
                    printf("nCr = %d\n", nCr(n, r));
                else
                    printf("Invalid input: n should be >= r\n");
                break;

            case 3:
                printf("Enter the string: ");
                scanf("%s", str);
                printf("Permutations are:\n");
                permute(str, 0, strlen(str) - 1);
                break;

            case 4:
                printf("Enter the string: ");
                scanf("%s", str);
                printf("Enter r: ");
                scanf("%d", &r);
                printf("Combinations are:\n");
                generateCombinations(str, r);
                break;

            case 5:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

