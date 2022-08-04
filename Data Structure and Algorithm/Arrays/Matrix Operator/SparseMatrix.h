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
        SparseMatrix(string name, int **SparseMatrix, int row, int col);

        //destructor
        ~SparseMatrix();

        //method
        void printSparseMatrix();
        SparseMatrix Transpose();
        SparseMatrix Add(const SparseMatrix& x);
        SparseMatrix Mult(const SparseMatrix& x);
};