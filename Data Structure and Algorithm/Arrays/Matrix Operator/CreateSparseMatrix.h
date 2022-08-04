#include <iostream>
#include <cstdlib>
#include <ctime>

#define MAX_RAND 10

int **createSparseMatrix(int row, int col, int non_zero_terms);
void printMatrix(int **matrix, int row, int col); 
void freeMatrix(int **matrix, int row, int col);