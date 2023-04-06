#include "setup.hpp"
#include "square_matrix_methods.hpp"
#include "basic_matrix_methods.hpp"

int main() {
    
    //---------------
    // Square Matrix 
    //---------------
        int size;
        std::cout << "Enter size:" << std::endl;
        std::cin >> size;
        std::cout << std::endl;

        long double* numbers = new long double [size * size];

        std::cout << "Enter data of matrix:" << std::endl;
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                std::cin >> numbers [size*i + j];
            }
        }
        std::cout << std::endl;

        std::cout << "Square matrix:" << std::endl;
        square_matrix<long double> square (size, numbers);
        square.checkout();
        delete numbers;
    


    //-------------------
    // Minor determinant
    //-------------------
        std::cout << "Minor determinant = " <<  square.minor_det() << "\n" << std::endl;

    
    //------------------
    // Gauss detrminant
    //------------------
        long double res_of_gauss_det = square.gauss_det();
        std::cout << "Gauss determinant = " << res_of_gauss_det << "\n" << std::endl;
}