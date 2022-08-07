#include "CreateSparseMatrix.h"
#include "SparseMatrix.h"
#include <iostream>
#include <random>

using namespace std;


int main(){

    random_device rd;
    mt19937 gen(rd());

    //generate random sparse matrix

    //m1
    int row1 = 5;
    int col1 = 4;
    int non_zero_term1 = gen()%(row1 * col1 / 2);      //make sure that the non-zero term will not exceed 50%
    int **m1 = createSparseMatrix(row1, col1, non_zero_term1);

    //m2
    int row2 = 5;
    int col2 = 4;
    int non_zero_term2 = gen()%(row2 * col2 / 2);
    int **m2 = createSparseMatrix(row2, col2, non_zero_term2);

    
    SparseMatrix Sm1("Sm1", m1, row1, col1);
    //Sm1.print_smArray();
    Sm1.printSparseMatrix();

    SparseMatrix Sm2("Sm2", m2, row2, col2);
    //Sm2.print_smArray();
    Sm2.printSparseMatrix();



    //test transpose:
    SparseMatrix Sm1T = Sm1.Transpose();
    //Sm1T.print_smArray();
    Sm1T.printSparseMatrix();

    SparseMatrix Sm2T = Sm2.Transpose();
    //Sm2T.print_smArray();
    Sm2T.printSparseMatrix();    




    //test fast transpose:
    SparseMatrix Sm1FT = Sm1.FastTranspose();
    //Sm1FT.print_smArray();
    Sm1FT.printSparseMatrix();

    SparseMatrix Sm2FT = Sm2.FastTranspose();
    //Sm2FT.print_smArray();
    Sm2FT.printSparseMatrix();



    //test add
    SparseMatrix Sm1_Add_Sm2 = Sm1.Add(Sm2);
    Sm1_Add_Sm2.printSparseMatrix();

    SparseMatrix Sm1T_Add_Sm2T = Sm1T.Add(Sm2T);
    Sm1T_Add_Sm2T.printSparseMatrix();

    SparseMatrix Sm1FT_Add_Sm2T = Sm1FT.Add(Sm2T);
    Sm1FT_Add_Sm2T.printSparseMatrix();

    SparseMatrix Sm1_Add_Sm2T = Sm1.Add(Sm2T);
    Sm1_Add_Sm2T.printSparseMatrix();


    //test minus
    SparseMatrix Sm1_Minus_Sm2 = Sm1.Minus(Sm2);
    Sm1_Minus_Sm2.printSparseMatrix();

    SparseMatrix Sm1T_Minus_Sm2T = Sm1T.Minus(Sm2T);
    Sm1T_Minus_Sm2T.printSparseMatrix();

    SparseMatrix Sm1FT_Minus_Sm2T = Sm1FT.Minus(Sm2T);
    Sm1FT_Minus_Sm2T.printSparseMatrix();

    SparseMatrix Sm1_Minus_Sm2T = Sm1.Minus(Sm2T);
    Sm1_Minus_Sm2T.printSparseMatrix();


    freeMatrix(m1, row1, col1);
    freeMatrix(m2, row2, col2);
    return 0;
}