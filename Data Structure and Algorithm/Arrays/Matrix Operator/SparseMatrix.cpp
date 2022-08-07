#include "SparseMatrix.h"
#include <string>
#include <iostream>
#include <iomanip>

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
    if(smArray == NULL){
        cerr << "Matrix Not Found!" << endl;
        return;
    }
    cout << endl << name << " : " << endl;
    cout << "\tRow : " << row <<", Col : " << col << ", Non-zero terms : " << terms << endl;
    cout << "\tsmArray:" << endl;
    
    for(int i = 0; i < terms; i++){
        cout << "\t\tsmArray[" << setw(2) << i << "] : " << setw(2) << smArray[i].row << " " << setw(2) << smArray[i].col << " " << setw(2) << smArray[i].value << endl;
    }
    cout << endl << endl;
}

void SparseMatrix::printSparseMatrix(){
    if(smArray == NULL){
        cerr << "Matrix Not Found!" << endl;
        return;
    }

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
            cout << setw(3) << tempMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    //free tempMatrix
    for(int i = 0; i < row; i++){
        delete[] tempMatrix[i];
    }
    delete[] tempMatrix;         
}

//time complexity: O(col * terms)
SparseMatrix SparseMatrix::Transpose(){
    
    SparseMatrix ret;
    ret.name = name + "T";
    ret.row = col;
    ret.col = row;
    ret.terms = terms;
    ret.smArray = new MatrixTerm[row * col];

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

//time complexity: O(col + terms)
SparseMatrix SparseMatrix::FastTranspose(){

    SparseMatrix ret;
    ret.name = name + "FT";
    ret.row = col;
    ret.col = row;
    ret.terms = terms;
    ret.smArray = new MatrixTerm[row * col];

    if(terms > 0){

        int *rowSize = new int[col];        //number of nonzero terms in ith row of A^T
        int *rowStart = new int[col];       //location of nonzero term in ith row of A^T

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


SparseMatrix SparseMatrix::Add(const SparseMatrix& x){

    SparseMatrix ret;
    ret.name = name + "_Add_" + x.name;
    ret.row = row;
    ret.col = col;
    ret.terms = 0;
    ret.smArray = new MatrixTerm[row * col];

    //check for the dimension of two matrixs
    if(row != x.row || col != x.col){
        cerr << "SparseMatrix::Add() Dimension Error!" << endl;
        cerr << "Adding " << name << " & " << x.name << " error!" << endl;
        ret.row = 0;
        ret.col = 0;
        ret.terms = 0;
        delete[] ret.smArray;
        ret.smArray = NULL;
        return ret;
    }



    int thisIndex = 0;
    int xIndex = 0;

    while(thisIndex < terms && xIndex < x.terms){
        int x_row = x.smArray[xIndex].row;
        int x_col = x.smArray[xIndex].col;
        int this_row = smArray[thisIndex].row;
        int this_col = smArray[thisIndex].col;
        //this row and col is smaller
        if((x_row > this_row) || (x_row == this_row && x_col > this_col)){
            ret.smArray[ret.terms].row = smArray[thisIndex].row;
            ret.smArray[ret.terms].col = smArray[thisIndex].col;
            ret.smArray[ret.terms].value = smArray[thisIndex].value;
            ret.terms++;
            thisIndex++;
        }

        //x's row and col is smaller
        else if((x_row < this_row) || (x_row == this_row && x_col < this_col)){
            ret.smArray[ret.terms].row = x.smArray[xIndex].row;
            ret.smArray[ret.terms].col = x.smArray[xIndex].col;
            ret.smArray[ret.terms].value = x.smArray[xIndex].value;
            ret.terms++;
            xIndex++;            
        }

        //same row and col
        else{
            int add_result = smArray[thisIndex].value + x.smArray[xIndex].value;
            if(add_result != 0){
                ret.smArray[ret.terms].row = x.smArray[xIndex].row;
                ret.smArray[ret.terms].col = x.smArray[xIndex].col;
                ret.smArray[ret.terms].value = add_result;
                ret.terms++;
                thisIndex++;
                xIndex++;                
            }
        }
    }

    //insert the remaining elements
    while(thisIndex < terms){
        ret.smArray[ret.terms].row = smArray[thisIndex].row;
        ret.smArray[ret.terms].col = smArray[thisIndex].col;
        ret.smArray[ret.terms].value = smArray[thisIndex].value;
        ret.terms++;
        thisIndex++;        
    }

    while(xIndex < x.terms){
        ret.smArray[ret.terms].row = x.smArray[xIndex].row;
        ret.smArray[ret.terms].col = x.smArray[xIndex].col;
        ret.smArray[ret.terms].value = x.smArray[xIndex].value;
        ret.terms++;
        xIndex++;            
    }

    return ret;
}


SparseMatrix SparseMatrix::Minus(const SparseMatrix& x){

    SparseMatrix ret;
    ret.name = name + "_Minus_" + x.name;
    ret.row = row;
    ret.col = col;
    ret.terms = 0;
    ret.smArray = new MatrixTerm[row * col];

    //check for the dimension of two matrixs
    if(row != x.row || col != x.col){
        cerr << "SparseMatrix::Minus() Dimension Error!" << endl;
        cerr << "Minusing " << name << " & " << x.name << " error!" << endl;
        ret.row = 0;
        ret.col = 0;
        ret.terms = 0;
        delete[] ret.smArray;
        ret.smArray = NULL;
        return ret;
    }



    int thisIndex = 0;
    int xIndex = 0;

    while(thisIndex < terms && xIndex < x.terms){
        int x_row = x.smArray[xIndex].row;
        int x_col = x.smArray[xIndex].col;
        int this_row = smArray[thisIndex].row;
        int this_col = smArray[thisIndex].col;
        //this row and col is smaller
        if((x_row > this_row) || (x_row == this_row && x_col > this_col)){
            ret.smArray[ret.terms].row = smArray[thisIndex].row;
            ret.smArray[ret.terms].col = smArray[thisIndex].col;
            ret.smArray[ret.terms].value = smArray[thisIndex].value;
            ret.terms++;
            thisIndex++;
        }

        //x's row and col is smaller
        else if((x_row < this_row) || (x_row == this_row && x_col < this_col)){
            ret.smArray[ret.terms].row = x.smArray[xIndex].row;
            ret.smArray[ret.terms].col = x.smArray[xIndex].col;
            ret.smArray[ret.terms].value = -1 * x.smArray[xIndex].value;
            ret.terms++;
            xIndex++;            
        }

        //same row and col
        else{
            int minus_result = smArray[thisIndex].value - x.smArray[xIndex].value;
            if(minus_result != 0){
                ret.smArray[ret.terms].row = x.smArray[xIndex].row;
                ret.smArray[ret.terms].col = x.smArray[xIndex].col;
                ret.smArray[ret.terms].value = minus_result;
                ret.terms++;               
            }
            thisIndex++;
            xIndex++; 

        }
    }

    //insert the remaining elements
    while(thisIndex < terms){
        ret.smArray[ret.terms].row = smArray[thisIndex].row;
        ret.smArray[ret.terms].col = smArray[thisIndex].col;
        ret.smArray[ret.terms].value = smArray[thisIndex].value;
        ret.terms++;
        thisIndex++;        
    }

    while(xIndex < x.terms){
        ret.smArray[ret.terms].row = x.smArray[xIndex].row;
        ret.smArray[ret.terms].col = x.smArray[xIndex].col;
        ret.smArray[ret.terms].value = -1 * x.smArray[xIndex].value;
        ret.terms++;
        xIndex++;            
    }

    return ret;
}