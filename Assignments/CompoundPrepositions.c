#include <stdio.h>

// Implication: P ? Q
int implies(int p, int q) {
    return (!p || q);
}

// Biconditional: P ? Q
int biconditional(int p, int q) {
    return (p == q);
}

int main() {
    int choice;
    int P, Q;

    do {
    	printf("Choose a compound proposition:\n");
    	printf("1. negation P\n");
    	printf("2. P ^ Q\n");
    	printf("3. P v Q\n");
    	printf("4. P -> Q\n");
    	printf("5. P <--> Q\n");
    	printf("6. Exit\n");
    	printf("Enter your choice : ");
    	scanf("%d", &choice);
    	switch(choice) {
    	case 1:
    		printf("P | negation P\n");
        	printf("--------\n");
        	for (P = 1; P >= 0; P--) {
            	printf("%d |  %d\n", P, !P);
        	}
        	printf("\n");
        	break;
        case 2:
        	printf("P | Q | P ^ Q\n");
        	printf("-------------\n");
        	for (P = 1; P >= 0; P--) {
            	for (Q = 1; Q >= 0; Q--) {
                	printf("%d | %d |  %d\n", P, Q, P && Q);
            	}
        	}
        	printf("\n");
        	break;
        case 3:
        	printf("P | Q | P v Q\n");
        	printf("-------------\n");
        	for (P = 1; P >= 0; P--) {
            	for (Q = 1; Q >= 0; Q--) {
                	printf("%d | %d |  %d\n", P, Q, P || Q);
            	}
        	}
        	printf("\n");
        	break;
        case 4:
        	printf("P | Q | P ->Q\n");
        	printf("-------------\n");
        	for (P = 1; P >= 0; P--) {
            	for (Q = 1; Q >= 0; Q--) {
                	printf("%d | %d |  %d\n", P, Q, implies(P, Q));
            	}
        	}
        	printf("\n");
        	break;
        case 5:
        	printf("P | Q | P <--> Q\n");
        	printf("-------------\n");
        	for (P = 1; P >= 0; P--) {
            	for (Q = 1; Q >= 0; Q--) {
                	printf("%d | %d |  %d\n", P, Q, biconditional(P, Q));
            	}
        	}
        	printf("\n");
        	break;
    	default:
    		printf("Invalid choice!\n");
    		
		}
	} while (choice != 6);

    return 0;
}

