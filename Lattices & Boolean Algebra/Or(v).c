#include <stdio.h>
#include <conio.h>

int main() {
	int m, n;
	printf("Enter first number : ");
	scanf("%d", &m); // Input as : 5 (101)
	printf("Enter second number : ");
	scanf("%d", &n); // Input as : 6 (110)
	
	int ans = m | n; // Output as 5 | 6 = 7 (111)
	
	printf("\nThe answer is : %d\n", ans);
	return 0;
}
