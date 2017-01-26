#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* matrix_gen
 *
 * Generates a matrix of natural numbers (inc. zero) in left to right,
 * top to bottom order, in a rows X cols size matrix.
 *
 * const int rows   : The number of rows for this matrix
 * const int cols   : The number of cols for this matrix
 */
int **matrix_gen(const int rows, const int cols) {
    int **m = malloc(sizeof(int *) * rows);
    
    int i, j;
    int count = 0;
    for(i = 0; i < rows; i++) {
        m[i]= malloc(sizeof(int) * cols);
        for(j = 0; j < cols; j++) {
            m[i][j] = count++;
        }
    }

    return m;
}

/* set_row
 *
 * Sets all the entries in row `row` to value `set_val` in a matrix `m`
 *
 * int **m          : A 2D matrix of integers
 * const int row    : The row to set all entries of to set_val
 * const int cols   : The number of cols of matrix m
 * const int set_val: The value to set all entries in row `row` to
 */
void set_row(int **m, const int row, const int cols, const int set_val) {
    int i;
    for(i = 0; i < cols; i++) {
        m[row][i] = set_val;
    }
}

/* set_col
 *
 * Sets all the entries in column `col` to value `set_val` in a matrix `m`
 *
 * int **m          : A 2D matrix of integers
 * const int col    : The column to set all entries of to set_val
 * const int rows   : The number of rows of matrix m
 * const int set_val: The value to set all entries in column `col` to
 */
void set_col(int **m, const int col, const int rows, const int set_val) {
    int i;
    for(i = 0; i < rows; i++) {
        m[i][col] = set_val;
    }
}

/* matrix_zero
 *
 * Zeroes out any rows or columns of a matrix where at least one element
 * is already a zero
 *
 * int **m          : A 2D matrix of integers
 * const int rows   : the number of rows in the matrix
 * const int cols   : the number of cols in the matrix
 */
int **matrix_zero(int **m, const int rows, const int cols) {
    bool zero_rows[rows];
    bool zero_cols[cols];

    memset(zero_rows, 0, sizeof(zero_rows));
    memset(zero_cols, 0, sizeof(zero_cols));

    int i, j;
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            if(m[i][j] == 0) {
                zero_rows[i] = true;
                zero_cols[j] = true;
            }
        }
    }

    int **m_new = matrix_gen(rows, cols);
    
    for(i = 0; i < rows; i++) {
        if(zero_rows[i]) {
            set_row(m_new, i, cols, 0);
        }
    }

    for(j = 0; j < cols; j++) {
        if(zero_cols[j]) {
            set_col(m_new, j, rows, 0);
        }
    }

    return m_new;
}

/* print_matrix
 *
 * Prints a pretty-ish output of a 2D matrix of integers
 *
 * int **m          : a 2D matrix of integers
 * const int rows   : number of rows in the matrix
 * const int cols   : number of columns in the matrix
 */
void print_matrix(int **m, const int rows, const int cols) {
    int i, j;
    for(i = 0; i < rows; i++) {
        printf("(");
        for(j = 0; j < cols; j++) {
            printf(" %2d ", m[i][j]); 
        }
        printf(")\n");
    }
}

int main(int argc, char *argv[]) {
    int **my_mat = matrix_gen(4, 4);
    my_mat[3][3] = 0;
    print_matrix(my_mat, 4, 4);

    int **m2 = matrix_zero(my_mat, 4, 4);
    print_matrix(m2, 4, 4);

    return 0;
}
