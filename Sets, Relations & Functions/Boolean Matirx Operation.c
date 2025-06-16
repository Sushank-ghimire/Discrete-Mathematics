#include <stdio.h>
#define MAX 5

void inputMatrix(int rows, int cols, int matrix[MAX][MAX], char name) {
	int i, j;
    printf("Enter %d elements of matrix %c (only 0 or 1):\n",rows * cols, name);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int rows, int cols, int matrix[MAX][MAX]) {
	int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


void joinMatrix(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
	int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = A[i][j] | B[i][j];
        }
    }
}

void booleanProduct(int r1, int c1, int c2, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
	int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++) {
                result[i][j] = result[i][j] | (A[i][k] & B[k][j]);
            }
        }
    }
}

void productMatrix(int rows, int cols, int A[MAX][MAX], int B[MAX][MAX], int result[MAX][MAX]) {
	int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = A[i][j] & B[i][j];
        }
    }
}


int main() {
    int r1, c1, r2, c2;
    int choice, matrix1[MAX][MAX], matrix2[MAX][MAX], result[MAX][MAX];
    
    do {
    	printf("\n===== Boolean Matrix Operations =====\n");
        printf("1. Join (A OR B)\n");
        printf("2. Product (A AND B)\n");
        printf("3. Boolean Product (A * B using OR-AND logic)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
        	case 1:
        	case 2:
        		printf("Enter rows and columns of matrices: ");
                scanf("%d%d", &r1, &c1);
                inputMatrix(r1, c1, matrix1, 'A');
                inputMatrix(r1, c1, matrix2, 'B');

                if (choice == 1){
                	printf("\nJoin matrix of A and B is : \n");
                    joinMatrix(r1, c1, matrix1, matrix2, result);
				} else {
                	printf("\nProduct matrix of A and B is : \n");
                    productMatrix(r1, c1, matrix1, matrix2, result);
				}

                displayMatrix(r1, c1, result);
                break;
            case 3:
            	printf("Enter rows and columns of Matrix A: ");
                scanf("%d%d", &r1, &c1);
                printf("Enter rows and columns of Matrix B: ");
                scanf("%d%d", &r2, &c2);

                if (c1 != r2) {
                    printf("Error: Matrix A's columns must match Matrix B's rows!\n");
                    break;
                }
                inputMatrix(r1, c1, matrix1, 'A');
                inputMatrix(r2, c2, matrix2, 'B');

                booleanProduct(r1, c1, c2, matrix1, matrix2, result);
                printf("\nBoolean Product of both matrix is :\n");
                displayMatrix(r1, c2, result);
                break;
        	case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
		}
	} while (choice != 4);
    
	return 0;
}
