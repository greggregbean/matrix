#include "setup.h"

void matrix::str_sub(int a, int b, double lambda) {
    for (int j = 0; j < size; ++j) {
        data[a*size + j] -= lambda * data[b*size + j];
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

double matrix::gauss_det() {
    double det = 1;
    for (int i = 0; i < size; ++i) {
        if(data[i*size + i] == 0) return 0;
        det *= data[i*size + i];
    }
    return det;
}