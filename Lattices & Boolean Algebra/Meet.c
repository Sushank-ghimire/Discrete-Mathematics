#include <stdio.h>
#include <conio.h>

int meet(int a, int b) {
	return a & b;
}

void getMatixInput(int row, int column, int *matrix[][column]) {
	int i, j;
	printf("Enter %d elements (int) : ", row * column);
	for(i=0; i<row; i++) {
		for(j=0; j<column; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("\n");
}

void printMatrix(int row, int column, int matrix[][column]) {
    int i, j;
    for(i = 0; i < row; i++) {
        for(j = 0; j < column; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
	int r1, c1, i, j;
	printf("Enter the dimensions of the 1st matrix (row column) : ");
	scanf("%d%d", &r1, &c1);
	
	int matrix1[r1][c1];
	getMatixInput(r1, c1, &matrix1);
	
	int matrix2[r1][c1];
	
	printf("Enter elements for second matrix : \n");
	getMatixInput(r1, c1, &matrix2);
	
	
	int meetmatrix[r1][c1];
	
	for(i=0; i<r1; i++) {
		for(j=0; j<c1; j++) {
			meetmatrix[i][j] = meet(matrix1[i][j], matrix2[i][j]);
		}
	}
	
	printf("Meet (AND) Matrix:\n");
	printMatrix(r1, c1, meetmatrix);
	
	return 0;
}
