#ifndef SETUP_H
#define SETUP_H

#include <iostream>
#include <iomanip>

class matrix {
    private:
        int size;
        double* data;
    public:
        matrix(size_t n, double* numbers);
        void checkout();

        void str_sub(int a, int b, double lambda);
        void to_up_triangale();
        void make_diag();
        
        matrix make_addition(int i, int j);
        double minor_det();
};


#endif