#include <iostream>
#include <random>

using namespace std;

#define MAX_RAND 10

int **createSparseMatrix(int row, int col, int non_zero_terms){
    if(non_zero_terms > row * col){
        cerr << "Too many non-zero-terms!!!" << endl;
        return NULL;
    }

    int **ret = new int*[row];
    for(int i = 0; i < row; i++){
        ret[i] = new int[col];
    }

    //set all value to zero
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            ret[i][j] = 0;
        }
    }

    //fix the random number
    random_device rd;
    mt19937 gen(rd());
    for(int i = 0; i < non_zero_terms; i++){
        bool canBreak = false;
        while(!canBreak){
            int random_row = gen() % row;
            int random_col = gen() % col;
            int random_val = gen() % MAX_RAND;

            if(ret[random_row][random_col] == 0){
                if(random_val == 0) continue;
                ret[random_row][random_col] = random_val;
                canBreak = true;
            }
        }
    }

    return ret;
}

void printMatrix(int **matrix, int row, int col){
    if(!matrix){
        cerr << "No such matrix!!" << endl;
        return;
    }
    for(int i = 0; i < row; i++){
        cout << "\t";
        for(int j = 0; j < col; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }    
}

void freeMatrix(int **matrix, int row, int col){
    for(int i = 0; i < row; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}