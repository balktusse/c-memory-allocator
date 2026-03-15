#include "gahook.h"
#include <stdio.h>

#define ROWS 4
#define COLS 5

void print_matrix(int **m, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int **matrix = galloc(ROWS * sizeof(int *));
    if (!matrix) {
        perror("galloc failed");
        return 1;
    }
    
    for (int i = 0; i < ROWS; i++) {
        matrix[i] = galloc(COLS * sizeof(int));
        if (!matrix[i]) {
            perror("galloc failed");
            return 1;
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = (i+1) * 10 + j;
        }
    }

    print_matrix(matrix, ROWS, COLS);

    for (int i = 0; i < ROWS; i++) {
        gfree(matrix[i]);
    }
    gfree(matrix);


    return 0;
}