#include "setup.h"

int main() {
    int n;
    std::cout << "Enter size of matrix: " << std::endl;
    std::cin >> n;
    std::cout << std::endl;

    double numbers[n*n];
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

    std::cout << "Alebraic addition to (2,2):" << std::endl;
    matrix A_addition = A.make_addition(2, 2);
    A_addition.checkout();

    std::cout << "Determinant = " <<  A.minor_det() << "\n" << std::endl;
    
    // std::cout << "Matrix after 1str - 3.5 * 0str:" << std::endl;
    // A.str_sub(1, 0, 3.5);
    // A.checkout();

    std::cout << "Matrix to upper trianglular matrix:" << std::endl;
    A.to_up_triangale();
}