#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include <iomanip>

class matrix {
    private:
        int size;
        double* data;
    public:
        matrix(int n, double* numbers);
        void checkout();

        void str_sub(int a, int b, double lambda);
        void to_up_triangale();
        void make_diag();
        double gauss_det();
        
        matrix make_addition(int i, int j);
        double minor_det();
};


#endif