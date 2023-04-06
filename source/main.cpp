#include "setup.hpp"
#include "square_matrix_methods.hpp"
#include "basic_matrix_methods.hpp"

int main() {
    //----------
    // Matrix A
    //----------
        // int strs;
        // std::cout << "Enter number of strings:" << std::endl;
        // std::cin >> strs;
        // std::cout << std::endl;

        // int clmns;
        // std::cout << "Enter number of columns:" << std::endl;
        // std::cin >> clmns;
        // std::cout << std::endl;

        // long double* numbers_A = new long double [strs * clmns];

        // std::cout << "Enter data of matrix:" << std::endl;
        // for(int i = 0; i < strs; ++i) {
        //     for(int j = 0; j < clmns; ++j) {
        //         std::cin >> numbers_A [clmns*i + j];
        //     }
        // }
        // std::cout << std::endl;


        // std::cout << "Matrix:" << std::endl;
        // matrix<long double> A (strs, clmns, numbers_A);
        // A.checkout();
        // delete numbers_A;
    
    //----------
    // Matrix B
    //----------
        // std::cout << "Enter number of strings:" << std::endl;
        // std::cin >> strs;
        // std::cout << std::endl;

        // std::cout << "Enter number of columns:" << std::endl;
        // std::cin >> clmns;
        // std::cout << std::endl;

        // long double* numbers_B = new long double [strs * clmns];

        // std::cout << "Enter data of matrix:" << std::endl;
        // for(int i = 0; i < strs; ++i) {
        //     for(int j = 0; j < clmns; ++j) {
        //         std::cin >> numbers_B [clmns*i + j];
        //     }
        // }
        // std::cout << std::endl;

        // std::cout << "Matrix:" << std::endl;
        // matrix<long double> B (strs, clmns, numbers_B);
        // B.checkout();
        // delete numbers_B;
    
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
    
    //-----------------------
    // Another square matrix
    //-----------------------
        std::cout << "Enter size:" << std::endl;
        std::cin >> size;
        std::cout << std::endl;

        long double* another_numbers = new long double [size * size];

        std::cout << "Enter data of matrix:" << std::endl;
        for(int i = 0; i < size; ++i) {
            for(int j = 0; j < size; ++j) {
                std::cin >> another_numbers [size*i + j];
            }
        }
        std::cout << std::endl;

        std::cout << "Square matrix:" << std::endl;
        square_matrix<long double> another_square (size, another_numbers);
        another_square.checkout();
        delete another_numbers;

    //--------------
    // Matrix equal
    //--------------
        // std::cout << "Operator=:" << std::endl;
        // another_square = square;
        // another_square.checkout();

    //-----------------
    // Matrix transpose
    //-----------------
        // std::cout << "Matrix transpose:" << std::endl;
        // matrix<long double> A_transp = A.transpose();
        // A_transp.checkout();

    //-----------------------------
    // Unary matrix multiplication
    //-----------------------------
        // std::cout << "Unary matrix multiplication:" << std::endl;
        // square *= another_square;
        // square.checkout();
    
    //------------------------------
    // Binary matrix multiplication
    //------------------------------
        // std::cout << "Matrix multiplication:" << std::endl;
        // matrix<long double> C = square * another_square;
        // C.checkout();
    
    //----------------------------------------
    // Binary multiplication matrix by number
    //----------------------------------------
        // std::cout << "Binary multiplication matrix by 2.2:" << std::endl;
        // matrix<long double> C = 2.2 * square;
        // C.checkout(); 

    //---------------------------------------
    // Unary multiplication matrix by number
    //---------------------------------------
        // std::cout << "Multiplication matrix by 2.2:" << std::endl;
        // square *= 2.2;
        // square.checkout();

    //-----------------
    // Matrix addition
    //-----------------
        // std::cout << "Matrix addition:" << std::endl;
        // square_matrix<long double> C = square + another_square;
        // C.checkout();
        // std::cout << C.gauss_det() << std::endl;

    //----------
    // Neg_copy
    //----------
        // std::cout << "Negative copy" << std::endl;
        // square_matrix<long double> neg_square = -square;
        // neg_square.checkout();

    //--------------------
    // Matrix subtraction
    //--------------------
        // std::cout << "Matrix subtraction" << std::endl;
        // matrix F = A - B;
        // F.checkout();

    //-------------
    // Matrix copy
    //-------------
        // std::cout << "Matrix copy:" << std::endl;
        // square_matrix A_cpy = A;
        // A_cpy.checkout();

    //--------------------
    // Algebraic addition
    //--------------------
        // std::cout << "Alebraic addition to (2,2):" << std::endl;
        // square_matrix A_addition = A.make_addition(2, 2);
        // A_addition.checkout();

    //-------------------
    // Minor determinant
    //-------------------
        // std::cout << "Minor determinant = " <<  square.minor_det() << "\n" << std::endl;

    //----------------
    // Switch strings
    //----------------
        // std::cout << "Switch strings (0),(2): " << std::endl;
        // A.switch_str(0, 2);
        // A.checkout();
    
    //--------------------
    // Srting subtraction
    //--------------------
        // std::cout << "Matrix after 1str - 3.5 * 0str:" << std::endl;
        // A.str_sub(1, 0, 3.5);
        // A.checkout();
    
    //------------------
    // Gauss detrminant
    //------------------
        // long double res_of_gauss_det = square.gauss_det();
        // std::cout << "Gauss determinant = " << res_of_gauss_det << "\n" << std::endl;
        // std::cout << "Matrix one more time:" << std::endl;
        // square.checkout();
}