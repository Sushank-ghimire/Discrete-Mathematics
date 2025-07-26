// Programs to test validity of arguments by using truth tables.
#include <stdio.h>

// Implication function: a ? b is false only when a is 1 and b is 0
int implies(int a, int b) {
    return (!a || b);
}

int main() {
    int P, Q;
    int allTrue = 1;

    printf("Truth Table for ((P -> Q) ^ P) -> Q\n");
    printf("P | Q | P->Q | (P->Q)^P (Final) | Final -> Q | Result\n");
    printf("------------------------------------------\n");

    for (P = 0; P <= 1; P++) {
        for (Q = 0; Q <= 1; Q++) {
            int p_implies_q = implies(P, Q);
            int conj = p_implies_q && P;
            int final_result = implies(conj, Q);

            printf(" %d | %d |  %d  |    %d             |     %d     | %s\n",
                   P, Q, p_implies_q, conj, final_result,
                   final_result ? "True" : "False");

            if (!final_result)
                allTrue = 0;
        }
    }

    if (allTrue)
        printf("\nThe argument is VALID.\n");
    else
        printf("\nThe argument is INVALID.\n");

    return 0;
}

