#include "CreateSparseMatrix.h"
#include "SparseMatrix.h"
#include <iostream>

using namespace std;


int main(){

    srand(time(NULL));

    int row1 = 5;
    int col1 = 4;
    int non_zero_term1 = rand()%(row1 * col1 / 2);      //make sure that the non-zero term will not exceed 50%
    int **m1 = createSparseMatrix(row1, col1, non_zero_term1);
    
    cout << "original random matrix: " << endl;
    printMatrix(m1, row1, col1);
    SparseMatrix Sm1("Sm1", m1, row1, col1);
    Sm1.print_smArray();
    Sm1.printSparseMatrix();

    //test transpose:
    SparseMatrix Sm1T = Sm1.Transpose();
    Sm1T.print_smArray();
    Sm1T.printSparseMatrix();



    //test fase transpose:
    SparseMatrix Sm1FT = Sm1.FastTranspose();
    Sm1FT.print_smArray();
    Sm1FT.printSparseMatrix();

    freeMatrix(m1, row1, col1);
    return 0;
}