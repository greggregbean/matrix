#include "setup.hpp"
#include "square_matrix_methods.hpp"
#include "basic_matrix_methods.hpp"

int main() {
    
    //---------------
    // Square Matrix 
    //---------------
        int size;
        std::cin >> size;

        long double* numbers = new long double [size * size];

        for(int i = 0; i < size * size; ++i) {
            std::cin >> numbers [i];
        }

        square_matrix<long double> square (size, numbers);
        delete numbers;
    
    //-------------------
    // Minor determinant
    //-------------------
        // std::cout <<  square.minor_det() << std::endl;

    //------------------
    // Gauss detrminant
    //------------------
        std::cout << square.gauss_det() << std::endl;
}