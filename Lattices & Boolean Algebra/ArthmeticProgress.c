#include <stdio.h>
#include <math.h>

int main() {
	
	int a, d, n, i, term;
    int sum = 0;

    printf("\n--- Arithmetic Progression ---\n");
    printf("Enter first term (a): ");
    scanf("%d", &a);
    printf("Enter common difference (d): ");
    scanf("%d", &d);
    printf("Enter number of terms (n): ");
    scanf("%d", &n);

    printf("AP Terms: ");
    for (i = 0; i < n; i++) {
        term = a + i * d;
        printf("%d ", term);
        sum += term;
    }
    printf("\nSum of AP: %d\n", sum);
    
    return 0;
}
