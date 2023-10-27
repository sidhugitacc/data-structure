#include <stdio.h>
int i,j;

void readMatrix(int **matrix, int n) {
    printf("Enter the elements of the %d x %d matrix, row by row:\n", n, n);
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int **matrix, int n) {
    printf("Matrix is:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void calculateRowTotal(int **matrix, int n) {
    for(i = 0; i < n; i++) {
        int rowSum = 0;
        for(j = 0; j < n; j++) {
            rowSum += matrix[i][j];
        }
        printf("Sum of row %d: %d\n", i + 1, rowSum);
    }
}

int isIdentityMatrix(int **matrix, int n) {
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if((i == j && matrix[i][j] != 1) || (i != j && matrix[i][j] != 0)) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    int n;
    printf("Enter the order of the matrix: ");
    scanf("%d", &n);

    int *matrix[n];
    for(i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(n * sizeof(int));
    }

    readMatrix(matrix, n);
    displayMatrix(matrix, n);
    calculateRowTotal(matrix, n);

    if(isIdentityMatrix(matrix, n)) {
        printf("The matrix is an identity matrix.\n");
    } else {
        printf("The matrix is not an identity matrix.\n");
    }

    for(i = 0; i < n; i++) {
        free(matrix[i]);
    }

    return 0;
}
