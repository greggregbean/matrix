#include "setup.h"

void matrix::str_sub(int a, int b, double lambda) {
    for (int j = 0; j < size; ++j) {
        data[size*a + j] -= lambda * data[size*b + j];
    }
}

void matrix::to_up_triangale() {
    for (int i = 0; i < size; ++i) {
        for (int n = i+1; n < size; ++n) {
            double lambda = (data[n*size + i]) / (data[i*size + i]);
            std::cout << "lambda = " << lambda << std::endl; 
            this -> str_sub(n, i, lambda);
            this -> checkout();
        }
    }
}