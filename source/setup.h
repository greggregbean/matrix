#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include <iomanip>

class matrix {
    private:
        int size;
        long double* data;
    public:
        matrix(int n, long double* numbers);
        void checkout();
        matrix cpy();

        void str_sub(int a, int b, long double lambda);
        void switch_str(int a, int b);
        int to_up_triangale();
        void make_diag();
        long double mul_diag();
        long double gauss_det();
        
        matrix make_addition(int i, int j);
        long double minor_det();
};


#endif