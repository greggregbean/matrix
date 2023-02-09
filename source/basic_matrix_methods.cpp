#include "setup.h"

matrix::matrix(size_t n, double* numbers): size(n) {
    data = new double[n*n];
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < size; ++j) {
            data[size*i + j] = numbers[size*i + j];
        }
    }
}

void matrix::checkout() {
    for (int i = 0; i < size; ++i) {
        std::cout << "| ";
        for(int j = 0; j < size; ++j) {
            std::cout << std::setw(3u) << data[size*i + j] << std::setw(3u) << " ";
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::endl;
}

