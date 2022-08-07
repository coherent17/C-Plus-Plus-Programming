#include "SparseMatrix.h"
#include <string>
#include <iostream>

using namespace std;

SparseMatrix::SparseMatrix(string name, int row, int col, int terms){
    this->name = name;
    this->row = row;
    this->col = col;
    this->capacity = row * col;
    this->terms = terms;

    this->smArray = new MatrixTerm[terms];
}

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

void SparseMatrix::print_smArray(){
    cout << endl << name << " : " << endl;
    cout << "\tRow : " << row <<", Col : " << col << ", Non-zero terms : " << terms << endl;
    cout << "\tsmArray:" << endl;
    
    for(int i = 0; i < terms; i++){
        cout << "\t\tsmArray[" << i << "] : " << smArray[i].row << " " << smArray[i].col << " " << smArray[i].value << endl;
    }
    cout << endl;
}

void SparseMatrix::printSparseMatrix(){
    int **tempMatrix = new int*[row * col];
    for(int i = 0; i < row; i++){
        tempMatrix[i] = new int[col];
    }

    //init all element to zero
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            tempMatrix[i][j] = 0;
        }
    }

    //put the smArray into tempMatrix
    for(int i = 0; i < terms; i++){
        tempMatrix[smArray[i].row][smArray[i].col] = smArray[i].value;
    }

    //print out the whole matrix
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            cout << tempMatrix[i][j] << " ";
        }
        cout << endl;
    }

    //free tempMatrix
    for(int i = 0; i < row; i++){
        delete[] tempMatrix[i];
    }
    delete[] tempMatrix;         
}

SparseMatrix SparseMatrix::Transpose(){
    
    SparseMatrix ret(name.append("Transpose"), col, row, terms);
    if(terms > 0){
        int current_smArrayIndex = 0;
        for(int i = 0; i < col; i++){
            for(int j = 0; j < terms; j++){
                if(smArray[j].col == i){
                    ret.smArray[current_smArrayIndex].row = i;
                    ret.smArray[current_smArrayIndex].col = smArray[j].row;
                    ret.smArray[current_smArrayIndex].value = smArray[j].value;
                    current_smArrayIndex++;
                }
            }
        }
    }

    return ret;
}