#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int relation[MAX][MAX];
int set[MAX];
int n;

// Input set and relation matrix
void inputRelation() {
	int i, j;
    printf("Enter number of elements in the set (max %d): ", MAX);
    scanf("%d", &n);

    printf("Enter elements of the set:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter relation matrix (%dx%d):\n", n, n);
    printf("(Enter 1 if related, 0 otherwise)\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &relation[i][j]);
}

// Display matrix
void displayMatrix() {
    printf("\nRelation Matrix:\n    ");
    int i, j;
    for (i = 0; i < n; i++) printf("%d ", set[i]);
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("%d | ", set[i]);
        for (j = 0; j < n; j++) {
            printf("%d ", relation[i][j]);
        }
        printf("\n");
    }
}

// Reflexive check
int isReflexive() {
	int i;
    for (i = 0; i < n; i++) {
        if (relation[i][i] != 1)
            return 0;
    }
    return 1;
}

// Symmetric check
int isSymmetric() {
	int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (relation[i][j] != relation[j][i])
                return 0;
    return 1;
}

// Transitive check
int isTransitive() {
	int i, j, k;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < n; k++)
                if (relation[i][j] && relation[j][k] && !relation[i][k])
                    return 0;
    return 1;
}

// Check Equivalence
void checkEquivalence() {
    int r = isReflexive();
    int s = isSymmetric();
    int t = isTransitive();

    printf("\nProperties of the Relation:\n");
    printf("Reflexive: %s\n", r ? "Yes" : "No");
    printf("Symmetric: %s\n", s ? "Yes" : "No");
    printf("Transitive: %s\n", t ? "Yes" : "No");

    if (r && s && t)
        printf("=> The relation is an Equivalence Relation.\n");
    else
        printf("=> The relation is NOT an Equivalence Relation.\n");
}

// Menu
void menu() {
    printf("\n===== Relations Menu =====\n");
    printf("1. Input Set and Relation\n");
    printf("2. Display Relation Matrix\n");
    printf("3. Check Reflexive\n");
    printf("4. Check Symmetric\n");
    printf("5. Check Transitive\n");
    printf("6. Check Equivalence Relation\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                inputRelation();
                break;
            case 2:
                displayMatrix();
                break;
            case 3:
                printf("Reflexive: %s\n", isReflexive() ? "Yes" : "No");
                break;
            case 4:
                printf("Symmetric: %s\n", isSymmetric() ? "Yes" : "No");
                break;
            case 5:
                printf("Transitive: %s\n", isTransitive() ? "Yes" : "No");
                break;
            case 6:
                checkEquivalence();
                break;
            case 7:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

