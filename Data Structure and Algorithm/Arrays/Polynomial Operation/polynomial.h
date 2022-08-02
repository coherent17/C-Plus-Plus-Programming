#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


class Term{
    //let Polynomial class can share the resource of Term class
    friend Polynomial;

    private:
        float coef;
        int exp;
};


class Polynomial{
    public:
        //constructor
        Polynomial() = default;

        //destructor
        ~Polynomial() = default;

        //method
        Polynomial Add(Polynomial poly);
        Polynomial Mult(Polynomial poly);

    private:
        Term *termArray;
        int capacity;
        int terms;
};

#endif