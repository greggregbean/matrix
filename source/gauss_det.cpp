#include "setup.h"

void matrix::str_sub(int a, int b, long double lambda) {
    for (int j = 0; j < size; ++j) {
        data[a*size + j] -= lambda * data[b*size + j];
    }
}

void matrix::switch_str(int a, int b) {
    long double tmp;
    for (int j = 0; j < size; ++j) {
        tmp = data[a*size + j];
        data[a*size + j] = data[b*size + j];
        data[b*size + j] = tmp;
    }
}


int matrix::to_up_triangale() {
    int count_switch = 0;

    for (int i = 0; i < size; ++i) {
        if (data[i*size + i ] == 0) {
            int n;
            for (n = i+1; n < size; ++n) {
                if (data[n*size + i] != 0) break;
            }
            if (n == size) continue;
            else {
                switch_str(n, i);
                ++count_switch;
            }
        }

        for (int n = i+1; n < size; ++n) {
            if (data[n*size + i] == 0) continue;
            long double lambda = (data[n*size + i]) / (data[i*size + i]);
            std::cout << "lambda = " << lambda << std::endl; 
            this -> str_sub(n, i, lambda);
            this -> checkout();
        }
    }

    return count_switch;
}

long double matrix::mul_diag() {
    long double res = 1;
    for (int i = 0; i < size; ++i) {
        if (data[i*size + i] == 0) return 0;
        res *= data[i*size + i];
    }
    return res;
}

long double matrix::gauss_det() {
    matrix cpy = this -> cpy();

    long double det;
    if ((cpy.to_up_triangale() % 2) == 0) det = 1;
    else det = -1;

    det *= cpy.mul_diag();
    
    return det;
}