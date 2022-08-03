#include <string>

using namespace std;

struct term{
    int coef;
    int exp;
};

class Polynomial{

    private:
    term *termArray;
    int capacity;   //sizeof termArray
    int terms;      //number of non-zero term
    string description;
        
    public:
        //constructor
        Polynomial(string description);

        //destructor
        ~Polynomial();

        //setter
        void SetPolynomial(int termCounts, int *coef_array, int *exp_array);

        //method
        void NewTerm(int coef, int exp);
        int eval(int x_value);
        int get_coef(int exp);                              //return the coeffient at specific exponent
        void add(Polynomial& x, Polynomial &result);        //result = *this + x
        void minus(Polynomial& x, Polynomial &result);      //result = *this - x
        void mult(Polynomial& x, Polynomial &result);       //result = *this * x  
        bool diff(Polynomial& x);
        void printPolynomial();

};