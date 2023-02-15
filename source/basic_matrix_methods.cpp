#include "setup.h"

matrix::matrix(int n, long double* numbers): size(n) {
    data = new long double[n*n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < size; ++j) {
            data[i*size + j] = numbers[i*size + j];
        }
    }
}

void matrix::checkout() {
    for (int i = 0; i < size; ++i) {
        std::cout << "| ";
        for(int j = 0; j < size; ++j) {
            std::cout << std::setw(3u) << data[i*size + j] << std::setw(3u) << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl;
}

matrix matrix::cpy() {
    matrix cpy(size, data);
    return cpy;
}

