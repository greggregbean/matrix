#include "setup.h"

int main() {
    int n;
    std::cout << "Enter size of matrix: " << std::endl;
    std::cin >> n;
    std::cout << std::endl;

    long double numbers[n*n];
    std::cout << "Enter data of matrix: " << std::endl;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            std::cin >> numbers[n*i + j];
        }
    }
    std::cout << std::endl;

    std::cout << "Matrix:" << std::endl;
    matrix A (n, numbers);
    A.checkout();

    // std::cout << "Matrix copy:" << std::endl;
    // matrix A_cpy = A.cpy();
    // A_cpy.checkout();

    // std::cout << "Alebraic addition to (2,2):" << std::endl;
    // matrix A_addition = A.make_addition(2, 2);
    // A_addition.checkout();

    std::cout << "Minor determinant = " <<  A.minor_det() << "\n" << std::endl;

    // std::cout << "Switch strings (0),(2): " << std::endl;
    // A.switch_str(0, 2);
    // A.checkout();
    
    // std::cout << "Matrix after 1str - 3.5 * 0str:" << std::endl;
    // A.str_sub(1, 0, 3.5);
    // A.checkout();

    long double res_of_gauss_det = A.gauss_det();
    std::cout << "Gauss determinant = " << res_of_gauss_det << "\n" << std::endl;

    // std::cout << "Matrix one more time:" << std::endl;
    // A.checkout();
}