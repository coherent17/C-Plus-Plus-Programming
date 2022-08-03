#include <string>

using namespace std;

struct term{
    float coef;
    int exp;
};


class Polynomial{

    private:
    term *termArray;
    int capacity;   //sizeof termArray
    int terms;      //number of non-zero term

    public:
        //constructor
        Polynomial();

        //destructor
        ~Polynomial();

        //setter
        void SetPolynomial(int termCounts, float *coef_array, int *exp_array);

        //method
        void add(Polynomial& x, Polynomial &result)const;       //return *this + x
        Polynomial mult(Polynomial& x)const;      //return *this * x
        void printPolynomial();

    private:
        void NewTerm(float coef, int exp);

};