#include "setup.hpp"
#include "square_matrix_methods.hpp"
#include "basic_matrix_methods.hpp"

int main() {
    //--------------
    // Usual matrix
    //--------------
        // int strs;
        // std::cin >> strs;

        // int clmns;
        // std::cin >> clmns;

        // std::unique_ptr<long double[]> numbers_uptr (new long double [strs * clmns]);
        // long double* numbers_ptr = numbers_uptr.get();

        // for(int i = 0; i < strs * clmns; ++i) {
        //     std::cin >> numbers_ptr [i];
        // }

        // matrix<long double> my_matrix (strs, clmns, numbers_ptr);
        // matrix<long double> copy_m (my_matrix);
        // matrix<long double> move_m (std::move(my_matrix));

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
        // square_matrix<long double> copy_m (square);
        // square_matrix<long double> move_m (std::move(square));

        // std::cout << "Square: " << std::endl;
        // square.checkout();
        // std::cout << "Copy_m: " << std::endl;
        // copy_m.checkout();
        // std::cout << "Move_m: " << std::endl;
        // move_m.checkout();
    
    //-------------------
    // Minor determinant
    //-------------------
        // std::cout <<  square.minor_det() << std::endl;

    //------------------
    // Gauss detrminant
    //------------------
        std::cout << square.gauss_det() << std::endl;
}