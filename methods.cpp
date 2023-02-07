#include "setup.h"

matrix::matrix(size_t n, double* numbers): size(n) {
    data = new double[n*n];
    for(size_t i = 0; i < n; ++i) {
        for(int k = 0; k < size; ++k) {
            data[size*i + k] = numbers[size*i + k];
        }
    }
}

void matrix::checkout() {
    for (int i = 0; i < size; ++i) {
        std::cout << "| ";
        for(int k = 0; k < size; ++k) {
            std::cout << data[size*i + k] << " ";
        }
        std::cout << "|" << std::endl;
    }
}

matrix matrix::make_addition(int i, int k) {
    double numbers[(size-1)*(size-1)];
    int pos = 0;

    for (int n = 0; n < size; ++n) {
        if (n == i) continue;
        else {
            for(int m = 0; m < size; ++m) {
                if(m == k) continue;
                else {
                    numbers[pos] = data[n*size + m];
                    ++pos;
                }
            }
        }
    }
    matrix addition (size-1, numbers);
    return addition;
}

double matrix::determinant() {
    if (size == 1) return (data[0]);

    matrix addition = make_addition(0, 0); 
    double result = 0;
    int sign = 1;

    for(int k = 0; k < size; ++k) {
        result += (sign)*(data[k])*(addition.determinant());
        sign *= (-1);
        if((k+1) != size) {
            addition = make_addition(0, k+1);
        }
    }

    return result;
}