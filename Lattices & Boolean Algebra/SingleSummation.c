#include <stdio.h>
#include <math.h>

int main() {
	int n, i, sum = 0;
    int choice;

    printf("\n--- Single Summation ---\n");
    printf("Enter upper limit n: ");
    scanf("%d", &n);

    printf("Choose function:\n");
    printf("1. i (linear)\n");
    printf("2. i^2 (square)\n");
    printf("3. 2^i (exponential)\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    for (i = 1; i <= n; i++) {
        if (choice == 1)
            sum += i;
        else if (choice == 2)
            sum += i * i;
        else if (choice == 3)
            sum += pow(2, i);
        else {
            printf("Invalid choice\n");
            return;
        }
    }

    printf("Result of summation: %d\n", sum);
	
	return 0;
}
