#include <stdio.h>
#include <math.h>

int main() {
	
	int a, r, n, i, term;
    int sum = 0;

    printf("\n--- Geometric Progression ---\n");
    printf("Enter first term (a): ");
    scanf("%d", &a);
    printf("Enter common ratio (r): ");
    scanf("%d", &r);
    printf("Enter number of terms (n): ");
    scanf("%d", &n);

    printf("GP Terms: ");
    for (i = 0; i < n; i++) {
        term = a * pow(r, i);
        printf("%d ", term);
        sum += term;
    }
    printf("\nSum of GP: %d\n", sum);
	
	return 0;
}
