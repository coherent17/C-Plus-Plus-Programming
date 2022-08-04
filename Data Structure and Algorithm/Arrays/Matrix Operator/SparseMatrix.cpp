#include "SparseMatrix.h"
#include <string>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(string name, int **SparseMatrix, int row, int col){
    this->name = name;
    this->row = row;
    this->col = col;
    this->capacity = row * col;
    this->terms = 0;
    
    this->smArray = new MatrixTerm[row * col];

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(SparseMatrix[i][j] != 0){
                smArray[terms].row = i;
                smArray[terms].col = j;
                smArray[terms].value = SparseMatrix[i][j];
                terms++;
            }
        }
    }
}

SparseMatrix::~SparseMatrix(){
    delete[] smArray;
}

void SparseMatrix::printSparseMatrix(){
    cout << endl << name << " : " << endl;
    cout << "\tRow : " << row <<", Col : " << col << ", Non-zero terms : " << terms << endl;
    cout << "\tsmArray:" << endl;
    
    for(int i = 0; i < terms; i++){
        cout << "\t\tsmArray[" << i << "] : " << smArray[i].row << " " << smArray[i].col << " " << smArray[i].value << endl;
    }
    cout << endl;
}