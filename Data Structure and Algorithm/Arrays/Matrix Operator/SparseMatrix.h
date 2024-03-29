#include <string>

using namespace std;

struct MatrixTerm{
    int row;
    int col;
    int value;
};

class SparseMatrix{
    private:
        string name;
        int row;
        int col;
        int terms;
        int capacity;

        //use an array of triple <row, col, value> to store non-zero term
        MatrixTerm *smArray;
    

    public:
        //constructor
        SparseMatrix() = default;
        SparseMatrix(string name, int row, int col, int terms);
        SparseMatrix(string name, int **SparseMatrix, int row, int col);

        //destructor
        ~SparseMatrix();

        //method
        void print_smArray();                       //print triple <row, col, value> in smArray
        void printSparseMatrix();                   //print the whole sparse matrix
        SparseMatrix Transpose();                   //return the transpose of (*this) matrix
        SparseMatrix FastTranspose();               //return the fast transpose of (*this) matrix
        SparseMatrix Add(SparseMatrix& x);    //return *this matrix + x
        SparseMatrix Minus(SparseMatrix& x);  //return *this matrix - x
        SparseMatrix Mult(SparseMatrix& x);
};