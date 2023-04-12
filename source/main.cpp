#include "setup.hpp"
#include "square_matrix_methods.hpp"
#include "basic_matrix_methods.hpp"

int main() {
    
    //---------------
    // Square Matrix 
    //---------------
        int size;
        std::cin >> size;

        std::unique_ptr<long double[]> numbers_uptr (new long double [size * size]);

        long double* numbers_ptr = numbers_uptr.get();

        for(int i = 0; i < size * size; ++i) {
            std::cin >> numbers_ptr [i];
        }

        square_matrix<long double> square (size, numbers_ptr);
    
    //-------------------
    // Minor determinant
    //-------------------
        // std::cout <<  square.minor_det() << std::endl;

    //------------------
    // Gauss detrminant
    //------------------
        std::cout << square.gauss_det() << std::endl;
}