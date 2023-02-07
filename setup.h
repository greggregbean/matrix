#ifndef SETUP_H
#define SETUP_H

#include <iostream>

class matrix {
    private:
        size_t size;
        double* data;
    public:
        matrix(size_t n, double* numbers);
        void checkout();
        matrix make_addition(int i, int k);
        //void determinant();
};


#endif