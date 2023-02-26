#include "setup.h"

int main() {
    //----------
    // Matrix A
    //----------
        int strs;
        std::cout << "Enter number of strings:" << std::endl;
        std::cin >> strs;
        std::cout << std::endl;

        int clmns;
        std::cout << "Enter number of columns:" << std::endl;
        std::cin >> clmns;
        std::cout << std::endl;

        long double numbers_A [strs * clmns];

        std::cout << "Enter data of matrix:" << std::endl;
        for(int i = 0; i < strs; ++i) {
            for(int j = 0; j < clmns; ++j) {
                std::cin >> numbers_A [clmns*i + j];
            }
        }
        std::cout << std::endl;


        std::cout << "Matrix:" << std::endl;
        square_matrix A (strs, clmns, numbers_A);
        A.checkout();
    
    //----------
    // Matrix B
    //----------
        std::cout << "Enter number of strings:" << std::endl;
        std::cin >> strs;
        std::cout << std::endl;

        std::cout << "Enter number of columns:" << std::endl;
        std::cin >> clmns;
        std::cout << std::endl;

        long double numbers_B [strs * clmns];

        std::cout << "Enter data of matrix:" << std::endl;
        for(int i = 0; i < strs; ++i) {
            for(int j = 0; j < clmns; ++j) {
                std::cin >> numbers_B [clmns*i + j];
            }
        }
        std::cout << std::endl;

        std::cout << "Matrix:" << std::endl;
        square_matrix B (strs, clmns, numbers_B);
        B.checkout();

    //-----------------
    // Matrix addition
    //-----------------
        // std::cout << "Matrix addition:" << std::endl;
        // matrix C = A + B;
        // C.checkout();

    //----------
    // Neg_copy
    //----------
        std::cout << "Negative copy" << std::endl;
        matrix neg_A = -A;
        neg_A.checkout();

    //--------------------
    // Matrix subtraction
    //--------------------
        std::cout << "Matrix subtraction" << std::endl;
        matrix F = A - B;
        F.checkout();

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
        // std::cout << "Minor determinant = " <<  A.minor_det() << "\n" << std::endl;

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
        // long double res_of_gauss_det = A.gauss_det();
        // std::cout << "Gauss determinant = " << res_of_gauss_det << "\n" << std::endl;
        // std::cout << "Matrix one more time:" << std::endl;
        // A.checkout();
}