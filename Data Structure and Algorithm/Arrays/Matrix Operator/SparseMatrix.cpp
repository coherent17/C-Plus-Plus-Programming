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
    cout << name << " : " << endl;
    for(int i = 0; i < row; i++){
        cout << "\t";
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

//time complexity: O(col * terms)
SparseMatrix SparseMatrix::Transpose(){
    
    SparseMatrix ret;
    ret.name = name + " Transpose";
    ret.row = col;
    ret.col = row;
    ret.terms = terms;
    ret.smArray = new MatrixTerm[terms];

    if(terms > 0){
        int current_smArrayIndex = 0;
        for(int i = 0; i < col; i++){           //O(col)
            for(int j = 0; j < terms; j++){     //O(terms)
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

SparseMatrix SparseMatrix::FastTranspose(){

    SparseMatrix ret;
    ret.name = name + " Fast Transpose";
    ret.row = col;
    ret.col = row;
    ret.terms = terms;
    ret.smArray = new MatrixTerm[terms];

    if(terms > 0){
        int *rowSize = new int[col];
        int *rowStart = new int[col];

        for(int i = 0; i < col; i++){
            rowSize[i] = 0;
        }

        for(int i = 0; i < terms; i++){
            rowSize[smArray[i].col]++;
        }

        rowStart[0] = 0;
        for(int i = 1; i < col; i++){
            rowStart[i] = rowStart[i - 1] + rowSize[i - 1];
        }

        for(int i = 0; i < terms; i++){
            int newIndex = rowStart[smArray[i].col];
            ret.smArray[newIndex].row = smArray[i].col;
            ret.smArray[newIndex].col = smArray[i].row;
            ret.smArray[newIndex].value = smArray[i].value;
            rowStart[smArray[i].col]++;
        }

        delete[] rowSize;
        delete[] rowStart;
    }

    return ret;
}