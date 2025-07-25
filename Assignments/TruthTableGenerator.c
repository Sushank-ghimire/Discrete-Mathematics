// Programs to generate truth tables of compound propositions.

#include <stdio.h>
#include <conio.h>

// Define truth values for implication and biconditional
int implies(int a, int b) {
    return (!a || b);
}

int biconditional(int a, int b) {
    return (a == b);
}

int main() {
	int P, Q;

    printf("Truth Table for (P ^ Q) -> P\n");
    printf(" P | Q | P^Q | (P^Q)->P\n");
    printf("--------------------------\n");
    
    
    for (P = 0; P <= 1; P++) {
        for (Q = 0; Q <= 1; Q++) {
            int and_result = P && Q;
            int final_result = implies(and_result, P);

            printf(" %d | %d |  %d  |    %d\n", P, Q, and_result, final_result);
        }
    }
    
//	getch();
	return 0;
}
