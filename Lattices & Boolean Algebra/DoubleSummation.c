#include <stdio.h>
#include <math.h>

int main() {
	int n, m, i, j, sum = 0;

    printf("\n--- Double Summation ---\n");
    printf("Enter upper limit for i (n): ");
    scanf("%d", &n);
    printf("Enter upper limit for j (m): ");
    scanf("%d", &m);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            sum += i * j;
        }
    }

    printf("Result of double summation ?? (i * j): %d\n", sum);
    
	return 0;
}
