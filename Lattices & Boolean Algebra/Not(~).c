#include <stdio.h>
#include <conio.h>

int main() {
	int m, n;
	printf("Enter first number : ");
	scanf("%d", &m); // Input as : 5 (101)
	
	int ans = ~m; // Output as ~5 = -6
	
	printf("\nThe answer is : %d\n", ans);
	return 0;
}
